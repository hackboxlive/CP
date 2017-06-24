#include <bits/stdc++.h>
using namespace std;
struct node	{
	long long int beg;
	long long int tot;
	long long int lazy;
}tree[600600];
void build_tree(int id,int l,int r)	{
	if(l==r)	{
		tree[id].beg=0;
		tree[id].tot=0;
		tree[id].lazy=0;
		return;
	}
	build_tree(2*id,l,(l+r)/2);
	build_tree(2*id+1,(l+r)/2+1,r);
	tree[id].beg=0;
	tree[id].tot=0;
	tree[id].lazy=0;
	return;
}
void update_lazy(int id,int l,int r)	{
	if(tree[id].lazy>0)	{
	cout<<"Evaluating for "<<id<<endl;
		cout<<"Before: "<<tree[id].tot<<endl;
		tree[id].tot+=(long long int)((2*(tree[id].beg+1)+(r-l)*(tree[id].lazy))*(r-l+1))/2;
		cout<<"After: "<<tree[id].tot<<endl;
		if(r!=l)	{
			tree[2*id].beg+=tree[id].beg;
			tree[2*id].lazy+=tree[id].lazy;
			tree[2*id+1].beg+=(long long int)tree[id].beg+((r+l)/2+1-l);
			tree[2*id+1].lazy+=tree[id].lazy;
		}
		tree[id].beg=0;
		tree[id].lazy=0;
		for(int i=1;i<=14;i++)	{
			printf("%d %lld %lld %lld\n",i,tree[i].tot,tree[i].beg,tree[i].lazy);
		}
		cout<<endl;
	}
	return;
}
void update_tree(int id,int start,int end,int l,int r)	{
	update_lazy(id,start,end);
	if(start>r || end<l)	{
		return;
	}
	if(start>=l && end<=r)	{
		tree[id].beg+=start-l;
		tree[id].lazy++;
		update_lazy(id,start,end);
		return;
	}
	update_tree(2*id,start,(start+end)/2,l,r);
	update_tree(2*id+1,(start+end)/2+1,end,l,r);
	tree[id].tot=tree[2*id].tot+tree[2*id+1].tot;
	return;
}
long long int query_tree(int id,int start,int end,int l,int r)	{
	update_lazy(id,start,end);
	if(start>r || end<l)	{
		return 0;
	}
	if(start>=l && end<=r)	{
		return tree[id].tot;
	}
	return query_tree(2*id,start,(start+end)/2,l,r)+query_tree(2*id+1,(start+end)/2+1,end,l,r);
}
int main()	{
	int n,q;
	int ch,st,en;
	scanf("%d%d",&n,&q);
	build_tree(1,0,n-1);
	while(q--)	{
		scanf("%d%d%d",&ch,&st,&en);
		if(ch==0)	{
			update_tree(1,0,n-1,st-1,en-1);
		}
		else	{
			long long int ans=query_tree(1,0,n-1,st-1,en-1);
			cout<<ans<<endl;
		}
//		for(int i=1;i<=14;i++)	{
//			printf("%d %lld %lld %lld\n",i,tree[i].tot,tree[i].beg,tree[i].lazy);
//		}
//		cout<<endl;
	}
	return 0;
}
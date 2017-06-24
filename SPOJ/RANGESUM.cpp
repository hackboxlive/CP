#include <bits/stdc++.h>
using namespace std;
int ctr=0;
int arr[100100];
long long int tree[2002000];
void build_tree(int id,int l,int r)	{
	if(l==r)	{
		tree[id]=0;
		return;
	}
	build_tree(2*id,l,(l+r)/2);
	build_tree(2*id+1,(l+r)/2+1,r);
	tree[id]=0;
	return;
}
void update_tree(int id,int l,int r,int pos,int val)	{
	if(l>pos || r<pos)	{
		return;
	}
	if(l==pos && r==pos)	{
		tree[id]=val;
		return;
	}
	update_tree(2*id,l,(l+r)/2,pos,val);
	update_tree(2*id+1,(l+r)/2+1,r,pos,val);
	tree[id]=tree[2*id]+tree[2*id+1];
	return;
}
long long int query_tree(int id,int start,int end,int l,int r)	{
	if(start>r || end<l)	{
		return 0;
	}
	if(start>=l && end<=r)	{
		return tree[id];
	}
	return query_tree(2*id,start,(start+end)/2,l,r)+query_tree(2*id+1,(start+end)/2+1,end,l,r);
}
int main()	{
	int n;
	build_tree(1,0,200500);
	scanf("%d",&n);
	for(int i=0;i<n;i++)	{
		scanf("%d",&arr[i]);
	}
	for(int i=n-1;i>=0;i--)	{
		update_tree(1,0,200500,ctr,arr[i]);
		ctr++;
	}
	int q,ch;
	int p1,p2;
	long long int summ;
	scanf("%d",&q);
	while(q--)	{
		scanf("%d",&ch);
		if(ch==1)	{
			scanf("%d%d",&p1,&p2);
			p1=ctr-p1;
			p2=ctr-p2;
//			cout<<p1<<" "<<p2<<endl;
			summ=query_tree(1,0,200500,p2,p1);
			printf("%lld\n",summ);
		}
		else	{
			scanf("%d",&p1);
			update_tree(1,0,200500,ctr,p1);
			ctr++;
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
struct node	{
	int num[10];	
	int lazy;
}tree[600600];
void build_tree(int id,int l,int r)	{
	if(l==r)	{
		tree[id].num[0]=1;
		return;
	}
	build_tree(2*id,l,(l+r)/2);
	build_tree(2*id+1,(l+r)/2+1,r);
	tree[id].num[0]=tree[2*id].num[0]+tree[2*id+1].num[0];
	return;
}
void update_lazy(int id,int l,int r)	{
	tree[id].lazy%=10;
	if(tree[id].lazy>0)	{
		for(int j=0;j<tree[id].lazy;j++)	{
			int temp=tree[id].num[9];
			for(int i=9;i>0;i--)	{
				tree[id].num[i]=tree[id].num[i-1];
			}
			tree[id].num[0]=temp;
		}
		if(l!=r)	{
			tree[2*id].lazy+=tree[id].lazy;
			tree[2*id+1].lazy+=tree[id].lazy;
		}
		tree[id].lazy=0;
	}
	return;
}
void update_tree(int id,int start,int end,int l,int r)	{
	update_lazy(id,start,end);
	if(start>r || end<l)	{
		return;
	}
	if(start>=l && end<=r)	{
		int temp=tree[id].num[9];
		for(int i=9;i>0;i--)	{
			tree[id].num[i]=tree[id].num[i-1];
		}
		tree[id].num[0]=temp;
		tree[2*id].lazy++;
		tree[2*id+1].lazy++;
		return;
	}
	update_tree(2*id,start,(start+end)/2,l,r);
	update_tree(2*id+1,(start+end)/2+1,end,l,r);
	for(int i=0;i<10;i++)	{
		tree[id].num[i]=tree[2*id].num[i]+tree[2*id+1].num[i];
	}
	return;
}
int query_tree(int id,int start,int end,int l,int r)	{
	update_lazy(id,start,end);
	if(start>r || end<l)	{
		return 0;
	}
	if(start>=l && end<=r)	{
		int ssum=0;
		for(int i=0;i<10;i++)	{
			ssum+=((tree[id].num[i])*i);
		}
		return ssum;
	}
	return query_tree(2*id,start,(start+end)/2,l,r)+query_tree(2*id+1,(start+end)/2+1,end,l,r);
}
int main()	{
	int n,q;
	int ch,l,r;
	scanf("%d%d",&n,&q);
	build_tree(1,0,n-1);
	while(q--)	{
		scanf("%d%d%d",&ch,&l,&r);
		if(ch==1)	{
			update_tree(1,0,n-1,l-1,r-1);
		}
		else	{
			int ans=query_tree(1,0,n-1,l-1,r-1);
			printf("%d\n",ans);
		}
//		for(int i=0;i<)
	}
	return 0;
}
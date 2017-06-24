#include <bits/stdc++.h>
using namespace std;
struct inp	{
	int val;
	int tall;
}arr[10100];
int oup[10100];
struct node	{
	int left;
	int right;
	int tot;
}tree[60600];
bool comp(const inp &p1,const inp &p2)	{
	return p1.val<p2.val;
}
void build_tree(int id,int l,int r)	{
	if(l==r)	{
		tree[id].left=-1;
		tree[id].right=-1;
		tree[id].tot=1;
		return;
	}
	build_tree(2*id,l,(l+r)/2);
	build_tree(2*id+1,(l+r)/2+1,r);
	tree[id].left=tree[2*id].tot;
	tree[id].right=tree[2*id+1].tot;
	tree[id].tot=tree[id].left+tree[id].right;
	return;
}
void insert_tree(int id,int l,int r,int pos,int valu)	{
	if(l==r)	{
		oup[l]=valu;
		tree[id].tot=0;
		return;
	}
	if(tree[id].left>pos)	{
		insert_tree(2*id,l,(l+r)/2,pos,valu);
		tree[id].left=tree[2*id].tot;
		tree[id].right=tree[2*id+1].tot;
		tree[id].tot=tree[id].left+tree[id].right;
	}
	else	{
		insert_tree(2*id+1,(l+r)/2+1,r,pos-tree[id].left,valu);
		tree[id].left=tree[2*id].tot;
		tree[id].right=tree[2*id+1].tot;
		tree[id].tot=tree[id].left+tree[id].right;
	}
}
int main()	{
	int t,num;
	scanf("%d",&t);
	while(t--)	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)	{
			scanf("%d",&arr[i].val);
		}
		for(int i=0;i<n;i++)	{
			scanf("%d",&arr[i].tall);
		}
		sort(arr,arr+n,comp);
		build_tree(1,0,n-1);
		for(int i=0;i<n;i++)	{
			insert_tree(1,0,n-1,arr[i].tall,arr[i].val);
		}
		for(int j=0;j<n;j++)	{
			printf("%d ",oup[j]);
		}
		printf("\n");;
	}
	return 0;
}
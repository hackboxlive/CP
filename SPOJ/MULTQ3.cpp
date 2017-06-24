#include <bits/stdc++.h>
using namespace std;
struct node{
	int zero;
	int one;
	int two;
	int lazy;
}tree[600600];
int arr[100100];
void build_tree(int id,int l,int r)	{
	if(l==r)	{
		tree[id].zero=1;
		tree[id].one=0;
		tree[id].two=0;
		return;
	}
	build_tree(2*id,l,(l+r)/2);
	build_tree(2*id+1,(l+r)/2+1,r);
	tree[id].zero=tree[2*id].zero+tree[2*id+1].zero;
	tree[id].one=tree[2*id].one+tree[2*id+1].one;
	tree[id].two=tree[2*id].two+tree[2*id+1].two;
	return;
}
void update_lazy(int id,int l,int r)	{
	if(tree[id].lazy>0)	{
		if(tree[id].lazy%3==1)	{
			int temp=tree[id].zero;
			tree[id].zero=tree[id].two;
			tree[id].two=tree[id].one;
			tree[id].one=temp;
		}
		if(tree[id].lazy%3==2)	{
			int temp=tree[id].zero;
			tree[id].zero=tree[id].one;
			tree[id].one=tree[id].two;
			tree[id].two=temp;
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
		tree[id].lazy++;
		update_lazy(id,start,end);
		return;
	}
	update_tree(2*id,start,(start+end)/2,l,r);
	update_tree(2*id+1,(start+end)/2+1,end,l,r);
	update_lazy(2*id,l,(l+r)/2);
	update_lazy(2*id+1,(l+r)/2+1,r);
	tree[id].zero=tree[2*id].zero+tree[2*id+1].zero;
	tree[id].one=tree[2*id].one+tree[2*id+1].one;
	tree[id].two=tree[2*id].two+tree[2*id+1].two;
	return;
}
int query_tree(int id,int start,int end,int l,int r)	{
	update_lazy(id,start,end);
	if(start>r || end<l)	{
		return 0;
	}
	if(start>=l && end<=r)	{
		return tree[id].zero;
	}
	return query_tree(2*id,start,(start+end)/2,l,r)+query_tree(2*id+1,(start+end)/2+1,end,l,r);
}
int main()	{
	int n,q;
	scanf("%d%d",&n,&q);
	build_tree(1,0,n-1);	
	int ch,x,y;
	while(q--)	{
		scanf("%d%d%d",&ch,&x,&y);
		if(ch==0)	{
			update_tree(1,0,n-1,x,y);
		}
		else	{
			int ans=query_tree(1,0,n-1,x,y);
			printf("%d\n",ans);
		}
	}
}
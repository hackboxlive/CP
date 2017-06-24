#include <bits/stdc++.h>
using namespace std;
int arr[100100];
struct node	{
	int lval;
	int lfreq;
	int rval;
	int rfreq;
	int bfreq;
} tree[400100];
void build_tree(int id,int l,int r)	{
	if(l==r)	{
		tree[id].lval=arr[l];
		tree[id].rval=arr[l];
		tree[id].lfreq=1;
		tree[id].rfreq=1;
		tree[id].bfreq=1;
		return;
	}
	build_tree(2*id,l,(l+r)/2);
	build_tree(2*id+1,(l+r)/2+1,r);
	tree[id].lval=tree[2*id].lval;
	tree[id].rval=tree[2*id+1].rval;
	if(tree[2*id].lval==tree[2*id+1].lval)	{
		tree[id].lfreq=tree[2*id].lfreq+tree[2*id+1].lfreq;
	}
	else	{
		tree[id].lfreq=tree[2*id].lfreq;
	}
	if(tree[2*id].rval==tree[2*id+1].rval)	{
		tree[id].rfreq=tree[2*id].rfreq+tree[2*id+1].rfreq;
	}
	else	{
		tree[id].rfreq=tree[2*id+1].rfreq;
	}
	tree[id].bfreq=max(tree[2*id].bfreq,tree[2*id+1].bfreq);
	if(tree[2*id].rval==tree[2*id+1].lval)	{
		tree[id].bfreq=max(tree[id].bfreq,tree[2*id].rfreq+tree[2*id+1].lfreq);
	}
	return;
}
node query(int id,int start,int end,int l,int r)	{
	if(start>r || end<l)	{
		node nullnode;
		nullnode.lval=nullnode.rval=999999;
		nullnode.lfreq=nullnode.rfreq=nullnode.bfreq=0;
		return nullnode;
	}
	if(start>=l && end<=r)	{
		return tree[id];
	}
	node p=query(2*id,start,(start+end)/2,l,r);
	node q=query(2*id+1,(start+end)/2+1,end,l,r);
	node m;
	m.lval=p.lval;
	m.rval=q.rval;
	if(p.lval==q.lval)	{
		m.lfreq=p.lfreq+q.lfreq;
	}
	else	{
		m.lfreq=p.lfreq;
	}
	if(p.rval==q.rval)	{
		m.rfreq=p.rfreq+q.rfreq;
	}
	else	{
		m.rfreq=q.rfreq;
	}
	m.bfreq=max(p.bfreq,q.bfreq);
	if(p.rval==q.lval)	{
		m.bfreq=max(m.bfreq,p.rfreq+q.lfreq);
	}
	return m;
}
int main()	{
	int n,q,l,r;
	node val;
	scanf("%d",&n);
	while(n!=0)	{
		scanf("%d",&q);
		for(int i=1;i<=n;i++)	{
			scanf("%d",&arr[i]);
		}
		build_tree(1,1,n);
		while(q--)	{
			scanf("%d%d",&l,&r);
			val=query(1,1,n,l,r);
			printf("%d\n",val.bfreq);
		}
		scanf("%d",&n);
	}
	return 0;
}
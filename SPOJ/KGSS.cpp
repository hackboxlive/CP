#include <bits/stdc++.h>
using namespace std;
int arr[200100];
struct node	{
	int maxx;
	int secmaxx;
}tree[1000100];
void build_tree(int id,int l,int r)	{
	if(l==r)	{
		tree[id].maxx=arr[l];
		tree[id].secmaxx=-1;
		return;
	}
	build_tree(2*id,l,(l+r)/2);
	build_tree(2*id+1,(l+r)/2+1,r);
	tree[id].maxx=max(tree[2*id].maxx,tree[2*id+1].maxx);
	if(tree[2*id].maxx==tree[id].maxx)	{
		tree[id].secmaxx=max(tree[2*id+1].maxx,max(tree[2*id].secmaxx,tree[2*id+1].secmaxx));
	}
	else	{
		tree[id].secmaxx=max(tree[2*id].maxx,max(tree[2*id].secmaxx,tree[2*id+1].secmaxx));
	}
	return;
}
node query_tree(int id,int start,int end,int l,int r)	{
	if(start>r || end<l)	{
		node nullnode;
		nullnode.maxx=0;
		nullnode.secmaxx=0;
		return nullnode;
	}
	if(start>=l && end<=r)	{
		return tree[id];
	}
	node p=query_tree(2*id,start,(start+end)/2,l,r);
	node q=query_tree(2*id+1,(start+end)/2+1,end,l,r);
	node ans;
	ans.maxx=max(p.maxx,q.maxx);
	if(ans.maxx==p.maxx)	{
		ans.secmaxx=max(q.maxx,max(p.secmaxx,q.secmaxx));
	}
	else	{
		ans.secmaxx=max(p.maxx,max(p.secmaxx,q.secmaxx));
	}
	return ans;
}
void update_tree(int id,int start,int end,int pos,int val)	{
	if(start>pos || end<pos)	{
		return;
	}
	if(start==pos && end==pos)	{
		tree[id].maxx=val;
		return;
	}
	update_tree(2*id,start,(start+end)/2,pos,val);
	update_tree(2*id+1,(start+end)/2+1,end,pos,val);
	tree[id].maxx=max(tree[2*id].maxx,tree[2*id+1].maxx);
	if(tree[2*id].maxx==tree[id].maxx)	{
		tree[id].secmaxx=max(tree[2*id+1].maxx,max(tree[2*id].secmaxx,tree[2*id+1].secmaxx));
	}
	else	{
		tree[id].secmaxx=max(tree[2*id].maxx,max(tree[2*id].secmaxx,tree[2*id+1].secmaxx));
	}
	return;
}
int main()	{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)	{
		scanf("%d",&arr[i]);
	}
	build_tree(1,0,n-1);
	int q,x,y;
	string s;
	node g;
	scanf("%d",&q);
	while(q--)	{
		cin>>s;
		scanf("%d%d",&x,&y);
		if(s[0]=='Q')	{
			g=query_tree(1,0,n-1,x-1,y-1);
			printf("%d\n",g.maxx+g.secmaxx);
		}
		else	{
			update_tree(1,0,n-1,x-1,y);
		}
	}
	return 0;
}
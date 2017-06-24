#include <bits/stdc++.h>
#define gc getchar_unlocked
using namespace std;
long long int tree[40000];
long long int lazy[40000];
int read_int()	{
	char c=gc();
	while(c<'0' || c>'9')	{
		c=gc();
	}
	int ret=0;
	while(c>='0' && c<='9')	{
	ret=10*ret+c-48;
	c=gc();
	}
	return ret;
}
void update(int id,int start,int end,int l,int r,int val)	{
	if(lazy[id]!=0)	{
		tree[id]=tree[id]+(end-start+1)*lazy[id];
		if(start!=end)	{
			lazy[2*id]=lazy[2*id]+lazy[id];
			lazy[2*id+1]=lazy[2*id+1]+lazy[id];
		}
		lazy[id]=0;
	}
	if(start>end || start>r || end<l)	{
		return;
	}
	if(start>=l && end<=r)	{
		tree[id]=tree[id]+(end-start+1)*val;
		if(start!=end)	{
			lazy[2*id]=lazy[2*id]+val;
			lazy[2*id+1]=lazy[2*id+1]+val;
		}
		return;
	}
	update(2*id,start,(start+end)/2,l,r,val);
	update(2*id+1,(start+end)/2+1,end,l,r,val);
	tree[id]=tree[2*id]+tree[2*id+1];
	return;
}
long long int query(int id,int start,int end,int l,int r)	{
	if(start>end || start>r || end<l)	{
		return 0;
	}
	if(lazy[id]!=0)	{
		tree[id]=tree[id]+(end-start+1)*lazy[id];
		if(start!=end)	{
			lazy[2*id]=lazy[2*id]+lazy[id];
			lazy[2*id+1]=lazy[2*id+1]+lazy[id];
		}
		lazy[id]=0;
	}
	if(start>=l && end<=r)	{
		return tree[id];
	}
	return query(2*id,start,(start+end)/2,l,r)+query(2*id+1,(start+end)/2+1,end,l,r);
}
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		memset(tree,0,sizeof(tree));
		memset(lazy,0,sizeof(lazy));
		int n,u,l,r,val;
		n=read_int();
		u=read_int();
//		scanf("%d%d",&n,&u);
		for(int i=0;i<u;i++)	{
//			scanf("%d%d%d",&l,&r,&val);
			l=read_int();
			r=read_int();
			val=read_int();
			update(1,1,n,l+1,r+1,val);
		}
		int q,pos;
//		scanf("%d",&q);
		q=read_int();
		while(q--)	{
//			scanf("%d",&pos);
			pos=read_int();
			printf("%lld\n",query(1,1,n,pos+1,pos+1));
		}
	}
	return 0;
}
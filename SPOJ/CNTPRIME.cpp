#include <bits/stdc++.h>
using namespace std;
int arr[10100];
int primes[2001000];
int tree[100000];
int lazy[100000];
void sieve()	{
	memset(primes,0,sizeof(primes));
	primes[0]=1;
	primes[1]=1;
	for(int i=2;i<=2001000;i++)	{
		for(int j=2;j*i<=2001000;j++)	{
			primes[i*j]=1;
		}
	}
	return;
}
void build_tree(int id,int l,int r)	{
	if(l==r)	{
		if(primes[arr[l]]==0)	{
			tree[id]=1;
		}
		else	{
			tree[id]=0;
		}
		return;
	}
	build_tree(2*id,l,(l+r)/2);
	build_tree(2*id+1,(l+r)/2+1,r);
	tree[id]=tree[2*id]+tree[2*id+1];
	return;
}
void lazzy(int id,int l,int r)	{
	if(lazy[id]!=0)	{
		if(lazy[id]==1)	{
			tree[id]=r-l+1;
		}
		else	{
			tree[id]=0;
		}
		if(l!=r)	{
			lazy[2*id]=lazy[id];
			lazy[2*id+1]=lazy[id];
		}
		lazy[id]=0;
	}
	return;
}
void update_lazy(int id,int start,int end,int l,int r,int val)	{
	lazzy(id,start,end);
	if(start>r || end<l)	{
		return;
	}
	if(start>=l && end<=r)	{
		if(val==1)	{
			tree[id]=end-start+1;
		}
		else	{
			tree[id]=0;
		}
		if(l!=r)	{
			lazy[2*id]=val;
			lazy[2*id+1]=val;
		}
		return;
	}
	update_lazy(2*id,start,(start+end)/2,l,r,val);
	update_lazy(2*id+1,(start+end)/2+1,end,l,r,val);
	tree[id]=tree[2*id]+tree[2*id+1];
	return;
}
int query_tree(int id,int start,int end,int l, int r)	{
	lazzy(id,start,end);
	if(start>r || end<l)	{
		return 0;
	}
	if(start>=l && end<=r)	{
		return tree[id];
	}
	int p=query_tree(2*id,start,(start+end)/2,l,r);
	int q=query_tree(2*id+1,(start+end)/2+1,end,l,r);
	return (p+q);
}
int main()	{
	int t,ch,v,x,y;
	int c=0;
	sieve();
	scanf("%d",&t);
	while(t--)	{
		int n,q;
		memset(lazy,0,sizeof(lazy));
		int ans;
		scanf("%d%d",&n,&q);
		for(int i=0;i<n;i++)	{
			scanf("%d",&arr[i]);
		}
		build_tree(1,0,n-1);
		printf("Case %d:\n",++c);
		while(q--)	{
			scanf("%d",&ch);
			if(ch==0)	{
				scanf("%d%d%d",&x,&y,&v);
				if(primes[v]==0)	{
					update_lazy(1,0,n-1,x-1,y-1,1);
				}
				else	{
					update_lazy(1,0,n-1,x-1,y-1,-1);
				}
			}
			else	{
				scanf("%d%d",&x,&y);
				ans=query_tree(1,0,n-1,x-1,y-1);
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
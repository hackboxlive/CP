#include <bits/stdc++.h>
using namespace std;
long long int lazy[1000000];
long long int tree[1000000];
void update_lazy(int id,int l,int r)	{
	if(lazy[id]>0)	{
		tree[id]+=(lazy[id]*(r-l+1));
		if(l!=r)	{
			lazy[2*id]+=lazy[id];
			lazy[2*id+1]+=lazy[id];
		}
		lazy[id]=0;
	}
	return;
}
void update_tree(int id,int start,int end,int l,int r)	{
	update_lazy(id,start,end);
	if(start>r || end<l)	{
		return;
	}
	if(start>=l && end<=r)	{
		tree[id]+=(end-start+1);
		if(l!=r)	{
			lazy[2*id]++;
			lazy[2*id+1]++;
		}
		return;
	}
	update_tree(2*id,start,(start+end)/2,l,r);
	update_tree(2*id+1,(start+end)/2+1,end,l,r);
	tree[id]=tree[2*id]+tree[2*id+1];
	return;
}
long long int query_tree(int id,int start,int end,int l,int r)	{
	if(start>r || end<l)	{
		return 0;
	}
	update_lazy(id,start,end);
	if(start>=l && end<=r)	{
		return tree[id];
	}
	return query_tree(2*id,start,(start+end)/2,l,r)+query_tree(2*id+1,(start+end)/2+1,end,l,r);
}
void build_tree(int id,int l,int r)	{
	if(l==r)	{
		tree[id]=0;
		lazy[id]=0;
		return;
	}
	build_tree(2*id,l,(l+r)/2);
	build_tree(2*id+1,(l+r)/2+1,r);
	tree[id]=0;
	lazy[id]=0;
	return;
}
int main()	{
	int t;
	int x,y;
	char s[15];
	scanf("%d",&t);
	for(int c=1;c<=t;++c)	{
		printf("Scenario #%d:\n",c);
		int n,q;
		long long int ans;
		scanf("%d%d",&n,&q);
		build_tree(1,0,n-1);
		while(q--)	{
			scanf("%s",s);
			scanf("%d%d",&x,&y);
			if(s[0]=='m')	{
				update_tree(1,0,n-1,x-1,y-1);
				printf("OK\n");
			}
			else	{
				ans=(long long int)query_tree(1,0,n-1,x-1,y-1);
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}
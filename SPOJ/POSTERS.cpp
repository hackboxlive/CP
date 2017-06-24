#include <bits/stdc++.h>
using namespace std;
int tree[40000000];
void update_lazy(int id,int start,int end,int l, int r,int val)	{
	if(start>r || end<l)	{
		return;
	}
	if(start>=l && end<=r)	{
		tree[id]=val;
		return;
	}
	update_lazy(2*id,start,(start+end)/2,l,r,val);
	update_lazy(2*id+1,(start+end)/2+1,end,l,r,val);
	return;
}
void complete_update(int id,int l,int r)	{
	if(l==r)	{
		return;
	}
	tree[2*id]=tree[id];
	tree[2*id+1]=tree[id];
	complete_update(2*id,l,(l+r)/2);
	complete_update(2*id+1,(l+r)/2+1,r);
	return;
}
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		int n,l,r;
		scanf("%d",&n);
		memset(tree,0,sizeof(int)*n*4);
		for(int i=1;i<=n;i++)	{
			scanf("%d%d",&l,&r);
			update_lazy(1,0,9999999,l-1,r-1,i);
			for(int i=1;i<=20;i++)	{
				cout<<tree[i]<<" ";
			}
			cout<<endl;
		}
		int maxx=-1;
		complete_update(1,0,9999999);
		for(int i=1;i<=9999999;i++)	{
			if(maxx<tree[i])	{
				maxx=tree[i];
			}
		}
		printf("%d\n",maxx);
	}
	return 0;
}
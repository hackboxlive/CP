#include <bits/stdc++.h>
using namespace std;
int numarr[1001000];
int arr[100100];
int tree[600600];
void least_prime_divisors()	{
	numarr[1]=1;
	for(int i=2;i<=1001000;i++)	{
		if(numarr[i]==0)	{
			for(int j=1;j*i<=1001000;j++)	{
				if(numarr[j*i]==0)	{
					numarr[j*i]=i;
				}
			}
		}
	}
	return;
}
void build_tree(int id,int l,int r)	{
	if(l==r)	{
		tree[id]=numarr[arr[l]];
		return;
	}
	build_tree(2*id,l,(l+r)/2);
	build_tree(2*id+1,(l+r)/2+1,r);
	tree[id]=max(tree[2*id],tree[2*id+1]);
	return;
}
void update_tree(int id,int start,int end,int l,int r)	{
	if(start>r || end<l)	{
		return;
	}
	if(start>=l && end<=r && tree[id]==1)	{
		return;
	}
	if(start==end && start>=l && start<=r)	{
		arr[start]=arr[start]/tree[id];
		tree[id]=numarr[arr[start]];
		return;
	}
	update_tree(2*id,start,(start+end)/2,l,r);
	update_tree(2*id+1,(start+end)/2+1,end,l,r);
	tree[id]=max(tree[2*id],tree[2*id+1]);
	return;
}
int query_tree(int id,int start,int end,int l,int r)	{
	if(start>r || end<l)	{
		return 1;
	}
	if(start>=l && end<=r)	{
		return tree[id];
	}
	return max(query_tree(2*id,start,(start+end)/2,l,r),query_tree(2*id+1,(start+end)/2+1,end,l,r));
}
int main()	{
	int t;
	int type,lt,rt;
	least_prime_divisors();
	scanf("%d",&t);
	while(t--)	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)	{
			scanf("%d",&arr[i]);
		}
		build_tree(1,0,n-1);
		while(m--)	{
			scanf("%d%d%d",&type,&lt,&rt);
			if(type==0)	{
				update_tree(1,0,n-1,lt-1,rt-1);
			}
			else	{
				int ans=query_tree(1,0,n-1,lt-1,rt-1);
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
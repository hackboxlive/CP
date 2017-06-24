#include <bits/stdc++.h>
using namespace std;
long long int arr[100100];
long long int tree[600600];
void build_tree(int id,int l,int r)	{
	if(l==r)	{
		tree[id]=arr[l];
		return;
	}
	build_tree(2*id,l,(l+r)/2);
	build_tree(2*id+1,(l+r)/2+1,r);
	tree[id]=tree[2*id]+tree[2*id+1];
	return;
}
void update_tree(int id,int start,int end,int l,int r)	{
	if(start>r || end<l)	{
		return;
	}
	if(start>=l && end<=r && tree[id]==end-start+1)	{
		return;
	}
	if(start==end)	{
		tree[id]=(long long int)sqrt(tree[id]);
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
	if(start>=l && end<=r)	{
		return tree[id];
	}
	return query_tree(2*id,start,(start+end)/2,l,r)+query_tree(2*id+1,(start+end)/2+1,end,l,r);
}
int main()	{
	int n;
	int c=0;
	while(cin>>n)	{
		for(int i=0;i<n;i++)	{
			scanf("%lld",&arr[i]);
		}
		build_tree(1,0,n-1);
		int q;
		int ch,x,y;
		scanf("%d",&q);
		printf("Case #%d:\n",++c);
		while(q--)	{
			scanf("%d%d%d",&ch,&x,&y);
			if(x>y)	{
				swap(x,y);
			}
			if(ch==0)	{
				update_tree(1,0,n-1,x-1,y-1);
			}
			else	{
				long long int ans=query_tree(1,0,n-1,x-1,y-1);
				printf("%lld\n",ans);
			}
		}
		printf("\n");
	}
	return 0;
}
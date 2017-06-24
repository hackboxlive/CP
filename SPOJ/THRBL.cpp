#include <bits/stdc++.h>
using namespace std;
int arr[50500];
int tree[300300];
void build_tree(int id,int l,int r)	{
	if(l==r)	{
		tree[id]=arr[l];
		return;
	}
	build_tree(2*id,l,(l+r)/2);
	build_tree(2*id+1,(l+r)/2+1,r);
	tree[id]=max(tree[2*id],tree[2*id+1]);
	return;
}
int query_tree(int id,int start,int end,int l,int r)	{
	if(start>r || end<l)	{
		return 0;
	}
	if(start>=l && end<=r)	{
		return tree[id];
	}
	return max(query_tree(2*id,start,(start+end)/2,l,r),query_tree(2*id+1,(start+end)/2+1,end,l,r));
}
int main()	{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)	{
		scanf("%d",&arr[i]);
	}
	int lt,rt;
	int ctr=0;
	build_tree(1,0,n-1);
	while(m--)	{
		scanf("%d%d",&lt,&rt);
		int ans=query_tree(1,0,n-1,lt,rt-2);
		if(ans<arr[lt-1])	{
			ctr++;
		}
	}
	printf("%d\n",ctr);
	return 0;
}
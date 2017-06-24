#include <bits/stdc++.h>
using namespace std;
long long int tree[600600];
long long int arr[100100];
long long int newarr[100100];
void update_tree(int id,int start,int end,int pos,long long int val)	{
	if(start>pos || end<pos)	{
		return;
	}
	if(start==pos && end==pos)	{
		tree[id]+=val;
		return;
	}
	update_tree(2*id,start,(start+end)/2,pos,val);
	update_tree(2*id+1,(start+end)/2+1,end,pos,val);
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
	long long int ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)	{
		scanf("%lld",&arr[i]);
	}
	update_tree(1,0,100100,arr[0],1);
	newarr[0]=0;
	for(int i=1;i<n;i++)	{
		newarr[i]=query_tree(1,0,100100,arr[i]+1,100100);
		update_tree(1,0,100100,arr[i],1);
	}
	memset(tree,0,sizeof(tree));
	update_tree(1,0,n-1,arr[0],newarr[0]);
	for(int i=1;i<n;i++)	{
		ans+=query_tree(1,0,100100,arr[i]+1,100100);
		update_tree(1,0,100100,arr[i],newarr[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
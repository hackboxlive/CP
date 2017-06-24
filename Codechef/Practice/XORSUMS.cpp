#include <bits/stdc++.h>
using namespace std;
int arr[300100];
int prefix[300100];
int tree[40000000];
void update(int id,int start,int end,int pos,int val)	{
	if(start>pos || end<pos)	{
		return;
	}
	if(start==pos && end==pos)	{
		tree[id]+=val;
		return;
	}
	update(2*id,start,(start+end)/2,pos,val);
	update(2*id+1,(start+end)/2+1,end,pos,val);
	tree[id]=tree[2*id]+tree[2*id+1];
	return;
}
int query(int id,int start,int end,int l,int r)	{
	if(start>r || end<l)	{
		return 0;
	}
	if(start>=l && end<=r)	{
		return tree[id];
	}
	return query(2*id,start,(start+end)/2,l,r)+query(2*id+1,(start+end)/2+1,end,l,r);
}
int main()	{
	int n;
	int maxsum=0;
	scanf("%d",&n);
	prefix[0]=0;
	for(int i=1;i<=n;i++)	{
		scanf("%d",&arr[i]);
		maxsum+=arr[i];
	}
	maxsum++;
	int ans=0;
	for(int i=0;(1<<i)<maxsum;i++)	{
		for(int j=1;j<=n;j++)	{
			prefix[j]=(prefix[j-1]+arr[j])&((1<<(i+1))-1);
		}
		int bitans=0;
		update(1,0,(1<<(i+1))-1,0,1);
		for(int j=1;j<=n;j++)	{
			bitans+=query(1,0,(1<<(i+1))-1,prefix[j]+1,prefix[j]+(1<<i));
			bitans+=query(1,0,(1<<(i+1))-1,0,prefix[j]-(1<<i));
			update(1,0,(1<<(i+1))-1,prefix[j],1);
		}
		update(1,0,(1<<(i+1))-1,0,-1);
		for(int j=1;j<=n;j++)	{
			update(1,0,(1<<(i+1))-1,prefix[j],-1);
		}
		if(bitans&1)	{
			ans|=(1<<i);
		}
	}
	printf("%d\n",ans);
	return 0;
}
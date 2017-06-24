#include <bits/stdc++.h>
#define UPLT 10000100
using namespace std;
//int arr[200100];
long long int tree[60006000];
void update_tree(int id,int start,int end,int pos)	{
	if(start>pos || end<pos)	{
		return;
	}
	if(start==pos && end==pos)	{
		tree[id]++;
		return;
	}
	update_tree(2*id,start,(start+end)/2,pos);
	update_tree(2*id+1,(start+end)/2+1,end,pos);
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
	int t,n;
	int num;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d",&n);
		memset(tree,0,sizeof(tree));
		if(n==0)	{
			cout<<"0";
			continue;
		}
		long long int ans=0;
		scanf("%d",&num);
		update_tree(1,0,UPLT,num);
		for(int i=1;i<n;i++)	{
			scanf("%d",&num);
			ans+=query_tree(1,0,UPLT,num+1,UPLT);
			update_tree(1,0,UPLT,num);
		}
		cout<<ans<<endl;
	}
	return 0;
}
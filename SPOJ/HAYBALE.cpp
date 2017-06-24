#include <bits/stdc++.h>
using namespace std;
int lazy[4001000];
int arr[1001000];
int ctr=0;
void add_tree(int id,int start,int end,int l,int r)	{
	if(start>r || end<l)	{
		return;
	}
	if(start>=l && end<=r)	{
		lazy[id]++;
		return;
	}
	add_tree(2*id,start,(start+end)/2,l,r);
	add_tree(2*id+1,(start+end)/2+1,end,l,r);
	return;
}
void build_array(int id,int l,int r)	{
	if(l==r)	{
		arr[ctr]=lazy[id];
		ctr++;
		return;
	}
	lazy[2*id]+=lazy[id];
	lazy[2*id+1]+=lazy[id];
	build_array(2*id,l,(l+r)/2);
	build_array(2*id+1,(l+r)/2+1,r);
	return;
}
int main()	{
	int n,k;
	int l,r;
	scanf("%d%d",&n,&k);
	while(k--)	{
		scanf("%d%d",&l,&r);
		add_tree(1,0,n-1,l-1,r-1);
//		for(int i=1;i<=31;i++){
//			cout<<lazy[i]<<" ";
//		}
//		cout<<endl;
	}
	build_array(1,0,n-1);
	sort(arr,arr+n);
	printf("%d\n",arr[n/2]);
	return 0;
}
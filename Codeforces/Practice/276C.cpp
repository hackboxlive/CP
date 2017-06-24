#include <bits/stdc++.h>
using namespace std;
long long int arr[200200];
long long int freq[200200];
long long int tree[2002000];
bool compdesc(const long long int &p1,const long long int &p2)	{
	return p1>p2;
}
void build_tree(int id,int l,int r)	{
	if(l==r)	{
		tree[id]=0;
		return;
	}
	build_tree(2*id,l,(l+r)/2);
	build_tree(2*id+1,(l+r)/2+1,r);
	tree[id]=0;
	return;
}
void update_lazy(int id,int l,int r)	{
	if(tree[id]>0 && l!=r)	{
		tree[2*id]+=tree[id];
		tree[2*id+1]+=tree[id];
		tree[id]=0;
	}
	return;
}
void update_tree(int id,int start,int end,int l,int r)	{
	if(start>r || end<l)	{
		return;
	}
	if(start>=l && end<=r)	{
		tree[id]++;
		return;
	}
	update_lazy(id,start,end);
	update_tree(2*id,start,(start+end)/2,l,r);
	update_tree(2*id+1,(start+end)/2+1,end,l,r);
	return;
}
void calc_freq(int id,int l,int r)	{
	update_lazy(id,l,r);
	if(l==r)	{
//		freq[l].first=l;
		freq[l]=tree[id];
		return;
	}
	calc_freq(2*id,l,(l+r)/2);
	calc_freq(2*id+1,(l+r)/2+1,r);
	return;
}
int main()	{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)	{
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n,compdesc);
	int l,r;
	build_tree(1,0,n-1);
	for(int i=0;i<q;i++)	{
		scanf("%d%d",&l,&r);
		update_tree(1,0,n-1,l-1,r-1);
	}
	calc_freq(1,0,n-1);
//	for(int i=0;i<n;i++)	{
//		cout<<freq[i]<<" ";
//	}
	sort(freq,freq+n,compdesc);
	long long int ans=0;
	for(int i=0;i<n;i++)	{
		ans+=(long long int)freq[i]*arr[i];
	}
	cout<<ans;	
}
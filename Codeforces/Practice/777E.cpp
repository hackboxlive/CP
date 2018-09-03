//time 11:14 pm
#include <bits/stdc++.h>
using namespace std;

struct node	{
	long long a;
	long long b;
	long long h;
	int pos;
}arr[100100];
long long xx[100100];
bool c1(const node &x,const node &y)	{
	if(x.a==y.a)	{
		return x.b < y.b;
	}
	return x.a < y.a;
}
bool c2(const node &x,const node &y)	{
	if(x.b==y.b)	{
		return x.a < y.a;
	}
	return x.b < y.b;
}
long long tree[600600];
long long query(int id,int st,int en,int l,int r)	{
	if(st>r || en<l)	{
		return 0;
	}
	if(st>=l && en<=r)	{
		return tree[id];
	}
	return max(query(2*id,st,(st+en)/2,l,r),query(2*id+1,(st+en)/2+1,en,l,r));
}
void update(int id,int l,int r,int pos,long long ans)	{
	if(l>pos || r<pos)	{
		return;
	}
	if(l==pos && r==pos)	{
		tree[id]=ans;
		return;
	}
	update(2*id,l,(l+r)/2,pos,ans);
	update(2*id+1,(l+r)/2+1,r,pos,ans);
	tree[id]=max(tree[2*id],tree[2*id+1]);
}
int main()	{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>arr[i].a>>arr[i].b>>arr[i].h;
	}
	sort(arr,arr+n,c1);
	for(int i=0;i<n;i++)	{
		xx[i]=arr[i].a;
		arr[i].pos=i;
	}
	long long tot_ans=0;
	sort(arr,arr+n,c2);
	for(int i=n-1;i>=0;i--)	{
		long long b=arr[i].b;
		int pos=lower_bound(xx,xx+n,b)-xx;
		long long ans=query(1,0,n-1,0,pos-1);
		ans+=arr[i].h;
		update(1,0,n-1,arr[i].pos,ans);
		tot_ans=max(tot_ans,ans);
	}
	cout<<tot_ans<<endl;
	return 0;
}
//first submission 11:44pm
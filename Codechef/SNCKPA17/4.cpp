#include <bits/stdc++.h>
using namespace std;
long long h[100100];
long long a[100100];
long long b[100100];
long long c[100100];
int main()	{
	int t,n;
	cin>>t;
	while(t--)	{
		long long s=0;
		cin>>n;
		for(int i=0;i<n;i++)	{
			cin>>h[i];
			s+=h[i];
		}
		a[0]=a[n-1]=1;
		b[0]=b[n-1]=1;
		long long mx;
		for(int i=1;i<n-1;i++)	{
			a[i]=min(a[i-1]+1,h[i]);
		}
		for(int i=n-2;i>0;i--)	{
			b[i]=min(b[i+1]+1,h[i]);
		}
		for(int i=0;i<n;i++)	{
			c[i]=min(a[i],b[i]);
		}
		mx=0;
		for(int i=0;i<n;i++)	{
			mx=max(mx,c[i]);
		}
		cout<<s-mx*mx<<endl;
	}
	return 0;
}
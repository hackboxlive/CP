#include <bits/stdc++.h>
using namespace std;
#define mod 10007
int main()
{
	int n; scanf("%d",&n);
	long long int a[100001]={0};
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}	
	sort(a,a+n);
	long long int sum=0;
//	for(int i=0;i<n;i++) cout<<a[i]<<endl;
	for(int i=0;i<n;i++)
	{
		long long int p = a[i]*a[n-1-i];
		if(p>=mod) p%=mod;
		sum+=p;
		if(sum>=mod) sum%=mod;
	}
	cout<<sum<<endl;
}
#include <bits/stdc++.h>
using namespace std;
long long arr[1001000];
long long minpos[1001000];
long long maxpos[1001000];
long long mod=1e9+7;
long long premax[1001000];
long long premin[1001000];
int main()	{
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++)	{
		cin>>arr[i];
	}
	maxpos[1]=1;
	for(long long i=2;i<=n;i++)	{
		if(arr[i]>arr[maxpos[i-1]])	{
			maxpos[i]=i;
		}
		else	{
			maxpos[i]=maxpos[i-1];
		}
	}
	minpos[n]=n;
	for(long long i=n-1;i>=1;i--)	{
		if(arr[i]<arr[minpos[i+1]])	{
			minpos[i]=i;
		}
		else	{
			minpos[i]=minpos[i+1];
		}
	}
	premax[1]=arr[maxpos[1]];
	for(long long i=2;i<=n;i++)	{
		if(maxpos[i]==i)	{
			premax[i]=(long long)arr[i]*i;
			premax[i]=premax[i]%mod;
		}
		else	{
			premax[i]=(long long)arr[i]*(i-maxpos[i]);
			premax[i]=premax[i]%mod;
			premax[i]=(long long)(premax[i]+premax[maxpos[i]])%mod;
		}
	}
	premin[n]=arr[minpos[n]];
	for(long long i=n-1;i>=1;i--)	{
		if(minpos[i]==i)	{
			premin[i]=(long long)arr[i]*(n+1-i);
			premin[i]=premin[i]%mod;
		}
		else	{
			premin[i]=(long long)arr[i]*(minpos[i]-i);
			premin[i]=premin[i]%mod;
			premin[i]=(long long)(premin[i]+premin[minpos[i]])%mod;
		}
	}
	for(long long i=n-1;i>=1;i--)	{
		premin[i]=(long long)(premin[i+1]+premin[i])%mod;
	}
	long long ans=0;
	long long temp;
	for(long long i=1;i<n;i++)	{
		temp=(premax[i]*premin[i+1])%mod;
		ans=(ans+temp)%mod;
	}
	cout<<ans<<endl;
	return 0;
}
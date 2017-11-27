#include <bits/stdc++.h>
using namespace std;
int prime[10001000];
int mark[10001000];
//vector<long long> v;
void sieve()	{
	prime[0]=prime[1]=1;
	for(int i=2;i<=1e7;i++)	{
		if(prime[i]==0)	{
			for(int j=i+i;j<=1e7;j+=i)	{
				prime[j]=1;
			}
		}
	}
}
void precompute()	{
	long long x,y=0;
	for(long long i=1;y<=1e7;i++)	{
		x=0;
		for(long long j=1;x+y<=1e7;j++)	{
			if(prime[x+y]==0)	{
				mark[x+y]=1;
			}
			x=j*j;
		}
		y=i*i*i*i;
	}
	for(int i=1;i<=1e7;i++)	{
		mark[i]+=mark[i-1];
	}
}
int main()	{
	sieve();
	precompute();
	int t,n;
	cin>>t;
	while(t--)	{
		cin>>n;
		cout<<mark[n]<<endl;
	}
	return 0;
}
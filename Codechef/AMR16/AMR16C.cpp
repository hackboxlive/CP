#include <bits/stdc++.h>
using namespace std;
bool prime[1001000];
long long arr[100100];
map<long long,bool> mp;
void sieve()	{
	long long maxx=1e9;
	maxx*=1000;
	memset(prime,false,sizeof(prime));
	for(int i=2;i<1001000;i++)	{
		if(prime[i]==false)	{
			for(int j=2*i;j<1001000;j+=i)	{
				prime[j]=true;
			}
		}
	}
	long long v;
	for(int i=2;i<1001000;i++)	{
		if(prime[i]==false)	{
			v=i;
			for(int j=2;v<=maxx;j++)	{
				v=v*i;
				if(prime[j+1]==false)	{
					mp[v]=true;
				}
			}
		}
	}
}
int main()	{
	sieve();
	int t;
	cin>>t;
	while(t--)	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)	{
			cin>>arr[i];
		}
		sort(arr,arr+n);
		int flag=0;
		for(int i=n-1;i>=0;i--)	{
			if(mp.find(arr[i])!=mp.end())	{
				cout<<n-i<<" ";
				flag=1;
			}
		}
		if(flag==0)	{
			cout<<"No supporter found.";
		}
		cout<<endl;
	}
	return 0;
}

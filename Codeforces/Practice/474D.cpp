#include <bits/stdc++.h>
using namespace std;
long long int arr[100100];
void compute(int k)	{
	long long int mod=1000000007;
	arr[0]=0;
	for(int i=1;i<k;i++)	{
		arr[i]=1;
	}
	arr[k]=2;
	for(int i=k+1;i<100100;i++)	{
		arr[i]=(arr[i-1]+arr[i-k])%mod;
	}
	for(int i=2;i<=100100;i++)	{
		arr[i]=(arr[i]+arr[i-1])%mod;
	}
	return;
}
int main()	{
	int t,k;
	cin>>t>>k;
	int a,b;
	long long int ss;
	compute(k);
	while(t--)	{
		cin>>a>>b;
		ss=arr[b]-arr[a-1];
		if(ss<0)	{
			ss=ss+1000000007;
			cout<<ss<<endl;
		}
		else	{
			cout<<ss<<endl;
		}
	}
	return 0;
}
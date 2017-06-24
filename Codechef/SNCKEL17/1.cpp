#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long arr[100100];
long long dp[100100];
int main()	{
	int t;
	cin>>t;
	int n;
	while(t--)	{
		cin>>n;
		for(int i=0;i<n;i++)	{
			cin>>arr[i];
		}
		dp[0]=arr[0]%mod;
		long long dpsum=dp[0];
		long long extra=arr[0]%mod;
		long long two=1;
		for(int i=1;i<n;i++)	{
			extra=(extra+two)%mod;
			extra=(extra*arr[i])%mod;
			dp[i]=dpsum;
			dp[i]=(dp[i]+extra)%mod;
			dpsum=(dpsum+dp[i])%mod;
			two=(two*2)%mod;
		}
		cout<<dp[n-1]%mod<<endl;
	}
	return 0;
}
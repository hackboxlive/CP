#include <bits/stdc++.h>
using namespace std;
long long int dp[100100];
int main()	{
	int t;
	string s;
	scanf("%d",&t);
	while(t--)	{
		cin>>s;
		int mod=1000000007;
		int last[26];
		for(int i=0;i<26;i++)	{
			last[i]=-1;
		}
		dp[0]=1;
		for(int i=1;i<=s.length();i++)	{
			char ch=s[i-1];
			if(last[ch-'A']==-1)	{
				dp[i]=(dp[i-1]*2)%mod;
				last[ch-'A']=i-1;
			}
			else	{
				dp[i]=((dp[i-1]*2)%mod-dp[last[ch-'A']])%mod;
				last[ch-'A']=i-1;
				if(dp[i]<0)	{
					dp[i]=dp[i]+mod;
				}
			}
		}
		printf("%lld\n",dp[s.length()]);
	}
	return 0;
}
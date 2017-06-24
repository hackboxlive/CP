#include <bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int main()	{
	string s;
	string t;
	cin>>s;
	while(s[0]!='#')	{
		cin>>t;
		for(int i=0;i<=s.length();i++)	{
			dp[0][i]=0;
		}
		for(int i=0;i<=t.length();i++)	{
			dp[i][0]=0;
		}
		for(int i=1;i<=s.length();i++)	{
			for(int j=1;j<=t.length();j++)	{
				if(s[i-1]==t[j-1])	{
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else	{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
		int val=15*(s.length()-dp[s.length()][t.length()])+30*(t.length()-dp[s.length()][t.length()]);
		cout<<val<<endl;
		cin>>s;
	}
	return 0;
}
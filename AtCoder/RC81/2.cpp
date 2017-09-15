#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n;
	cin>>n;
	string s1,s2;
	cin>>s1;
	cin>>s2;
	string str="";
	int c=0;
	while(c<n-1)	{
		if(s1[c]!=s1[c+1])	{
			str+='h';
			c++;
		}
		else	{
			str+='v';
			c+=2;
		}
	}
	if(s1[n-1]==s2[n-1])	{
		str+='h';
	}
//	cout<<str<<endl;
	long long dp[100];
	long long mod=1e9+7;
	memset(dp,0,sizeof(dp));
	if(str[0]=='v')	{
		dp[0]=6;
	}
	else	{
		dp[0]=3;
	}
	for(int i=1;i<str.length();i++)	{
//		cout<<i<<" = i"<<endl;
		if(str[i]=='h' && str[i-1]=='v')	{
			dp[i]=dp[i-1];
		}
		if(str[i]=='v' && str[i-1]=='v')	{
			dp[i]=dp[i-1]*3;
			dp[i]=dp[i]%mod;
		}
		if(str[i]=='h' && str[i-1]=='h')	{
			dp[i]=dp[i-1]*2;
			dp[i]=dp[i]%mod;
		}
		if(str[i]=='v' && str[i-1]=='h')	{
			dp[i]=dp[i-1]*2;
			dp[i]=dp[i]%mod;
		}
	}
	cout<<dp[str.length()-1]<<endl;
	return 0;
}
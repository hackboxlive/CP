#include <bits/stdc++.h>
using namespace std;
long long dp[5005][5005];
long long pre[5005];
const long long modd=1e9+7;
int main()	{
	int n;
	cin>>n;
	string s;
	string tot;
	for(int i=0;i<n;i++)	{
		cin>>s;
		tot+=s;
	}
	dp[0][0]=1;
//	cout<<tot<<endl;
	for(int i=1;i<tot.length();i++)	{
		pre[0]=dp[i-1][0];
		for(int j=1;j<=tot.length();j++)	{
			pre[j]=(pre[j-1]+dp[i-1][j])%modd;
		}
		if(tot[i-1]=='f')	{
			for(int j=0;j<tot.length();j++)	{
				dp[i][j+1]=dp[i-1][j];
			}
		}
		else	{
			//sum from j to all
			dp[i][0]=pre[tot.length()];
			for(int j=1;j<tot.length();j++)	{
				dp[i][j]=pre[tot.length()]-pre[j-1];
				if(dp[i][j]<0)	{
					dp[i][j]+=modd;
				}
			}
		}
	}
	//print dp
	// for(int i=0;i<n;i++)	{
	// 	for(int j=0;j<=n;j++)	{
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	long long ans=0;
	for(int i=0;i<=tot.length();i++)	{
		ans+=dp[n-1][i];
		ans%=modd;
	}
	cout<<ans<<endl;
	return 0;
}
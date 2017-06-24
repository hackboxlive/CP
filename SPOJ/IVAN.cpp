#include <bits/stdc++.h>
using namespace std;
int ar1[2020],ar2[2020];
int dp[2020][2020];
int main()	{
	int a,b;
	cin>>a>>b;
	for(int i=1;i<=a;i++)	{
		cin>>ar1[i];
	}
	for(int i=1;i<=b;i++)	{
		cin>>ar2[i];
	}
	for(int i=0;i<=a;i++)	{
		for(int j=0;j<=b;j++)	{
			dp[i][j]=1e9;
		}
	}
	dp[0][0]=0;
	for(int i=1;i<=a;i++)	{
		for(int j=1;j<=b;j++)	{
			dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+(ar1[i]-1)*(ar2[j]-1);
		}
	}
	cout<<dp[a][b]<<endl;
	return 0;
}
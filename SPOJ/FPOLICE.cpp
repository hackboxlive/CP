#include <bits/stdc++.h>
using namespace std;
int times[110][110];
int risk[110][110];
int dp[110][300];
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)	{
			for(int j=1;j<=n;j++)	{
				scanf("%d",&times[i][j]);
			}
		}
		for(int i=1;i<=n;i++)	{
			for(int j=1;j<=n;j++)	{
				scanf("%d",&risk[i][j]);
			}
		}
		for(int i=1;i<=n;i++)	{
			for(int j=1;j<=m;j++)	{
				dp[i][j]=1e8;
			}
		}
		for(int i=1;i<=m;i++)	{
			dp[1][i]=0;
		}
		for(int i=2;i<=n;i++)	{
			for(int j=1;j<=m;j++)	{
				for(int k=1;k<=n;k++)	{
					if(k==i)	{
						continue;
					}
					if(times[k][i]>j)	{
						continue;
					}
					dp[i][j]=min(dp[i][j],risk[k][i]+dp[k][i-times[k][i]]);
				}
			}
		}
		cout<<dp[n][m]<<endl;
	}
}
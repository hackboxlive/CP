#include <bits/stdc++.h>
using namespace std;
int height[510];
int dp[510][510];
int main()	{
	int n,k,t;
	scanf("%d %d %d",&n,&k,&t);
	for(int i=1;i<=n;i++)	{
		scanf("%d",&height[i]);
	}
	for(int i=1;i<=n;i++)	{
		for(int j=1;j<=k;j++)	{
			int minn=1e9;
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			for(int k=i;k>0 && i-k<t;k--)	{
				minn=min(minn,height[k]);
				dp[i][j]=max(dp[i][j],dp[k-1][j-1]+(i-k+1)*minn);
			}
		}
	}
	printf("%d\n",dp[n][k]);
	return 0;
}
#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
int dp[110][110];
int arr[110];
int solve(int n)	{
	memset(dp,0,sizeof(dp));
	for(int i=3;i<n+1;i++)	{
		for(int j=0;j+i<=n;j++)	{
			int k=i+j-1;
			dp[j][k]=INF;
			for(int t=j+1;t<k;t++)	{
				dp[j][k]=min(dp[j][k],dp[t][k]+dp[j][t]+arr[k]-arr[j]-2);
			}
		}
	}
	return dp[0][n-1];
}
int main()	{
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++)	{
		int p,q;
		scanf("%d%d",&p,&q);
		arr[0]=0;
		for(int i=1;i<=q;i++)	{
			scanf("%d",&arr[i]);
		}
		arr[q+1]=p+1;
		printf("Case #%d: %d\n",tt,solve(q+2));
	}
	return 0;
}
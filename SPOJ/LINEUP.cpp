#include <bits/stdc++.h>
using namespace std;
int mat[11][11];
int dp[12][3000];
int solve(int player,int position)	{
	if(player==11)	{
		return 0;
	}
	if(dp[player][position]!=-1)	{
		return dp[player][position];
	}
	int ans,maxans=-1000000000;
	for(int i=0;i<11;i++)	{
		if(mat[player][i] && !(position&(1<<i)))	{
			ans=mat[player][i]+solve(player+1,position|(1<<i));
			maxans=max(maxans,ans);
		}
	}
	return dp[player][position]=maxans;
}
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		for(int i=0;i<11;i++)	{
			for(int j=0;j<11;j++)	{
				scanf("%d",&mat[i][j]);
			}
		}
		memset(dp,-1,sizeof(dp));
		int ans=solve(0,0);
		printf("%d\n",ans);
	}
	return 0;
}
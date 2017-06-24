#include <bits/stdc++.h>
using namespace std;
int mat[11][11];
long long dp[21][1<<21];
int n;
inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	if(ch=='-')
		sign=-1,ch=getchar();
	else
		sign=1;

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	N*=sign;
	return;
}
long long solve(int player,int position)	{
	if(player==n)	{
		return dp[player][position]=1;
	}
	if(dp[player][position]!=-1)	{
		return dp[player][position];
	}
	long long ans=0;
	for(int i=0;i<n;i++)	{
		if(mat[player][i] && !(position&(1<<i)))	{
			ans+=solve(player+1,position|(1<<i));
		}
	}
	return dp[player][position]=ans;
}
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
//		scanf("%d",&n);
		Input(n);
		for(int i=0;i<n;i++)	{
			for(int j=0;j<n;j++)	{
//				scanf("%d",&mat[i][j]);
				Input(mat[i][j]);
			}
		}
		memset(dp,-1,sizeof(dp));
		long long ans=solve(0,0);
		printf("%lld\n",ans);
	}
	return 0;
}
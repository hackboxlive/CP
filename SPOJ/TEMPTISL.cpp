#include <bits/stdc++.h>
using namespace std;
long long int dp[55][55];
int main()	{
	int n,k,a,b;
	while(true)	{
		scanf("%d%d",&n,&k);
		if(n==-1 && k==-1)	{
			return 0;
		}
		scanf("%d%d",&a,&b);
		for(int i=0;i<n;i++)	{
			dp[0][i]=0;
		}
		dp[0][0]=1;
		for(int i=1;i<=k;i++)	{
			for(int j=0;j<n;j++)	{
				dp[i][j]=dp[i-1][(int)abs(j-1)]+dp[i-1][(int)abs(n-1-j)];
			}
		}
		printf("%lld\n",dp[k][(int)abs(a-b)]);
	}
	return 0;
}

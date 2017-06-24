#include <bits/stdc++.h>
#define INF 1e8
using namespace std;
long long int dp[2100][2100];
int arr[2100];
long long int solve(int l,int r,int days)	{
//	cout<<l<<" "<<r<<endl;
	if(l>r)	{
		return INF;
	}
	if(l==r)	{
		return days*arr[l];
	}
	if(dp[l][r]!=-1)	{
		return dp[l][r];
	}
	dp[l][r] = max(arr[l]*days+solve(l+1,r,days+1),arr[r]*days+solve(l,r-1,days+1));
	return dp[l][r];
}
int main()	{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)	{
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<n;i++)	{
		for(int j=0;j<n;j++)	{
			dp[i][j]=-1;
		}
	}
	printf("%lld\n",solve(0,n-1,1));
	return 0;
}
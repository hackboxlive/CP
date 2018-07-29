#include <bits/stdc++.h>
using namespace std;

int a[1010],c[1010];
int dp[1010];

int main()	{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)	{
		cin>>c[i];
	}
	dp[0]=0;
	int minn;
	for(int i=1;i<=n;i++)	{
		minn=dp[i-1]+a[i];
		for(int j=0;j<k && i-j>=1;j++)	{
			minn=min(minn,dp[i-j-1]+c[i-j]);
		}
		dp[i]=minn;
	}
	cout<<dp[n]<<endl;
	return 0;
}
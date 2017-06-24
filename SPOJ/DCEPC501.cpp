#include <bits/stdc++.h>
using namespace std;
long long int dp[100100];
int arr[100100];
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)	{
			scanf("%d",&arr[i]);
			dp[i]=0LL;
		}
		dp[n]=dp[n+1]=dp[n+2]=0LL;
		if(n<=3)	{
			long long int sum=0;
			for(int i=n-1;i>=0;i--)	{
				sum=sum+arr[i];
				dp[i]=sum;
			}
			printf("%lld\n",dp[0]);
			continue;
		}
		long long int sum=0;
		for(int i=n-1;i>=n-3;i--)	{
			sum+=arr[i];
			dp[i]=sum;
		}
		for(int i=n-4;i>=0;i--)	{
			dp[i]=max(arr[i]+dp[i+2],max(arr[i]+arr[i+1]+dp[i+4],arr[i]+arr[i+1]+arr[i+2]+dp[i+6]));
		}
		printf("%lld\n",dp[0]);
	}
	return 0;
}
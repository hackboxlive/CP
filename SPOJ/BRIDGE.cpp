#include <bits/stdc++.h>
using namespace std;
pair<int,int> arr[1100];
int dp[1100];
bool comp(const pair<int,int> &p1,const pair<int,int> &p2)	{
	if(p1.first!=p2.first)	{
		return p1.first<p2.first;
	}
	return p1.second<p2.second;
}
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)	{
			scanf("%d",&arr[i].first);
		}
		for(int i=0;i<n;i++)	{
			scanf("%d",&arr[i].second);
		}
		sort(arr,arr+n,comp);
		dp[0]=1;
		int lis_length=1;
		for(int i=1;i<n;i++)	{
			dp[i]=1;
			for(int j=0;j<i;j++)	{
				if(arr[i].second>=arr[j].second)	{
					dp[i]=max(dp[i],1+dp[j]);
				}
			}
			if(dp[i]>lis_length)	{
				lis_length=dp[i];
			}
		}
		printf("%d\n",lis_length);
	}
	return 0;
}
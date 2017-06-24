#include <bits/stdc++.h>
using namespace std;
long long int dp[210][210];
int arr1[210],arr2[210];
int m,n;
long long int solve(int id,int rem)	{
//	cout<<"In solve with "<<id<<" and "<<rem<<endl;
	long long int ssum=0;
	if(rem<arr1[id])	{
		return 0;
	}
	if(id==m && rem<=arr2[id])	{
		dp[id][rem]=1;
		return 1;
	}
	if(id==m && rem>arr2[id])	{
		return 0;
	}
	if(dp[id][rem]!=-1)	{
		return dp[id][rem];
	}
	for(int i=arr1[id];i<=arr2[id];i++)	{
		ssum+=solve(id+1,rem-i);
//		ssum=ssum+dp[id][i];
	}
	dp[id][rem]=ssum;
	return ssum;
}
int main()	{
//	int m,n;
	int t;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d%d",&m,&n);
		for(int i=0;i<210;i++)	{
			for(int j=0;j<210;j++)	{
				dp[i][j]=-1;
			}
		}
		for(int i=1;i<=m;i++)	{
			scanf("%d%d",&arr1[i],&arr2[i]);
		}
		long long int ssumm=0;
		ssumm=solve(1,n);
//		for(int i=1;i<=m;i++)	{
//			for(int j=1;j<=n;j++)	{
//				cout<<dp[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		cout<<ssumm%1000000007<<endl;
//		scanf("%d%d",&m,&n);
	}
	return 0;
}
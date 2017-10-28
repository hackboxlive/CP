#include <bits/stdc++.h>
using namespace std;
pair<int,int> arr[100100];
int w[100100];
pair<double,long long> dp[100100];
int u[100100];
double get_dist(int i,int j)	{
	long long x=arr[i].first-arr[j].first;
	x*=x;
	long long y=arr[i].second-arr[j].second;
	y*=y;
	x=x+y;
	return sqrt(x);
}
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)	{
			cin>>arr[i].first>>arr[i].second;
		}
		for(int i=0;i<n;i++)	{
			cin>>w[i];
		}
		dp[0].first=0.0;
		dp[0].second=w[0];
		u[0]=1;
		double num,div;
		long long den;
		double ans=0.0;
		for(int i=1;i<n;i++)	{
			double maxx=-1.0;
			double maxxn,maxxd;
			for(int j=0;j<i;j++)	{
				if(u[j]==1)	{
					double num=dp[j].first-get_dist(j,0);
					num+=(get_dist(0,i)+get_dist(j,i));
					den=dp[j].second+w[i];
					div=num/den;
					if(div>ans)	{
						ans=div;
					}
					if(maxx<div)	{
						maxx=div;
						maxxn=num;
						maxxd=den;
					}
				}
			}
			dp[i].first=maxxn;
			dp[i].second=maxxd;
		}
		printf("%.11lf\n",ans);
		}
	return 0;
}
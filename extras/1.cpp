#include <bits/stdc++.h>
using namespace std;

long long arr[100100];
int store[100100][10];
int dp[100100];
vector<pair<int,int> > digits[10];

int main()	{
	int n;
	long long temp;
	int pos,cur;
	cin>>n;
	for(int i=1;i<=n;i++)	{
		cin>>arr[i];
		int cnt[10]={0};
		temp=arr[i];
		while(temp>0)	{
			cnt[temp%10]=1;
			temp/=10;
		}
		for(int j=0;j<10;j++)	{
			if(cnt[j]==1)	{
				digits[j].push_back(make_pair(arr[i],i));
				store[i][j]=digits[j].size()-1;
			}
		}
	}
	dp[0]=0;
	dp[1]=1;
	int max_dp=1;
	for(int i=2;i<=n;i++)	{
		temp=arr[i];
		int cnt[10]={0};
		while(temp>0)	{
			cnt[temp%10]=1;
			temp/=10;
		}
		cur=0;
		for(int j=0;j<10;j++)	{
			if(cnt[j]==1)	{
				if(store[i][j]==0)	{
					cur=max(cur,1);
				}
				else	{
					cur=max(cur,1+dp[digits[j][store[i][j]-1].second]);
				}
			}
		}
		dp[i]=cur;
		max_dp=max(max_dp,cur);
	}
	cout<<max_dp<<endl;
	return 0;
}
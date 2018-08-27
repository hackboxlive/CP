#include <bits/stdc++.h>
using namespace std;

int arr[707];
int old_dp[707][707];
int new_dp[707][707];
int prev_ctr[707];
int main()	{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
	}
	dp[0][0]=arr[0];
	int prev=1;
	prev_ctr[0]=1;
	int cur;
	for(int i=1;i<n;i++)	{
		cur=0;
		if(old_dp[i-1][0])
		for(int j=0;j<prev;j++)	{

		}
	}
	return 0;
}
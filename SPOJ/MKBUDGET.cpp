#include <bits/stdc++.h>
using namespace std;
int req[25];
int dp[25][50];
int main()	{
	int n;
	cin>>n;
	int t=1;
	while(n!=0)	{
		int hire,sal,sev,mxem=-1;
		cin>>hire>>sal>>sev;
		for(int i=0;i<n;i++)	{
			cin>>req[i];
			mxem=max(mxem,req[i]);
		}
		for(int i=req[0];i<=mxem;i++)	{
			dp[0][i]=i*(sal+hire);
		}
		for(int i=1;i<n;i++)	{
			for(int j=req[i];j<=mxem;j++)	{
				int temp,minans=1e9;
				for(int k=req[i-1];k<=mxem;k++)	{
					temp=dp[i-1][k]+j*sal;
					if(k<j)	{
						temp+=(j-k)*hire;
					}
					else	{
						temp+=(k-j)*sev;
					}
					minans=min(minans,temp);
				}
				dp[i][j]=minans;
			}
		}
		int minn=1e9;
		for(int i=req[n-1];i<=mxem;i++)	{
			minn=min(minn,dp[n-1][i]);
		}
		cout<<"Case "<<t<<", cost = $"<<minn<<endl;
		cin>>n;
		t++;
	}
	return 0;
}
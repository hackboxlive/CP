#include <bits/stdc++.h>
using namespace std;
double dp[150][11][310];
double solve(int balls,int wickets,int left)	{
	if(dp[balls][wickets][left]!=-1)	{
		return dp[balls][wickets][left];
	}
	if(left<=0)	{
		return dp[balls][wickets][left]=100.0;
	}
	if(wickets==0 || balls==0)	{
		return dp[balls][wickets][left]=0.0;
	}
	dp[balls][wickets][left]=solve(balls-1,wickets,left);
	dp[balls][wickets][left]+=solve(balls-1,wickets,left-1);
	dp[balls][wickets][left]+=solve(balls-1,wickets,left-2);
	dp[balls][wickets][left]+=solve(balls-1,wickets,left-3);
	dp[balls][wickets][left]+=solve(balls-1,wickets,left-4);
	dp[balls][wickets][left]+=solve(balls-1,wickets,left-5);
	dp[balls][wickets][left]+=solve(balls-1,wickets,left-6);
	dp[balls][wickets][left]+=solve(balls,wickets,left-1);
	dp[balls][wickets][left]+=solve(balls,wickets,left-1);
	dp[balls][wickets][left]+=solve(balls-1,wickets-1,left);
	dp[balls][wickets][left]/=10.0;
	return dp[balls][wickets][left];
}
int main()	{
	int t;
	cin>>t;
	double bl;
	double overs;
	string score;
	int target;
	int cur;
	int balls;
	int wkt;
	for(int i=0;i<150;i++)	{
		for(int j=0;j<11;j++)	{
			for(int k=0;k<310;k++)	{
				dp[i][j][k]=-1.0;
			}
		}
	}
	while(t--)	{
		cin>>overs>>score>>target;
		cur=0;
		wkt=0;
		int i;
		for(i=0;score[i]!='/';i++)	{
			cur=cur*10+(score[i]-'0');
		}
		i++;
		for(;i<score.length();i++)	{
			wkt=wkt*10+(score[i]-'0');
		}
		int left=target-cur;
		balls=((int)overs)*6;
		bl=(double)overs-(int)overs;
//		cout<<bl<<endl;
		bl=bl*10;
		balls+=bl;
		balls=120-balls;
//		cout<<balls<<" "<<10-wkt<<" "<<left<<endl;
//		cout<<solve(balls,10-wkt,left)<<endl;
		double ans=solve(balls,10-wkt,left);
		ans=ans*100;
		int intans=(int)ans;
		ans=intans;
		ans=ans/100;
		printf("%.2lf\n",ans);
	}
	return 0;
}
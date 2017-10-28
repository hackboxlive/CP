#include <bits/stdc++.h>
using namespace std;
double p[1010];
double dp[1010][1010];
long long get_one(long long l,long long r)	{
	long long lo=1,hi=1;
	long long ans=0;
	long long x,y;
	for(int dig=1;dig<=19;dig++)	{
		x=max(l,lo);
		y=min(r,hi);
		if(x<=y)	{
			ans+=(y-x+1);
		}
		lo*=10;
		hi=lo*2-1;
	}
	return ans;
}
int main()	{
	int n;
	cin>>n;
	long long l,r;
	int k;
	long long one,zero;
	for(int i=1;i<=n;i++)	{
		cin>>l>>r;
		one=get_one(l,r);
//		cout<<one<<endl;
		p[i]=((double)one*1.0)/(r-l+1);
//		cout<<p[i]<<endl;
	}
	cin>>k;
	dp[0][0]=1.0;
	for(int i=1;i<=n;i++)	{
		for(int j=0;j<=i;j++)	{
			if(j!=0)	{
				dp[i][j]=p[i]*dp[i-1][j-1];
			}
			if(j!=i)	{
				dp[i][j]+=(1-p[i])*dp[i-1][j];
			}
		}
	}

	// for(int i=1;i<=n;i++)	{
	// 	for(int j=0;j<=i;j++)	{
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	double ans=0.0;
	for(int i=n;i>=0;i--)	{
		if(i*100<k*n)	{
			break;
		}
		ans+=dp[n][i];
	}
//	cout<<ans<<endl;
	printf("%.10lf\n",ans);
	return 0;
}
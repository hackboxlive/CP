#include <bits/stdc++.h>
using namespace std;
const long long MODD=1e9+7;
struct node	{
	long long g,b;
}arr[3010];
long long c;
long long dp[3030][3030];
bool corrupt[3030][3030];
long long solve(long long good,long long bad)	{
	if(dp[good][bad]!=-1)	{
		return dp[good][bad];
	}
	if(corrupt[good][bad])	{
		return dp[good][bad]=0;
	}
	if(good==0)	{
		return dp[good][bad]=0;
	}
	if(good==1 && bad==0)	{
		if(corrupt[good][bad])	{
			return dp[good][bad]=0;
		}
		return dp[good][bad]=1;
	}
	if(bad==0)	{
		return dp[good][bad]=solve(good-1,bad);
	}
	long long ans=0;
	if(!corrupt[good][bad-1] && good-bad+1>c)	{
		ans+=solve(good,bad-1);
		ans%=MODD;
	}
	if(!corrupt[good-1][bad])	{
		ans+=solve(good-1,bad);
		ans%=MODD;
	}
	return dp[good][bad]=ans;
}
int main()	{
	long long p,q,m;
	cin>>p>>q>>c>>m;
	for(int i=0;i<m;i++)	{
		cin>>arr[i].g>>arr[i].b;
		if(arr[i].g>2002 || arr[i].b>2002)	{
			continue;
		}
		corrupt[arr[i].g][arr[i].b]=true;
	}
	memset(dp,-1,sizeof(dp));
	cout<<solve(p,q)<<endl;
	return 0;
}
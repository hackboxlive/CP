#include <bits/stdc++.h>
using namespace std;
const long long MODD=1e9+7;
struct node	{
	long long g,b;
}arr[3010];
long long c;
long long dp[3030][3030];
bool corrupt[3030][3030];
/*long long solve(long long good,long long bad)	{
	//cout<<"At "<<good<<" "<<bad<<endl;
	//getchar();
	if(good==0)	{
		return dp[good][bad]=0;
	}
	if(bad==0)	{
		return dp[good][bad]=1;
	}
	if(dp[good][bad]!=-1)	{
		return dp[good][bad];
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
}*/
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
	if(corrupt[p][q])	{
		cout<<"0\n";
		return 0;
	}
	//memset(dp,-1,sizeof(dp));
	//cout<<solve(p,q)<<endl;
	for(int i=0;i<=q;i++)	{
		dp[0][i]=0;
	}
	for(int i=c+1;i<=p;i++)	{
		dp[i][0]=1;
	}
	for(int i=1;i<=p;i++)	{
		for(int j=1;j<=q;j++)	{
			dp[i][j]=0;
			if(!corrupt[i][j-1] && i-j+1>c)	{
				dp[i][j]+=dp[i][j-1];
				dp[i][j]%=MODD;
			}
			if(!corrupt[i-1][j])	{
				dp[i][j]+=dp[i-1][j];
				dp[i][j]%=MODD;
			}
		}
	}
	cout<<dp[p][q]<<endl;
	// for(int i=0;i<=p;i++)	{
	// 	for(int j=0;j<=q;j++)	{
	// 		cout<<dp[i][j]<<"\t";
	// 	}
	// 	cout<<endl;
	// }
	return 0;
}
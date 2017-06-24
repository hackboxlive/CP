#include <bits/stdc++.h>
using namespace std;
const long long mod=(1e9)+9;
vector<vector<int> > cond(1010);
long long dp[1010][1010];
void precompute(int lim)	{
	set<int> s;
	set<int>::iterator it;
	for(int i=1;i<=lim;i++)	{
		for(int j=1;j<=lim;j++)	{
			if(j%i==0)	{
				s.insert(j);
			}
			if(i%j==0)	{
				s.insert(j);
			}
		}
		// cout<<"For i = "<<i<<endl;
		for(it=s.begin();it!=s.end();it++)	{
			// cout<<"vals are = "<<*it<<" ";
			cond[i].push_back(*it);
		}
		s.clear();
		// cout<<endl;
	}
	return;
}
int main()	{
	int n,k;
	scanf("%d %d",&n,&k);
	precompute(k);
	for(int i=1;i<=k;i++)	{
		dp[1][i]=1;
	}
	long long ans;
	for(int i=2;i<=n;i++)	{
		for(int j=1;j<=k;j++)	{
			ans=0;
			for(int it=0;it<cond[j].size();it++)	{
				// cout<<"val= "<<cond[j][it]<<endl;
				ans=(ans+dp[i-1][cond[j][it]]);
				// cout<<ans<<endl;
				ans=ans%mod;
			}
			// cout<<i<<" "<<j<<" "<<ans<<endl;
			dp[i][j]=ans;
		}
	}
	ans=0;
	for(int i=1;i<=k;i++)	{
		ans=(ans+dp[n][i]);
		ans=ans%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
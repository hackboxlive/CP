#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > baby;
vector<pair<int,int> > valid;
int n;
int dp[20][1<<20];
void solve(int src,int mask)	{
	if(dp[src][mask]!=-1)	{
		return;
	}
	for(int i=0;i<n;i++)	{
		if(!(mask & (1<<i)))	{
			
		}
	}
}
int main()	{
	int col;
	scanf("%d",&n);
	while(n)	{
		for(int i = 1 ; i <= n ; i++)	{
			scanf("%d",&col);
			baby.push_back(make_pair(i,col));
		}
		for(int i = 1 ; i <= n ; i++)	{
			scanf("%d",&col);
			valid.push_back(make_pair(i,col));
		}
		solve(,0);
	}
}
#include <bits/stdc++.h>
using namespace std;
int winner[110][110];
int dp[110][110];
int n;
vector<int> candidates;
int meet(int x,int y)	{
	if(x==y || (x+1)%n==y)	{
		dp[x][y]=1;
		return 1;
	}
	if(dp[x][y]!=-1)	{
		return dp[x][y];
	}
	for(int i=(x+1)%n;i!=y;i=(i+1)%n)	{
		if(winner[x][i]==1 || winner[y][i]==1)	{
			if(meet(x,i)==1 && meet(i,y))	{
				dp[x][y]=1;
				return 1;
			}
		}
	}
	dp[x][y]=0;
	return 0;
}
int main()	{
	int t;
	string s;
	scanf("%d",&t);
	while(t--)	{
		candidates.clear();
		scanf("%d",&n);
		for(int i=0;i<n;i++)	{
			cin>>s;
			for(int j=0;j<n;j++)	{
				winner[i][j]=(s[j]=='1')?1:0;
			}
		}
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<n;i++)	{
			for(int j=0;j<n;j++)	{
				if(i==j || winner[i][j]==0)	{
					continue;
				}
				if(meet(i,j)==1 && meet(j,i)==1)	{
					candidates.push_back(i);
					break;
				}
			}
		}
		printf("%d\n",(int)candidates.size());
		for(int i=0;i<candidates.size();i++)	{
			printf("%d\n",candidates[i]+1);
		}
	}
	return 0;
}
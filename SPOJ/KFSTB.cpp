#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g(10100);
int visited[10100];
vector<int> nodes;
long long int dp[10100];
void topological_sort(int src)	{
	visited[src]=1;
	for(int i=0;i<g[src].size();i++)	{
		if(visited[g[src][i]]==0)	{
			topological_sort(g[src][i]);
		}
	}
	nodes.push_back(src);
	return;
}
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		int n,m,src,dest,u,v;
		scanf("%d%d%d%d",&n,&m,&src,&dest);
		for(int i=0;i<m;i++)	{
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
		}
		memset(visited,0,sizeof(visited));
		topological_sort(src);
		int len=nodes.size();
		memset(dp,0,sizeof(dp));
		dp[src]=1;
		for(int i=len-1;i>=0;i--)	{
			u=nodes[i];
			for(int j=0;j<g[u].size();j++)	{
				dp[g[u][j]]=(dp[g[u][j]]+dp[u])%1000000007;
			}
		}
		printf("%lld\n",dp[dest]);
		nodes.clear();
		for(int i=1;i<=n;i++)	{
			g[i].clear();
		}
	}
	return 0;
}
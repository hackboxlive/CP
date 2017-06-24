#include <bits/stdc++.h>
#include <vector>
#define ll long long
#define MAX 5002
using namespace std;
 
 
ll cost[MAX][MAX], H[MAX], C[MAX], dp[MAX];
int depth[MAX];
vector<int> *adj;
 
using namespace std;
 
//calculate h
void calculateheight(int u, int p, int l, int &h)
{
	depth[u] = l;
	h = max(h, l);
	for(int i = 0; i < adj[u].size(); i++)
		if(adj[u][i] != p)
			calculateheight(adj[u][i], u, l + 1, h);
}
 
//cost[u][v] stores the cost from u to v when started painting from v
void calculatecost(int u, int p, vector<int>&path, int h)
{
	path.push_back(u);
	for(int i = path.size() - 1; i >= 0; i--)
	{
		cost[path[i]][u] = 0;
		if(i + 1 < path.size())
			cost[path[i]][u] = cost[path[i + 1]][u];
		cost[path[i]][u] += (C[u]*(h - depth[path[i]])) + (C[u] * C[u]);
	}
	for(int i = path.size() - 1; i >= 0; i--)
		cost[path[i]][u] -= H[u];
	for(int i = 0; i < adj[u].size(); i++)
		if(adj[u][i] != p)
			calculatecost(adj[u][i], u, path, h);
	path.pop_back();
}
 
//fuction to caluclate answer for subtree roted at u
void rootat(int r, int u, int p, ll curr, ll &ans)
{
	ll child = 0;
	for(int i = 0; i < adj[u].size(); i++)
		if(adj[u][i] != p)
			child += dp[adj[u][i]];
	ans = min(ans, child + curr + cost[r][u]);
	for(int i = 0; i < adj[u].size(); i++)
		if(adj[u][i] != p)
			rootat(r, adj[u][i], u, curr + child - dp[adj[u][i]], ans);
	
}
 
//healscreate dp[i] from bottoms up manner
void calculatedp(int u, int p)
{
	for(int i = 0; i < adj[u].size(); i++)
		if(adj[u][i] != p)
			calculatedp(adj[u][i], u);
	ll ans = LLONG_MAX;
	rootat(u, u, p, 0, ans);
	dp[u] = ans;
}
 
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, u, v;
		scanf("%d", &n);
		adj = new vector<int>[n + 1];
		for(int i = 1; i <= n; i++)
			cin >> H[i] >> C[i];
		for(int i = 1; i <= n; i++)
			dp[i] = 0;
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= n; j++)
				cost[i][j] = 0;
		for(int i = 0; i < n - 1; i++)
		{
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);		
		}
		int h = 0;
		vector<int>path;
		calculateheight(1, 0, 0, h);
		calculatecost(1, 0, path, h);
		calculatedp(1, 0);
		printf("%lld\n", dp[1]);
	}
}
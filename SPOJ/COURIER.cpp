#include <bits/stdc++.h>
using namespace std;
int n,b,tot;
const long long int inf = 1e18;
long long int graph[110][110];
long long int dist[110][110];
long long int dp[110][5000];
vector<pair<long long int,long long int> > package;
void floyd_warshall(void)	{
	for(int k = 1 ; k <= n ; k++)	{
		for(int i = 1 ; i <= n ; i++)	{
			for(int j = 1 ; j <= n ; j++)	{
				if(dist[i][j] > dist[i][k] + dist[k][j])	{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	return;
}
void solve(int src,int mask)	{
	if(dp[src][mask] != -1)	{
		return;
	}
	long long int ansmin = inf;
	long long int ans;
	int f = 0;
	for(int i = 0 ; i < tot ; i++)	{
		if(!(mask & (1<<i)))	{
			f = 1;
			solve(package[i].second,mask | (1<<i));
			ans = dist[src][package[i].first] + dist[package[i].first][package[i].second] + dp[package[i].second][mask | (1<<i)];
			if(ans < ansmin)	{
				ansmin = ans;
			}
		}
	}
	if(f == 0)	{
		dp[src][mask] = dist[src][b];
		return;
	}
	dp[src][mask] = ansmin;
	return;
}
int main(void)	{
	int t,m,u,v,w,z;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d %d %d",&n,&m,&b);
		for(int i = 1 ; i <= n ; i++)	{
			for(int j = 0 ; j < 5000 ; j++)	{
				dp[i][j] = -1;
			}
		}
		package.clear();
		for(int i = 1 ; i <= n ; i++)	{
			for(int j = 1 ; j <= n ; j++)	{
				dist[i][j] = graph[i][j] = (i == j) ? 0 : inf ;
			}
		}
		for(int i = 0 ; i < m ; i++)	{
			scanf("%d %d %d",&u,&v,&w);
			dist[u][v] = dist[v][u] = graph[u][v] = graph[v][u] = w;
		}
		floyd_warshall();
		scanf("%d",&z);
		tot = 0;
		for(int i = 0 ; i < z ; i++)	{
			scanf("%d %d %d",&u,&v,&w);
			for(int j = 0 ; j < w ; j++)	{
				package.push_back(make_pair(u,v));
				tot++;
			}
		}
		solve(b,0);
		printf("%lld\n",dp[b][0]);
	}
	return 0;
}
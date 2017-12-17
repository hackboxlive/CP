#include <bits/stdc++.h>
using namespace std;
const int offset = 35000;
const int MAXX = 80800;
int finalflow;
bool done;
vector<int> graph[MAXX];
vector<pair<int, int> > res[MAXX];
bool vis[MAXX];
void build(int src)	{
	vis[src] = true;
	for(int i = 0; i < graph[src].size(); i++)	{
		if(!vis[graph[src][i]])	{
			res[src].push_back(make_pair(graph[src][i], 1));
			res[graph[src][i]].push_back(make_pair(src, 0));
			build(graph[src][i]);
		}
	}
}
int dfs(int src, int flow)	{
	vis[src] = true;
	if(src == 2)	{
		done = true;
		return;
	}
	for(int i = 0; i < res[src].size(); i++)	{
		if(!vis[res[src][i].first] && res[src][i].second)	{
			dfs(res[src][i].first, min(flow, res[src][i].second));
			if(done)	{
				//
			}
		}
	}
}
int ford_fulkerson()	{
	int ans = 0;
	while(true)	{
		done = false;
		for(int i = 0; i < MAXX; i++)	{
			vis[i] = false;
		}
		dfs(0, MAXX);
		if(flow == 0)	{
			break;
		}
		ans += flow;
	}
	return ans;
}
int main()	{
	int t,n,m,u,v;
	cin>>t;
	while(t--)	{
		cin >> n >> m;
		if(n < 3)	{
			cout << "NO\n";
			continue;
		}
		graph[0].push_back(1);
		graph[0].push_back(3);
		graph[1].push_back(offset+1);
		for(int i = 3; i < MAXX; i++)	{
			graph[i].clear();
			graph[i].push_back(offset+i);
			vis[i] = false;
		}
		for(int i = 0; i < m; i++)	{
			cin >> u >> v;
			if(u == 2)	{
				graph[offset + v].push_back(u);
			}
			else if(v == 2)	{
				graph[offset + u].push_back(v);
			}
			else	{
				graph[offset + u].push_back(v);
				graph[offset + v].push_back(u);
			}
		}
		build(0);
		if(ford_fulkerson() == 2)	{
			cout << "YES\n";
		}
		else	{
			cout << "NO\n";
		}
	}
	return 0;
}
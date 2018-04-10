#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > graph[100100];
vector<pair<int,int> > tree[100100];
vector<int> root;
struct node	{
	int u,v,p;
}edges[100100];
int vis[100100];
void dfs_forest(int src)	{
	for(int i=0;i<graph[src].size();i++)	{
		if(vis[graph[src][i].first]!=1)	{
			tree[src].push_back(make_pair(graph[src][i].first,graph[src][i].second));
			edges[graph[src][i].second].p=1;
			dfs_forest(graph[src][i].first);
		}
	}
}
int main()	{
	int n,m,u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)	{
		cin>>u>>v;
		graph[u].push_back(make_pair(v,i+1));
		graph[v].push_back(make_pair(u,i+1));
		edges[i+1].u=u;
		edges[i+1].v=v;
		edges[i+1].p=0;
	}
	for(int i=1;i<=n;i++)	{
		if(!vis[i])	{
			root.push_back(i);
			dfs_forest(i);
		}
	}
	for(int i=1;i<=m;i++)	{

	}
	return 0;
}
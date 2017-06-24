#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > a(500500);
vector<vector<int> > b(500500);
vector<vector<int> > graph(500500);
bool vis[500500];
void remove_backedge1(int src)	{
	vis[src]=true;
	for(int i=0;i<a[src].size();i++)	{
		if(!vis[a[src][i]])	{
			graph[src].push_back(a[src][i]);
			remove_backedge1(a[src][i]);
		}
	}
}
void remove_backedge2(int src)	{
	vis[src]=true;
	for(int i=0;i<b[src].size();i++)	{
		if(!vis[b[src][i]])	{
			graph[src].push_back(b[src][i]);
			remove_backedge1(b[src][i]);
		}
	}
}
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		cin>>n;
		for(int i=0;i<n-1;i++)	{
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		for(int i=0;i<n-1;i++)	{
			cin>>u>>v;
			b[u].push_back(v);
			b[v].push_back(u);
		}
		remove_backedge1(1);
		remove_backedge2(1);
		dfs(1);
	}
	return 0;
}
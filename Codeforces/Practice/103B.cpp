#include <bits/stdc++.h>
using namespace std;
vector<int> g[101];
int vis[101];
void dfs(int src)	{
	if(vis[src]==1)	{
		return;
	}
	vis[src]=1;
//	cout<<src<<" "<<par<<" here "<<vis[src]<<endl;
	for(int i=0;i<g[src].size();i++)	{
		dfs(g[src][i]);
	}
}
int main()	{
	int n,m,u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	int f=0;
	for(int i=1;i<=n;i++)	{
		if(vis[i]==0)	{
			f=1;
		}
	}
	if(f==0 && n==m)	{
		cout<<"FHTAGN!\n";
	}
	else	{
		cout<<"NO\n";
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g(10000);
vector<vector<int> > grev(10000);
vector<vector<int> > gtot(10000);
int visited[10000];
int finish[10000];
bool graph_broken;
void dfs_check(int src)	{
	visited[src]=1;
	for(int i=0;i<gtot[src].size();i++)	{
		if(visited[gtot[src][i]]==0)	{
			dfs_check(gtot[src][i]);
		}
	}
	return;
}
void dfs_reverse(int src)	{
	visited[src]=1;
	for(int i=0;i<grev)
}
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		int n,m,src,dest;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++)	{
			scanf("%d%d",&dest,&src);
			g[src].push_back(dest);
			grev[dest].push_back(src);
			gtot[src].push_back(dest);
			gtot[dest].push_back(src);
		}
		memset(visited,0,(n+1)*sizeof(int));
		graph_broken=false;
		dfs_check(1);
		for(int i=2;i<=n;i++)	{
			if(visited[i]==0)	{
				graph_broken=true;
			}
		}
		for(int i=1;i<=n;i++)	{
			if(visited[i]==0)	{
				dfs_reverse(i);
			}
		}
	}
}
#include <bits/stdc++.h>
using namespace std;
pair<int,int> cost[1010];
int ucost[1010];
bool rem[1010];
vector<vector<int> > graph(1010);
int main()	{
	int n,m,u,v;
	cin>>n>>m;
	for(int i=1;i<=n;i++)	{
		cin>>cost[i].first;
		cost[i].second=i;
		ucost[i]=cost[i].first;
	}
	for(int i=0;i<m;i++)	{
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int ans=0;
	sort(cost+1,cost+n+1);
	for(int i=n;i>=1;i--)	{
		u=cost[i].second;
		rem[u]=true;
		for(int j=0;j<graph[u].size();j++)	{
			v=graph[u][j];
			if(!rem[v])	{
				ans+=ucost[v];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
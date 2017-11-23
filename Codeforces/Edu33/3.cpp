#include <bits/stdc++.h>
using namespace std;
bool comp(const pair<long long,long long> &a,const pair<long long,long long> &b)	{
	return a.first<b.first;
}
long long vis[100100];
pair<long long,long long> coin[100100];
vector<long long> graph[100100];
void dfs(long long src)	{
	vis[src]=1;
	for(long long i=0;i<graph[src].size();i++)	{
		if(vis[graph[src][i]]==0)	{
			dfs(graph[src][i]);
		}
	}
}

int main()	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long n,m;
	long long u,v;
	cin>>n>>m;
	for(long long i=0;i<n;i++)	{
		cin>>u;
		coin[i+1].first=u;
		coin[i+1].second=i+1;
	}
	sort(coin+1,coin+n+1,comp);
	for(long long i=0;i<m;i++)	{
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	long long ans=0;
	for(long long i=1;i<=n;i++)	{
		if(vis[coin[i].second]==0)	{
			dfs(coin[i].second);
			ans+=coin[i].first;
		}
	}
	cout<<ans<<endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100];
vector<unsigned long long> cycles;
int sm[100];
map<pair<int,int>, bool> vis;
void dfs(int src, int v)	{
	if(sm[src]==-1)	{
		sm[src]=v;
	}
	else	{
		cycles.push_back(v-sm[src]);
	}
	int ch;
	for(int i=0;i<graph[src].size();i++)	{
		ch=graph[src][i];
		if(vis.find(make_pair(src,ch))->second==false)	{
			vis[make_pair(src,ch)]=true;
			vis[make_pair(ch,src)]=true;
			dfs(ch,sm[src]+1);
		}
	}
}
void clear(int n)	{
	for(int i=1;i<=n;i++)	{
		graph[i].clear();
	}
	cycles.clear();
	vis.clear();
	memset(sm,-1,sizeof(sm));
}
int main()	{
	int t,tt=1;
	scanf("%d",&t);
	while(t--)	{
		int n,e,u,v;
		scanf("%d %d",&n,&e);
		clear(n);
		for(int i=0;i<e;i++)	{
			scanf("%d %d",&u,&v);
			graph[u].push_back(v);
			graph[v].push_back(u);
			vis[make_pair(u,v)]=false;
			vis[make_pair(v,u)]=false;
		}
		dfs(1,0);
		// cycles.clear();
		// for(int i=0;i<40;i++)	{
		// 	cycles.push_back(3);
		// }
		unsigned long long ans=1LL;
		for(int i=0;i<cycles.size();i++)	{
			ans*=cycles[i];
		}
		// if(ans==1)	{
		// 	ans=0;
		// }
		printf("Case %d: %llu\n",tt,ans);
		++tt;
	}
	return 0;
}
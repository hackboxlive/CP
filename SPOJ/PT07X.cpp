#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g(100100);
int depth[100100];
int visited[100100];
void dfs(int src,int ctr)	{
	visited[src]=1;
	depth[src]=ctr;
	for(int i=0;i<g[src].size();i++)	{
		if(visited[g[src][i]]==0)	{
			dfs(g[src][i],ctr+1);
		}
	}
	return;
}
int main()	{
	int n;
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<n;i++)	{
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(visited,0,sizeof(visited));
	dfs(1,1);
	int odd_cnt=0,even_cnt=0;
	for(int i=1;i<=n;i++)	{
		if(depth[i]%2==1)	{
			odd_cnt++;
//			cout<<"Odd "<<i<<endl;
		}
		else	{
			even_cnt++;
//			cout<<"Even "<<i<<endl;
		}
	}
	printf("%d\n",min(odd_cnt,even_cnt));
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g(110);
vector<vector<int> > g2(110);
int color[110];
int check[110];
int dfs(int node)	{
	int child=0;
	for(int i=0;i<g[node].size();i++)	{
		child+=dfs(g[node][i]);
	}
	check[node]=child+1;
	return child+1;
}
int flag[110];
void dfs2(int node)	{
	for(int i=0;i<g[node].size();i++)	{
		dfs2(g[node][i]);
		if(color[node]!=color[g[node][i]] || flag[node]!=flag[g[node][i]])	{
			flag[node]=1;
		}
	}
	return;
}
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		memset(color,0,sizeof(color));
		memset(flag,0,sizeof(flag));
		memset(check,0,sizeof(check));
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)	{
			scanf("%d",&color[i]);
		}
		int src,dest;
		for(int i=1;i<n;i++)	{
			scanf("%d%d",&src,&dest);
			g[src].push_back(dest);
			g2[dest].push_back(src);
		}
		int root;
		for(int i=1;i<=n;i++)	{
			if(g2[i].size()==0)	{
				root=i;
			}
		}
		check[root]=dfs(root);
//		for(int i=1;i<=n;i++)	{
//			cout<<check[i]<<endl;
//		}
		dfs2(root);
		int maxm=-1;
//		for(int i=1;i<=n;i++)	{
//			cout<<"index "<<i<<"="<<color[i]<<endl;
//		}
		for(int i=1;i<=n;i++)	{
			if(flag[i]==0 && check[i]>maxm)	{
				maxm=check[i];
			}
		}
		cout<<maxm<<endl;
		for(int i=1;i<=n;i++)	{
			g[i].clear();
			g2[i].clear();
		}
	}
	return 0;
}
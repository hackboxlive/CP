#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int> > > tree(100100);
int parent[100100];
int level[100100];
int weight[100100];
int p[100100][]
void dfs_to_find_parent(int src)	{
	for(int i=0;i<tree[src].size();i++)	{
		if(vis[tree[src][i].first]==0)	{
			parent[tree[src][i].first]=src;
			level[tree[src][i].first]=level[src]+1;
			weight[tree[src][i].first]=tree[src][i].second;
			dfs_to_find_parent(tree[src][i].first);
		}
	}
	return;
}
void precompute()	{

}
int main()	{
	int n;
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<n;i++)	{
		scanf("%d %d",&u,&v,&w);
		tree[u].push_back(make_pair(v,w));
		tree[v].push_back(make_pair(u,w));
	}
	parent[1]=1;
	level[1]=0;
	weight[1]=0;
	dfs_to_find_parent(1);
	precompute();
	return 0;
}
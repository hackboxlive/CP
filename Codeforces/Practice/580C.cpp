#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > tree(100100);
int cats[100100];
int children[100100];
bool visited[100100];
int parent[100100];
int curr[100100];
int maxx[100100];
void parent_dfs(int src,int par)	{
	visited[src]=true;
	parent[src]=par;
	int num=0;
	for(int i=0;i<tree[src].size();i++)	{
		if(visited[tree[src][i]]==false)	{
			parent_dfs(tree[src][i],src);
			num++;
		}
	}
	children[src]=num;
	return;
}
void calc_dfs(int src)	{
	visited[src]=true;
	if(cats[parent[src]]==1 && cats[src]==1)	{
		curr[src]=curr[parent[src]]+1;
		maxx[src]=max(curr[src],maxx[parent[src]]);
	}
	else if(cats[parent[src]]==1 && cats[src]==0)	{
		curr[src]=0;
		maxx[src]=maxx[parent[src]];
	}
	else if(cats[parent[src]]==0 && cats[src]==1)	{
		curr[src]=1;
		maxx[src]=max(curr[src],maxx[parent[src]]);
	}
	else	{
		curr[src]=0;
		maxx[src]=maxx[parent[src]];
	}
	for(int i=0;i<tree[src].size();i++)	{
		if(visited[tree[src][i]]==false)	{
			calc_dfs(tree[src][i]);
		}
	}
	return;
}
int main()	{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)	{
		scanf("%d",&cats[i]);
	}
	int src,dest;
	for(int i=0;i<n-1;i++)	{
		scanf("%d%d",&src,&dest);
		tree[src].push_back(dest);
		tree[dest].push_back(src);
	}
	memset(visited,false,sizeof(visited));
	parent_dfs(1,1);
	memset(visited,false,sizeof(visited));
	visited[1]=true;
	if(cats[1]==1)	{
		curr[1]=1;
		maxx[1]=1;
	}
	else	{
		curr[1]=0;
		maxx[1]=0;
	}
	for(int i=0;i<tree[1].size();i++)	{
		calc_dfs(tree[1][i]);
	}
	int cnt=0;
	for(int i=1;i<=n;i++)	{
		if(children[i]==0)	{
			if(maxx[i]<=k)	{
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
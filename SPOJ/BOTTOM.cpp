#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g(5500);
vector<vector<int> > grev(5500);
int sink[5500];
int node[5500];
int visited[5500];
int finish[5500];
int tt;
int flag;
void dfs_reverse(int src)	{
	visited[src]=1;
	for(int i=0;i<grev[src].size();i++)	{
		if(visited[grev[src][i]]==0)	{
			dfs_reverse(grev[src][i]);
		}
	}
	finish[tt]=src;
	tt++;
	return;
}
void dfs(int src,int j)	{
	visited[src]=j;
//	cout<<src<<" ";
	for(int i=0;i<g[src].size();i++)	{
		if(visited[g[src][i]]!=0 && visited[g[src][i]]!=j)	{
			flag=1;
		}
		if(visited[g[src][i]]==0)	{
			dfs(g[src][i],j);
		}
	}
	return;
}
void getnodes(int src)	{
	visited[src]=1;
	for(int i=0;i<g[src].size();i++)	{
		if(visited[g[src][i]]==0)	{
			getnodes(g[src][i]);
		}
	}
	node[tt]=src;
	tt++;
	return;
}
int main()	{
	int n,m;
	int src,dest;
	scanf("%d",&n);
	while(n!=0)	{
		scanf("%d",&m);
		for(int i=0;i<m;i++)	{
			scanf("%d%d",&src,&dest);
			g[src].push_back(dest);
			grev[dest].push_back(src);
		}
		memset(visited,0,sizeof(visited));
		memset(finish,0,sizeof(finish));
		tt=1;
		for(int i=1;i<=n;i++)	{
			if(visited[i]==0)	{
				dfs_reverse(i);
			}
		}
		memset(visited,0,sizeof(visited));
		int sinkctr=0;
		for(int i=n;i>=1;i--)	{
			if(visited[finish[i]]==0)	{
				flag=0;
				dfs(finish[i],n+1-i);
//				cout<<endl;
				if(flag==0)	{
					sink[sinkctr]=finish[i];
					sinkctr++;
				}
			}
		}
		tt=0;
		memset(visited,0,sizeof(visited));
		for(int i=0;i<sinkctr;i++)	{
			getnodes(sink[i]);
		}
		sort(node,node+tt);
		for(int i=0;i<tt;i++)	{
			printf("%d ",node[i]);
		}
		printf("\n");
		for(int i=0;i<=n;i++)	{
			g[i].clear();
			grev[i].clear();
		}
		scanf("%d",&n);
	}
	return 0;
}
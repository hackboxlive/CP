#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int> > > g_undir(100100);
vector<vector<pair<int,int> > > g_dir(100100);
int visited[1000100];
int bfs_parent[1000100];
int dfs_parent[1000100];
bool AP[1000100];
bool vis[1000100];
int parent[1000100];
int disc[1000100];
int low[1000100];
int tim;
void bfs(int type,int src)	{
	queue<int> q;
	q.push(src);
	visited[src]=1;
	bfs_parent[src]=src;
	while(!(q.empty()))	{
		int u=q.front();
		q.pop();
		if(type==0)	{
			for(int i=0;i<g_undir[u].size();i++)	{
				if(visited[g_undir[u][i].first]==0)	{
					q.push(g_undir[u][i].first);
					bfs_parent[g_undir[u][i].first]=u;
					visited[g_undir[u][i].first]=1;
				}
			}
		}
		else	{
			for(int i=0;i<g_dir[u].size();i++)	{
				if(visited[g_dir[u][i].first]==0)	{
					q.push(g_dir[u][i].first);
					bfs_parent[g_dir[u][i].first]=u;
					visited[g_dir[u][i].first]=1;
				}
			}
		}
		printf("%d ",u);
	}
}
void bfs_path(int type,int src)	{
	if(bfs_parent[src]==src)	{
		printf("%d ",src);
		return;
	}
	bfs_path(type,bfs_parent[src]);
	printf("%d ",src);
	return;
}
void dfs(int type,int src)	{
	visited[src]=1;
	printf("%d ",src);
	if(type==0)	{
		for(int i=0;i<g_undir[src].size();i++)	{
			if(visited[g_undir[src][i].first]==0)	{
				dfs_parent[g_undir[src][i].first]=src;
				dfs(type,g_undir[src][i].first);
			}
		}
	}
	else	{
		for(int i=0;i<g_dir[src].size();i++)	{
			if(visited[g_dir[src][i].first]==0)	{
				dfs_parent[g_dir[src][i].first]=src;
				dfs(type,g_dir[src][i].first);
			}
		}
	}
	return;
}
void dfs_path(int type,int src)	{
	if(dfs_parent[src]==src)	{
		printf("%d ",src);
		return;
	}
	dfs_path(type,dfs_parent[src]);
	printf("%d ",src);
}
void dfs_for_components(int src,int num)	{
	visited[src]=num;
	for(int i=0;i<g_undir[src].size();i++)	{
		if(visited[g_undir[src][i].first]==0)	{
			dfs_for_components(g_undir[src][i].first,num);
		}
	}
}
void initialize(int n)	{
	for(int i=1;i<=n;i++)	{
		vis[i]=AP[i]=false; // Initializing AP and vis array as false
		parent[i]=-1;         // Initializing parent of each vertex to -1
		low[i]=0;
	}
	tim=0;
}
void dfs_for_cut_vertex(int u)	{
	vis[u]=true;
	int i;
	low[u]=disc[u]=(++tim);
	int child=0;
		for(i=0;i<g_undir[u].size();i++)	{
			int v=g_undir[u][i].first;
			if(vis[v]==false)	{
				child++;
				parent[v]=u;
				dfs_for_cut_vertex(v);
				low[u]=min(low[u],low[v]);
				if(parent[u]!=-1 && low[v]>=disc[u])
					AP[u]=true;
				if(parent[u]==-1 && child>1)
					AP[u]=true;
			}
			else if(v!=parent[u])	{
				low[u]=min(low[u],disc[v]);
			}
		}
}
int main()	{
	int graph_type;
	scanf("%d",&graph_type);
	int n,m;
	int u,v,w;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)	{
		scanf("%d%d%d",&u,&v,&w);
		g_undir[u].push_back(make_pair(v,w));
		g_undir[v].push_back(make_pair(u,w));
		g_dir[u].push_back(make_pair(v,w));
	}
	//for printing the graph
	printf("%d\n",graph_type);
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++)	{
		for(int j=0;j<g_dir[i].size();j++)	{
			printf("%d %d %d\n",i,g_dir[i][j].first,g_dir[i][j].second);
		}
	}
	printf("\n");
	//for printing bfs nodes
	printf("BFS:\n");
	for(int i=1;i<=n;i++)	{
		if(visited[i]==0)	{
			bfs(graph_type,i);
		}
	}
	printf("\n\n");
	//for printing bfs path for each node
	printf("BFS Paths:\n");
	for(int i=1;i<=n;i++)	{
			bfs_path(graph_type,i);
			printf("\n");
	}
	printf("\n");
	//for printing dfs nodes
	printf("DFS:\n");
	memset(visited,0,(n+10)*sizeof(int));
	for(int i=1;i<=n;i++)	{
		if(visited[i]==0)	{
			dfs_parent[i]=i;
			dfs(graph_type,i);
		}
	}
	printf("\n\n");
	//for printing dfs path for each node
	printf("DFS Paths:\n");
	for(int i=1;i<=n;i++)	{
		dfs_path(graph_type,i);
		printf("\n");
	}
	printf("\n");
	//for printing connected components
	printf("Connected Components:\n");
	int ctr=1;
	memset(visited,0,(n+10)*sizeof(int));
	for(int i=1;i<=n;i++)	{
		if(visited[i]==0)	{
			dfs_for_components(i,ctr);
			ctr++;
		}
	}
	vector<vector<int> > connected_comp(100100);
	for(int i=1;i<=n;i++)	{
		connected_comp[visited[i]].push_back(i);
	}
	for(int i=1;i<ctr;i++)	{
		printf("C%d: ",i);
		for(int j=0;j<connected_comp[i].size();j++)	{
			printf("%d ",connected_comp[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	//for articulation points
	printf("Articulation Vertices:\n");
	initialize(n);
	for(int i=1;i<=n;i++)	{
		if(vis[i]==false)	{
			dfs_for_cut_vertex(i);
		}
	}
	for(int i=1;i<=n;i++)	{
		if(AP[i]==true)	{
			printf("%d ",i);
		}
	}
	printf("\n");
}
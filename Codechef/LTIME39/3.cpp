#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int> > > g(600);
int flag;
int visited[600];
void reachable(int src,int dest)	{
	visited[src]=1;
	if(src==dest)	{
		flag=1;
		return;
	}
	for(int i=0;i<g[src].size();i++)	{
		if(visited[g[src][i].first]==0 && flag==0)	{
			reachable(g[src][i].first,dest);
		}
	}
	return;
}
void reachable2(int src,int dest,int k)	{
	visited[src]=k;
	if(src==dest)	{
		flag=1;
		return;
	}
	for(int i=0;i<g[src].size();i++)	{
		if(visited[g[src][i].first]!=k && flag==0 && g[src][i].second==1)	{
			reachable2(g[src][i].first,dest,k);
		}		
	}
}
struct comp {
	bool operator()	(const pair<int,int> &p1,const pair<int,int> &p2)	{
		return p1.second>p2.second;
	}
};
int travel[600];

priority_queue < pair < int,int > , vector < pair < int,int > > , comp > q;

int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		for(int i=0;i<=500;i++)	{
			g[i].clear();
		}
		int n,m,src,dest,wt;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++)	{
			scanf("%d%d%d",&src,&dest,&wt);
			g[src].push_back(make_pair(dest,wt));
		}
		flag=0;
		int a,b;
		scanf("%d%d",&a,&b);
		memset(visited,0,sizeof(visited));
		reachable(a,b);
		if(flag==0)	{
			cout<<"-1\n";
			continue;
		}
		int tt=1;
		int bigflag=0;
		memset(visited,0,sizeof(visited));
		for(int i=1;i<=n;i++)	{
			for(int j=0;j<g[i].size();j++)	{
				if(g[i][j].second==1)	{
					flag=0;
					reachable2(g[i][j].first,i,tt);
//					printf("Reacheable 2 from %d to %d is %d\n",g[i][j].first,i,flag);
					tt++;
					if(flag==1)	{
						memset(visited,0,sizeof(visited));
						flag=0;
						reachable(g[i][j].first,b);
						if(flag==1)	{
							memset(visited,0,sizeof(visited));
							flag=0;
							reachable(a,g[i][j].first);
							if(flag==1)	{
								printf("1.0\n");
								bigflag=1;
								break;
							}
						}
					}
				}
			}
			if(bigflag==1)	{
				break;
			}
		}
		memset(visited,0,sizeof(visited));
		if(bigflag==0)	{
//			djikstra(a,b);

			for(int i=1;i<=n;i++)	{
				travel[i]=INT_MAX;
			}
			int u,v,w;
		travel[a]=0;
		int edges[600];
		int gh=0;
		q.push(make_pair(a,0));
		while(!(q.empty()))	{
			u=q.top().first;
//			printf("%d\n",u);
			q.pop();
			for(int i=0;i<g[u].size();i++)	{
				v=g[u][i].first;
				w=g[u][i].second;
				if(visited[v]==0 && travel[u]+w<travel[v])	{
					edges[v]=++gh;
					travel[v]=travel[u]+w;
					q.push(make_pair(v,travel[v]));
				}
			}
			visited[u]=1;
		}

		printf("%f\n",(float)travel[b]/edges[b]);


		}
	}
	return 0;
}
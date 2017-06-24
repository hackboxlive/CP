#include <bits/stdc++.h>
using namespace std;
int mat[1100][1100];
int node_color[1100];
int visited[1100];
int n,flag;
void bfs(int node)	{
	queue<pair<int,int> > q;
	q.push(make_pair(node,1));
	node_color[node]=1;
	while(!(q.empty()))	{
		int u=q.front().first;
		int col=q.front().second;
		if(visited[u]==1)	{
			continue;
		}
		q.pop();
//		cout<<"At node "<<u<<endl;
		for(int i=1;i<=n;i++)	{
			if(mat[u][i]==0)	{
				if(node_color[i]==0)	{
//					cout<<"Coloring node "<<i<<endl;
					node_color[i]=col*-1;
					q.push(make_pair(i,col*-1));
				}
				if(node_color[i]==col)	{
//					cout<<"Same color for node "<<u<<" and "<<i<<endl;
					flag=1;
					break;
				}
			}
		}
		if(flag==1)	{
			break;
		}
		visited[u]=1;
	}
	return;
}
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		int m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)	{
			for(int j=1;j<=n;j++)	{
				mat[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)	{
			mat[i][i]=-1;
		}
		int u,v;
		for(int i=0;i<m;i++)	{
			scanf("%d%d",&u,&v);
			mat[u][v]=1;
			mat[v][u]=1;
		}
		flag=0;
		memset(node_color,0,(n+10)*sizeof(int));
		memset(visited,0,(n+10)*sizeof(int));
		for(int i=1;i<=n;i++)	{
			if(node_color[i]==0)	{
				bfs(i);
			}
		}
//		for(int i=1;i<=n;i++)	{
//			cout<<i<<" "<<node_color[i]<<endl;
//		}
		if(flag==0)	{
			cout<<"YES\n";
		}
		else	{
			cout<<"NO\n";
		}
	}
	return 0;
}
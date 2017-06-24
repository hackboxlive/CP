#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
vector<vector<pair<int,int> > > g(1000);
int dist[1000];
struct node	{
	int v,d;
};
struct comp	{
	int operator()	(const node &p1, const node &p2)	{
		return p1.d>p2.d;
	}
};
void dijkstra(int src)	{
	priority_queue<node, vector<node>,comp> q;
	for(int i=0;i<1000;i++)	{
		dist[i]=INF;
	}
	int u,vv,ww;
	dist[src]=0;
	node temp;
	temp.v=src;
	temp.d=0;
	q.push(temp);
	while(!(q.empty()))	{
		u=q.top().v;
		q.pop();
		for(int i=0;i<g[u].size();i++)	{
			vv=g[u][i].first;
			ww=g[u][i].second;
			if(dist[u]+ww<dist[vv])	{
				dist[vv]=dist[u]+ww;
				temp.v=vv;
				temp.d=dist[vv];
				q.push(temp);
			}
		}
	}
	return;
}
int main()	{
	int r=1,c=1;
	scanf("%d%d",&r,&c);
	int speed;
	int src,dest;
	char direction[5];
	int vertex;
	while(r!=0 && c!=0)	{
		vertex=(r+1)*(c+1);
		for(int i=0;i<2*r+1;i++)	{
			if(i%2==0)	{
				for(int j=0;j<c;j++)	{
					scanf("%d",&speed);
					scanf("%s",direction);
					if(speed>0)	{
						src=(i/2)*(c+1)+j;
						dest=src+1;
						if(direction[0]=='*')	{
							g[src].push_back(make_pair(dest,(2520/speed)));
							g[dest].push_back(make_pair(src,(2520/speed)));
						}
						else if(direction[0]=='>')	{
							g[src].push_back(make_pair(dest,(2520/speed)));
						}
						else	{
							g[dest].push_back(make_pair(src,(2520/speed)));
						}
					}
				}
			}
			else	{
				for(int j=0;j<c+1;j++)	{
					scanf("%d",&speed);
					scanf("%s",direction);
					if(speed>0)	{
						src=(i/2)*(c+1)+j;
						dest=src+(c+1);
						if(direction[0]=='*')	{
							g[src].push_back(make_pair(dest,(2520/speed)));
							g[dest].push_back(make_pair(src,(2520/speed)));
						}
						else if(direction[0]=='v')	{
							g[src].push_back(make_pair(dest,(2520/speed)));
						}
						else	{
							g[dest].push_back(make_pair(src,(2520/speed)));
						}
					}
				}
			}
		}
		dijkstra(0);
		if(dist[(r+1)*(c+1)-1]==INF)	{
			printf("Holiday\n");
		}
		else	{
			printf("%d blips\n",dist[(r+1)*(c+1)-1]);
		}
		for(int i=0;i<(r+1)*(c+1);i++)	{
			g[i].clear();
		}
		scanf("%d%d",&r,&c);
	}
	return 0;
}
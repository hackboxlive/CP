#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int> > > graph(100100);
long long dist[100100];
const long long inf=(long long)1e18;
struct comp{
	bool operator()(pair<int,long long> &p1,pair<int,long long> &p2)	{
		return p1.second>p2.second;
	}
};
void dijkstra(int n,int src,int oldnum,int olddist)	{
	for(int i=1;i<=n;i++)	{
		dist[i]=inf;
	}
	dist[src]=0;
	int flag=0;
    priority_queue<pair<int,long long>,vector<pair<int,long long> >,comp> pq;
	pq.push(make_pair(src,0));
	int u,v;
	long long w;
	while(!(pq.empty()))	{
		u=pq.top().first;
//		cout<<u<<" "<<dist[u]<<endl;
		pq.pop();
		if(flag==0 && u<=oldnum && u!=0)	{
			flag=1;
			for(int i=1;i<=oldnum;i++)	{
				if(i!=u)	{
					if(dist[i]>dist[u]+olddist)	{
						dist[i]=dist[u]+olddist;
						pq.push(make_pair(i,dist[i]));
					}
				}
			}
		}
		for(int i=0;i<graph[u].size();i++)	{
			v=graph[u][i].first;
			w=graph[u][i].second;
			if(dist[v]>dist[u]+w)	{
				dist[v]=dist[u]+w;
				pq.push(make_pair(v,dist[v]));
			}
		}
//			for(int j=1;j<=n;j++)	{
//				cout<<"dist["<<j<<"]="<<dist[j]<<endl;
//			}
	}
	for(int i=1;i<=n;i++)	{
		printf("%lld ",dist[i]);
	}
	printf("\n");
	return;
}
int main()	{
	int t;
	int n,k,x,m,s;
	int a,b,c;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d %d %d %d %d",&n,&k,&x,&m,&s);
		for(int i=0;i<=n;i++)	{
			graph[i].clear();
		}
		for(int i=0;i<m;i++)	{
			scanf("%d %d %d",&a,&b,&c);
			graph[a].push_back(make_pair(b,c));
			graph[b].push_back(make_pair(a,c));
		}
		graph[0].push_back(make_pair(s,0));
		dijkstra(n,0,k,x);
	}
	return 0;
}
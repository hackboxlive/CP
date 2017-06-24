#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > graph(50500);
int n,m,p;
int match[50500],dist[50500];
bool bfs()	{
	queue<int> q;
	for(int i=1;i<=n;i++)	{
		if(match[i]==0)	{
			dist[i]=0;
			Q.push(i);
		}
		else	{
			dist[i]=1e9;
		}
	}
	int u,v;
	dist[0]=1e9;
	while(!(q.empty()))	{
		u=q.front();
		q.pop();
	}
}
int main()	{
	for(int i=0;i<p;i++)	{
		scanf("%d %d",&u,&v);
		v+=n;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int matching=0;
	int i;
	while(bfs())	{//check if augmenting path exists
		
	}
	printf("%d\n",matching);
	return 0;
}
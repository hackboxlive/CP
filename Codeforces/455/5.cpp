#include <bits/stdc++.h>
using namespace std;
int pro[100100];
int depend[100100];
queue<int> q,p;
vector<int> graph[100100];
void dfs1(int src)	{
	if(pro[src]==0)	{
		for(int i=0;i<graph[src].size();i++)	{
			dfs1(graph[src][i]);
		}
	}
	else	{
		p.push(src);
	}
}
void dfs2(int src)	{
	if(pro[src]==1)	{
		for(int i=0;i<graph[src].size();i++)	{
			dfs2(graph[src][i]);
		}
	}
	else	{
		q.push(src);
	}
}
int main()	{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)	{
		cin>>pro[i];
	}
	int u,v;
	for(int i=0;i<m;i++)	{
		cin>>u>>v;
		graph[v].push_back(u);
		depend[u]=1;
	}
	for(int i=0;i<n;i++)	{
		if(depend[i]==0)	{
			q.push(i);
		}
	}
	int ans=0;
	while(!q.empty())	{
		while(!q.empty())	{
			u=q.front();
			q.pop();
			dfs1(u);
		}
		if(!p.empty())	{
			ans++;
			while(!p.empty())	{
				v=p.front();
				p.pop();
				dfs2(v);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
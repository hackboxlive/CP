#include <bits/stdc++.h>
using namespace std;
int offset=35000;
vector<int> graph[80000];
dinic(int s,int e)	{
	int tot=0;
	while(bfs(s,e)==true)	{
		
	}
}
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		cin>>n>>m;
		for(int i=1;i<800000;i++)	{
			graph[i].clear();
		}
		if(n==2)	{
			cout<<"NO\n";
			continue;
		}
		graph[offset].push_back(1);
		graph[offset].push_back(3);
		for(int i=0;i<m;i++)	{
			cin>>u>>v;
			graph[u].push_back(offset+u);
			graph[v].push_back(offset+v);
			graph[offset+u].push_back(v);
			graph[offset+v].push_back(u);
		}
		if(dinic(offset,2)==2)	{
			cout<<"YES\n";
		}
		else	{
			cout<<"NO\n";
		}
	}
	return 0;
}
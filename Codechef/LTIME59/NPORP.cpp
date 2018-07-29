#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100100];
int depth[100100];
bool flag;

void dfs(int src,int d)	{
	depth[src]=d;
	for(int i=0;i<graph[src].size();i++)	{
		if(depth[graph[src][i]]!=0)	{

		}
	}
}
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		int n,m,k;
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++)	{
			graph[i].clear();
			depth[i]=0;
		}
		int u,v;
		for(int i=0;i<m;i++)	{
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		flag=false;
		for(int i=1;i<=n;i++)	{
			if(graph[i].size()<k)	{
				cout<<"CUT\n1\n"<<i<<"\n";
				flag=true;
				break;
			}
		}
		if(flag==true)	{
			continue;
		}
	}
	return 0;
}
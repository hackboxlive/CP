#include <bits/stdc++.h>
using namespace std;
vector<int> graph[101];
vector<int> revgraph[101];
bool vis[101];
int fin[101];
int tt;
int ctr;
void dfs_rev(int src)	{
//	cout<<src<<endl;
	vis[src]=true;
	for(int i=0;i<revgraph[src].size();i++)	{
		if(!vis[revgraph[src][i]])	{
			dfs_rev(revgraph[src][i]);
		}
	}
	fin[tt]=src;
	tt++;
}
void dfs(int src)	{
	vis[src]=true;
	for(int i=0;i<graph[src].size();i++)	{
		if(!vis[graph[src][i]])	{
			dfs(graph[src][i]);
		}
	}
}
void clear(int n)	{
	for(int i=0;i<n;i++)	{
		graph[i].clear();
		revgraph[i].clear();
	}
}
int main()	{
	int t;
	cin>>t;
	string s;
	while(t--)	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)	{
			cin>>s;
			for(int j=0;j<n;j++)	{
				if(s[j]=='Y')	{
					graph[i].push_back(j);
					revgraph[j].push_back(i);
				}
			}
		}
		tt=0;
		memset(vis,false,sizeof(vis));
		for(int i=0;i<n;i++)	{
			if(!vis[i])	{
				dfs_rev(i);
			}
		}
//		for(int i=0;i<n;i++)	{
//			cout<<fin[i]<<" ";
//		}
//		cout<<endl;
		ctr=0;
//		cout<<"HERE";
		memset(vis,false,sizeof(vis));
		for(int i=n-1;i>=0;i--)	{
			if(!vis[fin[i]])	{
				ctr++;
				dfs(fin[i]);
			}
		}
		cout<<ctr<<endl;
		clear(n);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > graph[100100];
map<pair<int,int> , int> mp;
bool vis[100100];
int num[100100];
bool flag;
void clear(int n)	{
	for(int i=1;i<=n;i++)	{
		graph[i].clear();
		vis[i]=false;
		num[i]=0;
	}
	mp.clear();
}
void dfs(int src,int cur)	{
	if(vis[src]==true)	{
		if((cur-num[src])%2==1)	{
			flag=false;
		}
		return;
	}
	vis[src]=true;
	num[src]=cur;
	for(int i=0;i<graph[src].size();i++)	{
		dfs(graph[src][i].first,cur+graph[src][i].second);
	}
}
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		int n,q,u,v,w;
		scanf("%d %d",&n,&q);
		flag=true;
		for(int i=1;i<=q;i++)	{
			scanf("%d %d %d",&u,&v,&w);
			if(mp.find(make_pair(u,v))==mp.end())	{
				graph[u].push_back(make_pair(v,w));
				graph[v].push_back(make_pair(u,w));
				mp[make_pair(u,v)]=w;
				mp[make_pair(v,u)]=w;
			}
			else	{
				if(w!=mp[make_pair(u,v)])	{
					flag=false;
				}
			}
			if(u==v && w==1)	{
				flag=false;
			}
		}
		if(flag==false)	{
			printf("no\n");
			clear(n);
			continue;
		}
		for(int i=1;i<=n;i++)	{
			if(vis[i]==false)	{
				dfs(i,0);
			}
		}
		if(flag==true)	{
			printf("yes\n");
		}
		else	{
			printf("no\n");
		}
		clear(n);
	}
	return 0;
}
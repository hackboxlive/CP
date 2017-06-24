#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g(110000);
vector<vector<int> > g_rev(110000);
vector<pair<int,int> > scc_head;
bool visited[110000];
int f[110000];
int ctr;
int scc_num;
int h,p,s;
int place_ctr;
int store_scc[110000];
void reverse_dfs(int src)	{
	visited[src]=true;
	for(int i=0;i<g_rev[src].size();i++)	{
		if(visited[g_rev[src][i]]==false)	{
			reverse_dfs(g_rev[src][i]);
		}
	}
	f[ctr++]=src;
	return;
}
void dfs(int src)	{
	if(src>h)	{
		place_ctr++;
	}
	visited[src]=true;
	for(int i=0;i<g[src].size();i++)	{
		if(visited[g[src][i]]==false)	{
			dfs(g[src][i]);
		}
	}
	store_scc[src]=scc_num;
	return;
}
int main()	{
	int t;
	int src,dest;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d%d%d",&h,&p,&s);
		for(int i=0;i<s;i++)	{
			scanf("%d%d",&src,&dest);
			if(src>1000)	{
				src=src-1000;
				src=src+h;
			}
			if(dest>1000)	{
				dest=dest-1000;
				dest=dest+h;
			}
			g[src].push_back(dest);
			g_rev[dest].push_back(src);
		}
		ctr=1;
		memset(visited,false,sizeof(bool)*(h+p+10));
		for(int i=1;i<=h+p;i++)	{
			if(visited[i]==false)	{
				reverse_dfs(i);
			}
		}
		scc_num=1;
		memset(visited,false,sizeof(bool)*(h+p+10));
		for(int i=h+p;i>=1;i--)	{
			if(visited[f[i]]==false)	{
				place_ctr=0;
				dfs(f[i]);
				scc_head.push_back(make_pair(f[i],place_ctr));
				scc_num++;
			}
		}
		int minn=1;
		int fg,fgmin=store_scc[minn];
		fgmin--;
		for(int i=1;i<=h;i++)	{
			fg=store_scc[i];
			fgmin=store_scc[minn];
			fg--;
			fgmin--;
			if(scc_head[fg].second>scc_head[fgmin].second)	{
				minn=i;
			}
		}
		fgmin=store_scc[minn];
		fgmin--;
		cout<<minn<<" "<<scc_head[fgmin].second<<endl;
		for(int i=0;i<=h+p;i++)	{
			g[i].clear();
			g_rev[i].clear();
		}
		scc_head.clear();
	}
	return 0;
}
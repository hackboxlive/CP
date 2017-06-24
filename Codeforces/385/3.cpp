#include <bits/stdc++.h>
using namespace std;
vector<int> govt;
vector<pair<int,int> > govdata;
int numedge,numnode;
vector<vector<int> > g(11000);
int visited[11000];
void dfs(int src,int val)	{
	visited[src]=val;
	numnode++;
	numedge+=g[src].size();
	for(int i=0;i<g[src].size();i++)	{
		if(visited[g[src][i]]==false)	{
			dfs(g[src][i],val);
		}
	}
	return;
}
bool comp(const pair<int,int> &p1,const pair<int,int> &p2)	{
	return p1.second>p2.second;
}
int main()	{
	int n,m,k,u,v;
	cin>>n>>m>>k;
	int kk;
	for(int i=0;i<k;i++)	{
		cin>>kk;
		govt.push_back(kk);
	}
	for(int i=0;i<m;i++)	{
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=0;i<k;i++)	{
		numedge=0;
		numnode=0;
		dfs(govt[i],i+1);
		numedge/=2;
		govdata.push_back(make_pair(numnode,numedge));
	}
//	for(int i=0;i<k;i++)	{
//		cout<<govdata[i].first<<" "<<govdata[i].second<<endl;
//	}
	int faltu=0;
	for(int i=1;i<=n;i++)	{
		if(visited[i]==0)	{
			numedge=0;
			dfs(i,-1);
			numedge/=2;
			faltu+=numedge;
		}
	}
	sort(govdata.begin(),govdata.end(),comp);
	int tot_used=0;
	for(int i=0;i<k;i++)	{
		tot_used+=govdata[i].first;
	}
	int tot_left=n-tot_used;
	int x=govdata[0].first;
	x=x+tot_left;
	x=x*(x-1)/2;
	int maxx=x-govdata[0].second-faltu;
	for(int i=1;i<k;i++)	{
		x=govdata[i].first;
		x=x*(x-1)/2;
		maxx+=(x-govdata[i].second);
	}
	cout<<maxx;
	return 0;
}
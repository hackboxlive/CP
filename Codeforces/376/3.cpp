#include <bits/stdc++.h>
using namespace std;
int sock_color[200100];
bool visited[200100];
vector<vector<int> > g(200100);
int size_comp;
vector<int> col;
vector<pair<int,int> > store;
bool comp(const pair<int,int> &p1,const pair<int,int> &p2)	{
	return p1.second>p2.second;
}
void dfs(int sc)	{
//	cout<<"Pushing "<<sock_color[sc]<<endl;
	size_comp++;
	visited[sc]=true;
	col.push_back(sock_color[sc]);
	for(int i=0;i<g[sc].size();i++)	{
		if(visited[g[sc][i]]==false)	{
			dfs(g[sc][i]);
		}
	}
	return;
}
int main()	{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)	{
		scanf("%d",&sock_color[i]);
	}
	int src,dest;
	for(int i=0;i<m;i++)	{
		scanf("%d%d",&src,&dest);
		g[src].push_back(dest);
		g[dest].push_back(src);
	}
	int sum=0;
	for(int i=1;i<=n;i++)	{
		if(visited[i]==false && !(g[i].empty()))	{
			col.clear();
			store.clear();
			size_comp=0;
			dfs(i);
			int ctr=1;
//			for(int j=0;j<col.size();j++)	{
//				cout<<col[j]<<" ";
//			}
//			cout<<endl;
			sort(col.begin(),col.end());
			for(int j=0;j<col.size()-1;j++)	{
				if(col[j]==col[j+1])	{
					ctr++;
				}
				else	{
					store.push_back(make_pair(col[j],ctr));
					ctr=1;
				}
			}
			if(col[col.size()-1]==col[col.size()-2])	{
				store.push_back(make_pair(col[col.size()-1],ctr));
			}
			else	{
				store.push_back(make_pair(col[col.size()-1],1));
			}
//			for(int j=0;j<store.size();j++)	{
//				cout<<store[j].first<<" "<<store[j].second<<endl;
//			}
//			cout<<endl;
			sort(store.begin(),store.end(),comp);
			sum=sum+(size_comp-store[0].second);
		}
	}
	cout<<sum<<endl;
	return 0;
}
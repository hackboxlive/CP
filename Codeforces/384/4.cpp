#include <bits/stdc++.h>
using namespace std;
int vals[100100];
struct node	{
	long long int tot;
	long long int tree_max;
	long long int maxx;
	long long int smax;
}nodes[100100];
vector<vector<int> > tree(100100);
bool visited[100100];
void dfs(int src)	{
	visited[src]=true;
	long long int tt=0;
	long long int tmax=INT_MIN;
	int tnode;
	for(int i=0;i<tree[src].size();i++)	{
		dfs(tree[src][i]);
		tt=tt+vals[tree[src][i]];
		if(tmax<nodes[tree[src][i]].tree_max)	{
			tmax=nodes[tree[src][i]].tree_max;
			tnode=tree[src][i];
		}
	}
	if(tree[src].size()==0)	{
		nodes[src].tot=vals[src];
		nodes[src].tree_max=vals[src];
		nodes[src].maxx=nodes[src].smax=-1;
	}
	else if(tree[src].size()==1)	{
		nodes[src].tot=vals[src]+tt;
		nodes[src].tree_max=max(nodes[src].tot,tmax);
		nodes[src].maxx=nodes[tree[src][0]].maxx;
		nodes[src].smax=nodes[tree[src][0]].smax;
	}
	else	{
		nodes[src].tot=vals[src]+tt;
		nodes[src].tree_max=max(nodes[src].tot,tmax);
		long long int ssm=INT_MIN;
		for(int i=0;i<tree[src].size();i++)	{
			if(tree[src][i]==tnode)	{
				ssm=max(ssm,nodes[tnode].smax);
			}
			else	{
				ssm=max(ssm,nodes[tree[src][i]].maxx);
			}
		}
		nodes[src].maxx=
	}
	return;
}
int main()	{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>vals[i+1];
	}
	int n1,n2;
	for(int i=0;i<n-1;i++)	{
		cin>>n1>>n2;
		tree[n1].push_back(n2);
	}
	dfs(1);
	return 0;
}
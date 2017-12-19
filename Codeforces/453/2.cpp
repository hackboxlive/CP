#include <bits/stdc++.h>
using namespace std;
int color[10100];
int ans;
vector<int> tree[10100];
void dfs(int src,int par,int col)	{
	if(color[src]!=col)	{
		ans++;
		col=color[src];
	}
	for(int i=0;i<tree[src].size();i++)	{
		if(tree[src][i]!=par)	{
			dfs(tree[src][i],src,col);
		}
	}
}
int main()	{
	int n;
	cin>>n;
	int u;
	for(int i=2;i<=n;i++)	{
		cin>>u;
		tree[u].push_back(i);
		tree[i].push_back(u);
	}
	for(int i=1;i<=n;i++)	{
		cin>>color[i];
	}
	ans++;
	dfs(1,1,color[1]);
	cout<<ans<<endl;
	return 0;
}
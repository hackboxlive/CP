#include <bits/stdc++.h>
using namespace std;
vector<int> tree[100100];
int level[100100];
void dfs(int src,int l)	{
	level[l]++;
	for(int i=0;i<tree[src].size();i++)	{
		dfs(tree[src][i],l+1);
	}
}
int main()	{
	int n,v;
	cin>>n;
	for(int i=2;i<=n;i++)	{
		cin>>v;
		tree[v].push_back(i);
	}
	dfs(1,1);
	int ans=0;
	for(int i=1;i<=n;i++)	{
		if(level[i]%2)	{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
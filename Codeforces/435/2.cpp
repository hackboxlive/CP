#include <bits/stdc++.h>
using namespace std;
vector<int> tree[100100];
vector<int> one,two;
void dfs(int src,int par,int hgt)	{
	if(hgt%2==0)	{
		one.push_back(src);
	}
	else	{
		two.push_back(src);
	}
	for(int i=0;i<tree[src].size();i++)	{
		if(tree[src][i]!=par)	{
			dfs(tree[src][i],src,hgt+1);
		}
	}
}
int main()	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int u,v;
	for(int i=0;i<n-1;i++)	{
		cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dfs(1,1,0);
	long long ans=0;
	int twos=(int)two.size();
	for(int i=0;i<one.size();i++)	{
		u=one[i];
		v=(int)tree[u].size();
		ans+=(twos-v);
	}
	cout<<ans<<endl;
	return 0;
}
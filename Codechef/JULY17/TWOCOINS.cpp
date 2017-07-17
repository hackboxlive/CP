#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		int n;
		cin>>n;
		for(int i=0;i<n-1;i++)	{
			cin>>u>>v;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		dfs(1);
		cout<<min(ans[1].dp[1][0][0],ans[1].dp[0][0][0]);
	}
	return 0;
}

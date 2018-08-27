#include <bits/stdc++.h>
using namespace std;
int vis[200200];
int vis2[200200];
int arr[200200];
int cost[200200];
int ans;

int dfs(int src, int minn)	{
	//cout << "src= "<<src<<endl;
	vis[src]++;
	if(vis2[arr[src]]==1)	{
		return -1;
	}
	if(vis[arr[src]] == 0)	{
		return dfs(arr[src], minn);
	}
	else if(vis[arr[src]] == 1)	{
		return min(cost[src], dfs(arr[src], minn));
	}
	else	{
		return min(minn, cost[src]);
	}
}
void dfs2(int src)	{
	vis2[src]=1;
	if(vis2[arr[src]] == 0)	{
		dfs2(arr[src]);
	}
}
int main()	{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>cost[i + 1];
	}
	for(int i=0;i<n;i++)	{
		cin>>arr[i+1];
	}
	int temp;
	for(int i=1;i<=n;i++)	{
		if(vis[i]==0)	{
			temp = dfs(i,1e9);
			dfs2(i);
			if(temp != -1)	{
				ans += temp;
			}
			//cout << endl;
			//cout << i << " " << ans << endl;
		}
	}
	cout << ans << endl;
}
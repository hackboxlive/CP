#include <bits/stdc++.h>
using namespace std;
struct node	{
	int val;
	int orig;
	int sor;
}arr[100100];
bool vis[100100];
int ans=0;
vector<int> ind[100100];
bool comp(const node &a,const node &b)	{
	return a.val<b.val;
}
bool comp2(const node &a,const node &b)	{
	return a.orig<b.orig;
}
void dfs(int src)	{
	vis[src]=true;
	ind[ans].push_back(src);
	if(vis[arr[src].sor]==true)	{
		ans++;
		return;
	}
	dfs(arr[src].sor);
}
int main()	{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>arr[i].val;
		arr[i].orig=i;
	}
	sort(arr,arr+n,comp);
	for(int i=0;i<n;i++)	{
		arr[i].sor=i;
	}
	sort(arr,arr+n,comp2);
	for(int i=0;i<n;i++)	{
		if(vis[i]==false)	{
			dfs(i);
		}
	}
	cout<<ans<<endl;
	for(int i=0;i<ans;i++)	{
		cout<<(int)ind[i].size();
		for(int j=0;j<ind[i].size();j++)	{
			cout<<" "<<ind[i][j]+1;
		}
		cout<<endl;
	}
	return 0;
}
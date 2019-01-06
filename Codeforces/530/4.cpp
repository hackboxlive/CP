#include <bits/stdc++.h>
using namespace std;

struct node
{
	int s;
	int a;
}arr[200200];

vector<int> tree[200200];

bool verify(int src, int par, int height)
{
	if(height % 2 == 0)
	{
		arr[src].s = arr[par].s;
	}
	else
	{
		if(arr[src].s < arr[par].s)
		{
			return false;
		}
	}
	bool ans = true;
	for(int i = 0; i < tree[src].size(); i++)
	{
		ans &= verify(tree[src][i], src, height + 1);
	}
	return ans;
}

void dfs(int src, int par, int height)
{
	if(tree[src].size() == 0)
	{
		return;
	}
	for(int i = 0; i < tree[src].size(); i++)
	{
		dfs(tree[src][i], src, height + 1);
	}
	if(height % 2 == 0)
	{
		int ss = INT_MAX;
		for(int i = 0; i < tree[src].size(); i++)
		{
			ss = min(arr[tree[src][i]].s, ss);
		}
		arr[src].s = ss;
	}
	for(int i = 0; i < tree[src].size(); i++)
	{
		arr[tree[src][i]].a = arr[tree[src][i]].s - arr[src].s;
	}
}
int main()	{
	int n, p;
	cin >> n;
	for(int i = 2; i <= n; i++)
	{
		cin >> p;
		tree[p].push_back(i);
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> p;
		arr[i].s = p;
	}
	bool check = true;
	for(int i = 0; i <tree[1].size(); i++)	{
		check &= verify(tree[1][i], 1, 2);
	}
	if(check == false)
	{
		cout << "-1\n";
		return 0;
	}
	dfs(1, 1, 1);
	arr[1].a = arr[1].s;
	long long ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ans += arr[i].a;
	}
	cout << ans << endl;
	return 0;
}
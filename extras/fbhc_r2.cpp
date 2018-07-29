#include <bits/stdc++.h>
using namespace std;

struct node	{
	int left;
	int right;
}tree[2020];

vector<int> pre;
vector<int> post;

vector<int> g[2020];
int vis[2020];

void get_pre(int src)	{
	if(src == 0)	{
		return;
	}
	pre.push_back(src);
	get_pre(tree[src].left);
	get_pre(tree[src].right);
}
void get_post(int src)	{
	if(src == 0)	{
		return;
	}
	get_post(tree[src].left);
	get_post(tree[src].right);
	post.push_back(src);
}
void dfs(int src, int ctr)	{
	vis[src] = ctr;
	for(int i = 0; i < g[src].size(); i++)	{
		if(vis[g[src][i]] == 0)	{
			dfs(g[src][i], ctr);
		}
	}
}
int main()	{
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++)	{
		pre.clear();
		post.clear();
		int n, k, l, r;
		cin >> n >> k;
		for(int i = 1; i <= n; i++)	{
			g[i].clear();
			vis[i] = 0;
			cin >> l >> r;
			tree[i].left = l;
			tree[i].right = r;
		}
		get_pre(1);
		get_post(1);
		for(int i = 0; i < n; i++)	{
			g[pre[i]].push_back(post[i]);
			g[post[i]].push_back(pre[i]);
		}
		int ctr = 1;
		for(int i = 1; i <= n; i++)	{
			if(vis[i] == 0)	{
				dfs(i, ctr);
				ctr++;
			}
		}
		cout << "Case #" << tt << ": ";
		if(ctr - 1 < k)	{
			cout << "Impossible\n";
		}
		else	{
			for(int i = 1; i <= n; i++)	{
				if(vis[i] > k)	{
					cout << "1 ";
				}
				else	{
					cout << vis[i] << " ";
				}
			}
			cout << endl;
		}
	}
	return 0;
}
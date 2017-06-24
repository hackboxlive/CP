#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int> > > tree(100100);
int n;
long long int dist[1010];
bool vis[1010];
long long int a[100100];
long long int b[100100];
long long int c[100100];
long long int coff[100100];
bool comp(const pair<int,int> &p1,const pair<int,int> &p2)	{
	return p1.second > p2.second;
}
long long int dijkstra(int src)	{
	for(int i = 1 ; i <= n ; i++)	{
		dist[i] = 1e9;
		dist[i] *= 1e6;
	}
	queue<pair<int,long long int> > q;
	q.push(make_pair(src,0));
	dist[src] = 0;
	vis[src] = true;
	int u,v;
	long long int vv;
	long long int ans = 0;
	while(!(q.empty()))	{
		u = q.front().first;
		q.pop();
		for(int i = 0 ; i < tree[u].size() ; i++)	{
			v = tree[u][i].first;
			vv = tree[u][i].second;
			if(dist[v] > dist[u] + vv)	{
				dist[v] = dist[u] + vv;
				q.push(make_pair(v,dist[v]));
			}
		}
	}
	for(int i = src ; i <= n ; i++)	{
		cout<<"Src = "<<src<<" and i = "<<i<<" dist = "<<dist[i]<<endl;
		ans = ans + dist[i];
	}
	return ans;
}
bool subtask2()	{
	for(int i = 1 ; i < n - 1 ; i++)	{
		if(b[i] != a[i] + a[i + 1])	{
			return false;
		}
	}
	return true;
}
bool subtask3()	{
	for(int i = 1 ; i < n - 2 ; i++)	{
		if(c[i] != a[i] + a[i + 1] + a[i + 2])	{
			return false;
		}
	}
	return true;
}
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		int wt;
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; i++)	{
			tree[i].clear();
		}
		for(int i = 1 ; i < n ; i++)	{
			scanf("%d",&wt);
			a[i] = (long long int)wt;
			tree[i].push_back(make_pair(i + 1 , wt));
		}
		for(int i = 1 ; i < n - 1 ; i++)	{
			scanf("%d",&wt);
			b[i] = wt;
			tree[i].push_back(make_pair(i + 2 , wt));
		}
		for(int i = 1 ; i < n - 2 ; i++)	{
			scanf("%d",&wt);
			c[i] = wt;
			tree[i].push_back(make_pair(i + 3 , wt));
		}
		if(n <= 1000)	{
			long long int ans = 0;
			long long int val;
			for(int i = 1 ; i < n ; i++)	{
				val = dijkstra(i);
				ans = ans + val;
//				cout<<i<<" = "<<val<<endl;
			}
			cout<<ans<<endl;
		}
		else if(subtask3() && subtask2())	{
			//subtask2
			long long int ans = 0;
			for(int i = 1 ; i < n ; i++)	{
				coff[i] = ((long long int)n - i) * i;
			}
			for(int i = 1 ; i < n ; i++)	{
				ans += ((long long int)coff[i] * a[i]);
			}
			cout<<ans<<endl;
		}
		else if(subtask3())	{
			//subtask3
			
		}
	}
	return 0;
}
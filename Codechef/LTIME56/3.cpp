#include <bits/stdc++.h>
using namespace std;
long long w[100100];
struct node	{
	long long tot;
	int sz;
	int a;
	int b;
}temp;
vector<int> tree[100100];
struct comp	{
	bool operator()(const node &p1,const node &p2)	{
		return p1.tot*p2.sz>p2.tot*p1.sz;
	}
};
node paths[100100];
bool checker[100100];
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		cin>>n;
		for(int i=1;i<=n;i++)	{
			cin>>w[i];
			tree[i].clear();
		}
		int u,v;
		for(int i=1;i<n;i++)	{
			cin>>u>>v;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		priority_queue<node, vector<node>, comp> pq;
		for(int i=1;i<=n;i++)	{
			temp.tot=w[i];
			temp.sz=1;
			temp.a=i;
			temp.b=i;
			pq.push(temp);
			paths[i]=temp;
			checker[i]=true;
		}
		int ssz;
		long long wt;
		while(!pq.empty())	{
			u=pq.top().a;
			v=pq.top().b;
			wt=pq.top().cost;
			ssz=pq.top().sz;
			pq.pop();
			if(checker[u]==false || checker[v]==false)	{
				continue;
			}
			twt=wt;
			tsz=ssz;
			int vv;
			int f=0;
			for(int i=0;i<tree[u].size();i++)	{
				if(checker[tree[u][i]])	{
					if(twt*paths[tree[u][i]].sz<paths[tree[u][i]].cost*tsz)	{
						vv=tree[u][i];
						twt=paths[tree[u][i]].cost;
						tsz=paths[tree[u][i]].sz;
						f=1;
					}
				}
			}
			for(int i=0;i<tree[v].size();i++)	{
				if(checker[tree[v][i]])	{
					if(twt*paths[tree[v][i]].sz<paths[tree[v][i]].cost*tsz)	{
						vv=tree[v][i];
						twt=paths[tree[v][i]].cost;
						tsz=paths[tree[v][i]].sz;
						f=2;
					}
				}
			}
			if(f==1)	{
				
			}
		}
	}
	return 0;
}
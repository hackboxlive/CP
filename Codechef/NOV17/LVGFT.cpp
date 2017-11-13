#include <bits/stdc++.h>
using namespace std;
bool bank[100100];
vector<int> tree[100100];
pair<int,int> nodes[100100];
int fans,sans;
void dfs(int src,int par)	{
	for(int i=0;i<tree[src].size();i++)	{
		if(tree[src][i]!=par)	{
			dfs(tree[src][i],src);
		}
	}
	if(tree[src].size()==1 && tree[src][0]==par)	{
		nodes[src].first=src;
		nodes[src].second=-1;
		return;
	}
	int f=-1,s=-1;
	for(int i=0;i<tree[src].size();i++)	{
		if(tree[src][i]!=par)	{
			if(nodes[tree[src][i]].first>f)	{
				f=nodes[tree[src][i]].first;
			}
			else if(nodes[tree[src][i]].second>f)	{
				f=nodes[tree[src][i]].second;
			}
		}
	}
	if(src>f)	{
		f=src;
	}
	for(int i=0;i<tree[src].size();i++)	{
		if(tree[src][i]!=par )	{
			if(nodes[tree[src][i]].first>s && nodes[tree[src][i]].first!=f)	{
				s=nodes[tree[src][i]].first;
			}
			else if(nodes[tree[src][i]].second>s && nodes[tree[src][i]].second!=f)	{
				s=nodes[tree[src][i]].second;
			}
		}
	}
	if(f!=src)	{
		if(src>s)	{
			s=src;
		}
	}
	nodes[src].first=f;
	nodes[src].second=s;
}
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		int n,m,u,v,type,c;
		cin>>n>>m;
		for(int i=0;i<n-1;i++)	{
			cin>>u>>v;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		while(m--)	{
			cin>>type>>c;
			if(type==1)	{
				bank[c]=true;
			}
			else	{
				fans=sans=-1;
				dfs(c,c);
				for(int i=1;i<=n;i++)	{
					if(bank[i]==true)	{
						if(nodes[i].first>fans)	{
							fans=nodes[i].first;
						}
						else if(nodes[i].second>fans)	{
							fans=nodes[i].second;
						}
					}
				}
				for(int i=1;i<=n;i++)	{
					if(bank[i]==true)	{
						if(nodes[i].first!=fans && nodes[i].first>sans)	{
							sans=nodes[i].first;
						}
						else if(nodes[i].second!=fans && nodes[i].second>sans)	{
							sans=nodes[i].second;
						}
					}
				}				
				cout<<sans<<endl;
			}
		}
		for(int i=1;i<=n;i++)	{
			tree[i].clear();
			bank[i]=false;
		}
	}
	return 0;
}
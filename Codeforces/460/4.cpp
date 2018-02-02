#include <bits/stdc++.h>
using namespace std;
int n,m;
bool vis[300300];
bool st[300300];
int val[300300];
vector<int> g[300300];
vector<int> soc;
queue<int> q;
bool is_cyclic(int src)	{
	if(!vis[src])	{
		vis[src]=true;
		st[src]=true;
		for(int i=0;i<g[src].size();i++)	{
			if(!vis[g[src][i]] && is_cyclic(g[src][i]))	{
				return true;
			}
			else if(st[g[src][i]])	{
				return true;
			}
		}
	}
	st[src]=false;
	return false;
}
bool has_cycle()	{
	for(int i=1;i<=n;i++)	{
		vis[i]=false;
	}
	for(int i=1;i<=n;i++)	{
		if(is_cyclic(i))	{
			return true;
		}
	}
	return false;
}
int main()	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	string s;
	cin>>s;
	int u,v;
	for(int i=0;i<m;i++)	{
		cin>>u>>v;
		g[u].push_back(v);
		vis[v]=true;
	}
	for(int i=1;i<=n;i++)	{
		if(!vis[i])	{
			soc.push_back(i);
		}
	}
	if(has_cycle())	{
		cout<<"-1\n";
	}
	else	{
		int ans=0;
		for(char loop='a';loop<='z';loop++)	{
			for(int i=1;i<=n;i++)	{
				val[i]=0;
			}
			for(int i=0;i<soc.size();i++)	{
				q.push(soc[i]);
				if(s[soc[i]-1]==loop)	{
					val[soc[i]]++;
				}
			}
			while(!q.empty())	{
				u=q.front();
				ans=max(ans,val[u]);
				q.pop();
				for(int i=0;i<g[u].size();i++)	{
					v=g[u][i];
					if(s[v-1]==loop)	{
						if(val[v]<val[u]+1)	{
							val[v]=val[u]+1;
							q.push(v);
						}
					}
					else	{
						if(val[v]<val[u])	{
							val[v]=val[u];
							q.push(v);
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
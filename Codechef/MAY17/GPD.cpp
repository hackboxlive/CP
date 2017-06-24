#include <bits/stdc++.h>
using namespace std;
int id[300300];
vector<vector<int> > tree(100100);
map<int,int> mapval;
struct node	{
	int zero;
	int one;
}trie[10000000];
int mctr;
bool vis[100100];
int stnode[300300];
const int bits=32;
string s;
void insert_id(int src,int par)	{
	s="";
	int temp=id[src];
	for(int i=0;i<bits;i++)	{
		if(temp&1)	{
			s='1'+s;
		}
		else	{
			s='0'+s;
		}
		temp>>=1;
	}
	stnode[src]=mctr;
	int nd=mctr;
	int pd=stnode[par];
	mctr++;
	for(int i=0;i<bits;i++)	{
		if(s[i]=='1')	{
			trie[nd].one=mctr;
			mctr++;
			if(pd && trie[pd].zero)	{
				trie[nd].zero=trie[pd].zero;
			}
			nd=trie[nd].one;
			if(pd)	{
				pd=trie[pd].one;
			}
		}
		else	{
			trie[nd].zero=mctr;
			mctr++;
			if(pd && trie[pd].one)	{
				trie[nd].one=trie[pd].one;
			}
			nd=trie[nd].zero;
			if(pd)	{
				pd=trie[pd].zero;
			}
		}
	}
}
void dfs(int src,int par)	{
	vis[src]=true;
	insert_id(src,par);
	for(int i=0;i<tree[src].size();i++)	{
		if(!(vis[tree[src][i]]))	{
			dfs(tree[src][i],src);
		}
	}
}
int querymin(int src,int k)	{
	s="";
	int temp=k;
	for(int i=0;i<bits;i++)	{
		if(temp&1)	{
			s='1'+s;
		}
		else	{
			s='0'+s;
		}
		temp>>=1;
	}
	int st=stnode[src];
	int ans=0;
	for(int i=0;i<bits;i++)	{
		if(s[i]=='1')	{
			if(trie[st].one)	{
				st=trie[st].one;
				ans=(ans<<1)|1;
			}
			else	{
				st=trie[st].zero;
				ans=ans<<1;
			}
		}
		else	{
			if(trie[st].zero)	{
				st=trie[st].zero;
				ans=ans<<1;
			}
			else	{
				st=trie[st].one;
				ans=(ans<<1)|1;
			}
		}
	}
	return ans;
}
int querymax(int src,int k)	{
	s="";
	int temp=k;
	for(int i=0;i<bits;i++)	{
		if(temp&1)	{
			s='1'+s;
		}
		else	{
			s='0'+s;
		}
		temp>>=1;
	}
	int st=stnode[src];
	int ans=0;
	for(int i=0;i<bits;i++)	{
		if(s[i]=='1')	{
			if(trie[st].zero)	{
				st=trie[st].zero;
				ans=ans<<1;
			}
			else	{
				st=trie[st].one;
				ans=(ans<<1)|1;
			}
		}
		else	{
			if(trie[st].one)	{
				st=trie[st].one;
				ans=(ans<<1)|1;
			}
			else	{
				st=trie[st].zero;
				ans=ans<<1;
			}
		}
	}
	return ans;
}
int main()	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q;
	cin>>n>>q;
	int root,root_id;
	cin>>root>>root_id;
	int fc=1;
	mapval[root]=fc;
	id[fc]=root_id;
	fc++;
	int u,v,k;
	for(int i=1;i<n;i++)	{
		cin>>u>>v>>k;
		if(mapval.find(v)==mapval.end())	{
			mapval[v]=fc;
			fc++;
		}
		if(mapval.find(u)==mapval.end())	{
			mapval[u]=fc;
			fc++;
		}
		id[mapval[u]]=k;
		tree[mapval[u]].push_back(mapval[v]);
		tree[mapval[v]].push_back(mapval[u]);
	}
	mctr=1;
	dfs(1,1);
	int ch;
	int last_ans=0,minans,maxans;
	while(q--)	{
		cin>>ch;
		ch=ch^last_ans;
		if(ch==0)	{
			cin>>v>>u>>k;
			u=u^last_ans;
			v=v^last_ans;
			k=k^last_ans;
			mapval[u]=fc;
			fc++;
			id[mapval[u]]=k;
			insert_id(mapval[u],mapval[v]);
		}
		else	{
			cin>>v>>k;
			v=v^last_ans;
			k=k^last_ans;
			v=mapval[v];
			minans=querymin(v,k);
			minans=minans^k;
			maxans=querymax(v,k);
			maxans=maxans^k;
			last_ans=minans^maxans;
			cout<<minans<<" "<<maxans<<endl;
		}
	}
	return 0;
}
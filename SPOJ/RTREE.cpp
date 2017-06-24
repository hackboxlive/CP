#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > tree(1001000);
struct node	{
	int maxlen;
	int secmax;
	int diameter;
}dp[1001000];
void dfs(int src,int par)	{
	if(tree[src][0]==par && (int)tree[src].size()==1)	{
		dp[src].maxlen=0;
		dp[src].secmax=0;
		dp[src].diameter=0;
		return;
	}
	for(int i=0;i<tree[src].size();i++)	{
		if(tree[src][i]!=par)	{
			dfs(tree[src][i],src);
		}
	}
	int mm,sm,md,u;
	for(int i=0;i<tree[src].size();i++)	{
		if(tree[src][i]!=par)	{
			md=i;
			break;
		}
	}
	for(int i=0;i<tree[src].size();i++)	{
		if(tree[src][i]!=par)	{
			if(dp[tree[src][i]].diameter>dp[tree[src][md]].diameter)	{
				md=i;
			}
		}
	}
	for(int i=0;i<tree[src].size();i++)	{
		if(tree[src][i]!=par)	{
			mm=i;
			break;
		}
	}
	for(int i=0;i<tree[src].size();i++)	{
		if(tree[src][i]!=par)	{
			if(dp[tree[src][i]].maxlen>dp[tree[src][mm]].maxlen)	{
				mm=i;
			}
		}
	}
	if((int)tree[src].size()>2 || ((int)tree[src].size()>=2 && par==0))	{
		for(int i=0;i<tree[src].size();i++)	{
			if(tree[src][i]!=par)	{
				if(mm!=i)	{
					sm=i;
					break;
				}
			}
		}
		for(int i=0;i<tree[src].size();i++)	{
			if(tree[src][i]!=par)	{
				if(mm!=i)	{
					if(dp[tree[src][i]].maxlen>dp[tree[src][sm]].maxlen)	{
						sm=i;
					}
				}
			}
		}
	}
	else	{
		sm=-1;
	}
	dp[src].maxlen=dp[tree[src][mm]].maxlen+1;
	if(sm!=-1)	{
		dp[src].secmax=dp[tree[src][sm]].maxlen+1;
	}
	else	{
		dp[src].secmax=-1;
	}
	dp[src].diameter=dp[tree[src][md]].diameter;
	if(dp[src].secmax==-1)	{
		if(dp[src].maxlen>dp[src].diameter)	{
			dp[src].diameter=dp[src].maxlen;
		}
	}
	else	{
		if(dp[src].maxlen+dp[src].secmax>dp[src].diameter)	{
			dp[src].diameter=dp[src].maxlen+dp[src].secmax;
		}
	}
	return;
}
int main()	{
	int n,u,v;
	scanf("%d",&n);
	for(int i=1;i<n;i++)	{
		scanf("%d%d",&u,&v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	int root;
	scanf("%d",&root);
	if(n==1)	{
		int q;
		scanf("%d",&q);
		while(q--)	{
			scanf("%d",&u);
			cout<<"0\n";
		}
		return 0;
	}
	dfs(root,0);
	int q;
	scanf("%d",&q);
	while(q--)	{
		scanf("%d",&u);
		printf("%d\n",dp[u].diameter);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int> > g(100100);
vector<vector<pair<int,long long int> > > ticket(100100);
vector<vector<int> > range(100100);
int dfs_value[100100];
long long int dp[100100];
long long int tree[600600];
void dfs(int src,int val)	{
	dfs_value[src]=val;
	for(int i=0;i<g[src].size();i++)	{
		dfs(g[src][i],val+1);
	}
	return;
}
void update_tree(int id,int l,int r,int pos,long long int val)	{
	if(l>pos || r<pos)	{
		return;
	}
	if(l==pos && r==pos)	{
		tree[id]=val;
		return;
	}
	update_tree(2*id,l,(l+r)/2,pos,val);
	update_tree(2*id+1,(l+r)/2+1,r,pos,val);
	tree[id]=min(tree[2*id],tree[2*id+1]);
	return;
}
long long int query_tree(int id,int start,int end,int l,int r)	{
	if(start>r || end<l)	{
		return (long long int)1<<60;
	}
	if(start>=l && end<=r)	{
		return tree[id];
	}
	return min(query_tree(2*id,start,(start+end)/2,l,r),query_tree(2*id+1,(start+end)/2+1,end,l,r));
}
void dfs2(int src)	{
//	cout<<"Source="<<src<<endl;
	for(int i=0;i<g[src].size();i++)	{
		int u=g[src][i];
		int val=dfs_value[u];
//		cout<<"For child "<<u<<" Value="<<val<<endl;
		if(ticket[u].size()>0)	{
			long long int minans=(long long int)1<<60;
			int minj=0;
			for(int j=0;j<ticket[u].size();j++)	{
				long long int ans=query_tree(1,1,n,range[u][j],val-1);
				if(ans+ticket[u][j].second<minans+ticket[u][minj].second)	{
					minans=ans;
					minj=j;
				}
			}
			dp[u]=minans+ticket[u][minj].second;
		}
		else	{
			dp[u]=(long long int)1<<60;
		}
		update_tree(1,1,n,val,dp[u]);
		dfs2(u);
	}
	return;
}
int main()	{
	int m;
	int u,v;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n-1;i++)	{
		scanf("%d%d",&u,&v);
		g[v].push_back(u);
	}
	int k;
	for(int i=0;i<m;i++)	{
		scanf("%d%d%lld",&u,&v,&k);
		ticket[u].push_back(make_pair(v,k));
	}
	dfs(1,1);
	for(int i=2;i<=n;i++)	{
		for(int j=0;j<ticket[i].size();j++)	{
			u=ticket[i][j].first;
			if(dfs_value[i]<=u)	{
				range[i].push_back(1);
			}
			else	{
				range[i].push_back(dfs_value[i]-u);
			}
		}
	}
	for(int i=1;i<=4*n;i++)	{
		tree[i]=(long long int)1<<60;
	}
	update_tree(1,1,n,1,0);
	dp[1]=0;
	dfs2(1);
//	for(int i=1;i<=n;i++)	{
//		cout<<dp[i]<<" ";
//	}
//	cout<<endl;
	int q;
	scanf("%d",&q);
	while(q--)	{
		int aa;
		scanf("%d",&aa);
		printf("%lld\n",dp[aa]);
	}
	return 0;
}
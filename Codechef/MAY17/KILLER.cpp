#include <bits/stdc++.h>
using namespace std;
long long h[100100];
long long c[100100];
vector<vector<int> > input_tree(100100);
vector<vector<int> > tree(100100);
int par[100100];
bool vis[100100];
int height[100100];
int MAXDEPTH;
struct nd	{
	long long ans;
	int mincnode;
	long long restans;
	long long pathans;
}node[100100];
long long dp[5500];
long long cost[5500][5500];
//removing the backedges
void remove_backedge(int src,int parent,int dep)	{
	vis[src]=true;
	par[src]=parent;
	height[src]=dep;
	if(MAXDEPTH<dep)	{
		MAXDEPTH=dep;
	}
	for(int i=0;i<input_tree[src].size();i++)	{
		if(!(vis[input_tree[src][i]]))	{
			remove_backedge(input_tree[src][i],src,dep+1);
		}
	}
}
void costcalculate(int u,int p,vector<int>& path)	{
	path.push_back(u);
	for(int i=path.size()-1;i>=0;i--)	{
		cost[path[i]][u]=0;
		
	}
}
void dfs(int src)	{
	for(int i=0;i<tree[src].size();i++)	{
		dfs(tree[src][i]);
	}
	if(tree[src].size()==0)	{
		node[src].ans=c[src]*height[src]+c[src]*c[src]-h[src];
		return;
	}
	long long ans=0;

}
//getting the answer at each node
void maindfs(int src)	{
	int nc=0;
	for(int i=0;i<tree[src].size();i++)	{
		nc++;
		dfs(tree[src][i]);
	}
	if(nc==0)	{//if no child then it is base case
		node[src].pathans=c[src]*height[src]+c[src]*c[src]-h[src];
		node[src].restans=0;
		node[src].ans=node[src].pathans+node[src].restans;
		node[src].mincnode=src;
		return;
	}
	//if child is there
	long long ca=0;//calculating the sum of each child's answer
	for(int i=0;i<tree[src].size();i++)	{
		ca+=node[tree[src][i]].ans;
	}
	//selfans contains ans if path starts from that node itself
	long long selfans=c[src]*height[src];
	selfans=selfans-h[src];
	selfans=selfans+c[src]*c[src];
	selfans=selfans+ca;
	bool flag=true;
	long long tempans;
	int v,mcn,mmcn;
	for(int i=0;i<tree[src].size();i++)	{
		v=tree[src][i];
		//tempans contains the answer if source belongs to a particular child path
		tempans=ca-node[v].ans;//try and understand this
		tempans=tempans+node[v].restans;
		mcn=node[v].mincnode;
		tempans=tempans+node[v].pathans;
		tempans=tempans+c[mcn]*height[src];
		tempans=tempans+c[mcn]*c[mcn];
		if(selfans>tempans)	{
			mmcn=v;
			flag=false;
			selfans=tempans;
		}
	}
	if(flag==true)	{
		node[src].pathans=c[src]*height[src];
		node[src].pathans=node[src].pathans-h[src];
		node[src].pathans=node[src].pathans+c[src]*c[src];
		node[src].restans=ca;
		node[src].ans=node[src].pathans+node[src].restans;
		node[src].mincnode=src;
		return;
	}
	//if some branch has the answer
	v=node[mmcn].mincnode;
	node[src].pathans=node[mmcn].pathans;
	node[src].pathans=node[src].pathans+c[v]*height[src];
	node[src].pathans=node[src].pathans+c[v]*c[v];
	node[src].restans=ca-node[mmcn].ans;
	node[src].restans=node[src].restans+node[mmcn].restans;
	node[src].ans=node[src].pathans+node[src].restans;
	node[src].mincnode=v;
}
int main()	{
	int t,n;
	int u,v;
	scanf("%d",&t);
	for(int i=1;i<=100000;i++)	{
		par[i]=0;
		vis[i]=false;
	}
	while(t--)	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)	{
			scanf("%lld %lld",&h[i],&c[i]);
		}
		for(int i=1;i<n;i++)	{
			scanf("%d %d",&u,&v);
			input_tree[u].push_back(v);
			input_tree[v].push_back(u);
		}
		MAXDEPTH=-1;
		remove_backedge(1,0,0);
		for(int i=1;i<=n;i++)	{
			if(par[i]!=0)	{
				tree[par[i]].push_back(i);
			}
		}
		for(int i=1;i<=n;i++)	{
			height[i]=MAXDEPTH-height[i];
		}
		dfs(1);
//		maindfs(1);
		printf("%lld\n",node[1].ans);
		for(int i=1;i<=n;i++)	{
			input_tree[i].clear();
			tree[i].clear();
			vis[i]=false;
			par[i]=0;
		}
	}
	return 0;
}
#include <bits/stdc++.h>
#define MAX 10100
using namespace std;
struct node	{
	int dest;
	int wt;
	int id;
};
vector<vector<node> >tree(MAX);
int paren[14][MAX],depth[MAX],otherEnd[MAX],subsize[MAX];
int baseArray[MAX];
int posBase[MAX];
int chainNo,ptr;
int chainInd[MAX];
int chainSize[MAX];			//initially 0, meaning all chain lengths are 0
int chainHead[MAX];			//operates on number of chains
int chainPos[MAX];
int segtree[MAX*6];
void dfs(int src,int par,int dep)	{
	paren[0][src]=par;
	depth[src]=dep;
	subsize[src]=1;
	for(int i=0;i<tree[src].size();i++)	{
		if(tree[src][i].dest!=par)	{
			otherEnd[tree[src][i].id]=tree[src][i].dest;
			dfs(tree[src][i].dest,src,dep+1);
			subsize[src]+=subsize[tree[src][i].dest];
		}
	}
	return;
}
void heavylightdecomposition(int src,int cst,int par)	{
	if(chainHead[chainNo]==-1)	{
		chainHead[chainNo]=src;
	}
	chainInd[src]=chainNo;		//store the chain number of that node
	chainPos[src]=chainSize[chainNo];
	posBase[src]=ptr;
	baseArray[ptr++]=cst;
	chainSize[chainNo]++;
	int sc=-1,ncst;
	for(int i=0;i<tree[src].size();i++)	{
		if(tree[src][i].dest!=par)	{
			if(sc==-1 || subsize[sc]<subsize[tree[src][i].dest])	{
				sc=tree[src][i].dest;
				ncst=tree[src][i].wt;
			}
		}
	}
	if(sc!=-1)	{
		heavylightdecomposition(sc,ncst,src);
	}
	for(int i=0;i<tree[src].size();i++)	{
		if(tree[src][i].dest!=par && tree[src][i].dest!=sc)	{
			heavylightdecomposition(tree[src][i].dest,tree[src][i].wt,src);
		}
	}
	return;
}
int lowestcommonancestor(int u,int v)	{
	if(depth[u]<depth[v])	{
		swap(u,v);
	}
	int diff=depth[u]-depth[v];
	for(int i=0;i<14;i++)	{
		if((diff>>i)&1)	{
			u=paren[i][v];
		}
	}
	if(u==v)	{
		return u;
	}
	for(int i=13;i>=0;i--)	{
		if(paren[i][u]!=paren[i][v])	{
			u=paren[i][u];
			v=paren[i][v];
		}
	}
	return paren[0][u];
}
void build_tree(int id,int l,int r)	{
	if(l==r)	{
		segtree[id]=baseArray[l];
		return;
	}
	build_tree(2*id,l,(l+r)/2);
	build_tree(2*id+1,(l+r)/2+1,r);
	segtree[id]=max(segtree[2*id],segtree[2*id+1]);
	return;
}
void update_tree(int id,int l,int r,int pos,int val)	{
	if(l>pos || r<pos)	{
		return;
	}
	if(l==pos && r==pos)	{
		segtree[id]=val;
		return;
	}
	update_tree(2*id,l,(l+r)/2,pos,val);
	update_tree(2*id+1,(l+r)/2+1,r,pos,val);
	segtree[id]=max(segtree[2*id],segtree[2*id+1]);
	return;
}
int query_tree(int id,int start,int end,int l,int r)	{
	if(start>r || end<l)	{
		return -1;
	}
	if(start>=l && end<=r)	{
		return segtree[id];
	}
	return max(query_tree(2*id,start,(start+end)/2,l,r),query_tree(2*id+1,(start+end)/2+1,end,l,r));
}
int queryuv(int u,int v)	{
	if(u==v)	{
		return 0;
	}
	int uchain,vchain=chainInd[v];
	int ans=-1;
	while(1)	{
		uchain=chainInd[u];
		if(uchain==vchain)	{
			if(u==v)	{
				break;
			}
			ans=max(ans,query_tree(1,0,ptr-1,posBase[v]+1,posBase[u]+1));
			break;
		}
		ans=max(ans,query_tree(1,0,ptr-1,posBase[chainHead[uchain]],posBase[u]+1));
		u=chainHead[u];
		u=paren[0][u];
	}
	return ans;
}
void update(int u,int v)	{
	int vv=otherEnd[u];
	update_tree(1,0,ptr-1,posBase[vv],v);
	return;
}
void query(int u,int v)	{
	int lca=lowestcommonancestor(u,v);
	int ans=queryuv(u,lca);
	int temp=queryuv(v,lca);
	if(temp>ans)	{
		ans=temp;
	}
	printf("%d\n",ans);
}
int main()	{
	int t;
	node nn;
	char s[20];
	int n,src,dest,wt;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)	{
			chainHead[i]=-1;
			tree[i].clear();
			for(int j=0;j<14;j++)	{
				paren[j][i]=-1;
			}
		}
		for(int i=0;i<n-1;i++)	{
			scanf("%d%d%d",&src,&dest,&wt);
			src--;
			dest--;
			nn.dest=dest;
			nn.wt=wt;
			nn.id=i;
			tree[src].push_back(nn);
			nn.dest=src;
			tree[dest].push_back(nn);
		}
		chainNo=0;
		dfs(0,-1,0);
		for(int i=0;i<n;i++)	{
			printf("%d\n",otherEnd[i]);
		}
		heavylightdecomposition(0,-1,-1);
		build_tree(1,0,ptr-1);
		for(int i=1;i<14;i++)	{
			for(int j=0;j<n;j++)	{
				if(paren[i-1][j]!=-1)	{
					paren[i][j]=paren[i-1][paren[i-1][j]];
				}
			}
		}
		while(1)	{
			scanf("%s",s);
			if(s[0]=='D')	{
				break;
			}
			scanf("%d%d",&src,&dest);
			if(s[0]=='C')	{
				update(src-1,dest);
			}
			else	{
				query(src-1,dest-1);
			}
		}
	}
	return 0;
}
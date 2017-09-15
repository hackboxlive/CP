#include <bits/stdc++.h>
using namespace std;
vector<pair<int,long long> > graph[100100];
int par[100100];
long long dis[100100];
long long vertex[100100];
long long vvvvv[100100];
struct node	{
	int v;
	long long d;
};
long long tree[600600];
void clear(int m,int n)	{
	for(int i=0;i<m;i++)	{
		for(int j=0;j<n;j++)	{
			par[i*n+j]=i*n+j;
			dis[i*n+j]=-1;
		}
	}
}
struct comp	{
	bool operator()(const node &p1,const node &p2)	{
		return p1.d>p2.d;
	}
};
void dijkstra(int st,int en,long long ppp)	{
	priority_queue<node , vector<node> , comp> pq;
	node temp,pp;
	temp.v=st;
	temp.d=0;
	dis[st]=0;
	par[st]=0;
	int u;
	long long w;
	pq.push(temp);
	while(!pq.empty())	{
		temp=pq.top();
		pq.pop();
		for(int i=0;i<graph[temp.v].size();i++)	{
			u=graph[temp.v][i].first;
			w=graph[temp.v][i].second;
			if(dis[u]==-1 || dis[u]>dis[temp.v]+w)	{
				dis[u]=dis[temp.v]+w;
				par[u]=temp.v;
				pp.v=u;
				pp.d=dis[u];
				pq.push(pp);
			}
		}
	}
	u=en;
	while(u!=0)	{
		vertex[u]+=ppp;
		u=par[u];
	}
}
void build(int id,int l,int r)	{
	if(l==r)	{
		tree[id]=0;
		return;
	}
	build(2*id,l,(l+r)/2);
	build(2*id+1,(l+r)/2+1,r);
	tree[id]=0;
}
void update_lazy(int id,int l,int r)	{
	if(tree[id]!=0)	{
		if(l!=r)	{
			tree[2*id]+=tree[id];
			tree[2*id+1]+=tree[id];
			tree[id]=0;
		}
	}
}
void update(int id,int st,int en,int l,int r,long long w)	{
	update_lazy(id,st,en);
	if(st>r || en<l)	{
		return;
	}
	if(st>=l && en<=r)	{
		tree[id]+=w;
		return;
	}
	update(2*id,st,(st+en)/2,l,r,w);
	update(2*id+1,(st+en)/2+1,en,l,r,w);
}
long long query(int id,int l,int r,int pos)	{
	update_lazy(id,l,r);
	if(l==pos && r==pos)	{
		return tree[id];
	}
	if(pos>(l+r)/2)	{
		return query(2*id+1,(l+r)/2+1,r,pos);
	}
	else	{
		return query(2*id,l,(l+r)/2,pos);
	}
}
int main()	{
	int m,n,q;
	long long w;
	cin>>m>>n>>q;
	if(n>=1000)	{
		for(int i=0;i<m-1;i++)	{
			for(int j=0;j<n;j++)	{
				cin>>w;
				graph[i*n+j].push_back(make_pair((i+1)*n+j,w));
				graph[(i+1)*n+j].push_back(make_pair(i*n+j,w));
			}
		}
		for(int i=0;i<m;i++)	{
			for(int j=0;j<n-1;j++)	{
				cin>>w;
				graph[i*n+j].push_back(make_pair(i*n+j+1,w));
				graph[i*n+j+1].push_back(make_pair(i*n+j,w));
			}
		}
		int type,i1,j1,i2,j2;
		while(q--)	{
			cin>>type;
			if(type==1)	{
				cin>>i1>>j1>>i2>>j2>>w;
				i1--;i2--;
				j1--;j2--;
				clear(m,n);
				dijkstra(i1*n+j1,i2*n+j2,w);
			}
			else	{
				cin>>i1>>j1;
				i1--;j1--;
				cout<<vertex[i1*n+j1]<<endl;
			}
		}
		return 0;
	}
	if(m==1)	{
		for(int i=0;i<n-1;i++)	{
			cin>>vvvvv[i];
		}
		build(1,0,n-1);
		int type,i1,j1,i2,j2;
		while(q--)	{
			cin>>type;
			if(type==1)	{
				cin>>i1>>j1>>i2>>j2>>w;
				j1--;
				j2--;
				if(j1>j2)	{
					swap(j1,j2);
				}
				update(1,0,n-1,j1,j2,w);
			}
			else	{
				cin>>i1>>j1;
				j1--;
				cout<<query(1,0,n-1,j1)<<endl;
			}
		}
		return 0;
	}
	return 0;
}
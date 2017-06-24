#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g(100100);
long long int origsal[100100];
int tt;
long long int salary[100100];
struct node	{
	int start;
	int end;
}timings[100100];
struct emp	{
	long long int totsum;
	long long int minsal;
}tree[400400];
long long int lazy[400400];
void dfs(int id)	{
	timings[id].start=tt;
	for(int i=0;i<g[id].size();i++)	{
		dfs(g[id][i]);
	}
	timings[id].end=tt;
	tt++;
	return;
}
void build_tree(int id,int l,int r)	{
	if(l==r)	{
		tree[id].minsal=salary[l];
		tree[id].totsum=salary[l];
		return;
	}
	build_tree(2*id,l,(l+r)/2);
	build_tree(2*id+1,(l+r)/2+1,r);
	tree[id].totsum=tree[2*id].totsum+tree[2*id+1].totsum;
	tree[id].minsal=min(tree[2*id].minsal,tree[2*id+1].minsal);
	return;
}
void update_lazy(int id,int l,int r)	{
	if(lazy[id]>0)	{
		tree[id].totsum+=(long long int)(r-l+1)*(lazy[id]);
		tree[id].minsal+=lazy[id];
		if(l!=r)	{
			lazy[2*id]+=lazy[id];
			lazy[2*id+1]+=lazy[id];
		}
		lazy[id]=0;
	}
	return;
}
emp query_tree(int id,int start,int end,int l,int r)	{
	if(start>r || end<l)	{
		emp nullnode;
		nullnode.minsal=LONG_LONG_MAX;
		nullnode.totsum=0;
		return nullnode;
	}
	update_lazy(id,start,end);
	if(start>=l && end<=r)	{
		return tree[id];
	}
	emp p=query_tree(2*id,start,(start+end)/2,l,r);
	emp q=query_tree(2*id+1,(start+end)/2+1,end,l,r);
	emp f;
	f.minsal=min(p.minsal,q.minsal);
	f.totsum=p.totsum+q.totsum;
	return f;
}
void update_tree(int id,int start,int end,int l,int r,long long int val)	{
	update_lazy(id,start,end);
	if(start>r || end<l)	{
		return;
	}
	if(start>=l && end<=r)	{
		tree[id].totsum+=(end-start+1)*val;
		tree[id].minsal+=val;
		if(l!=r)	{
			lazy[2*id]+=val;
			lazy[2*id+1]+=val;
		}
		return;
	}
	update_tree(2*id,start,(start+end)/2,l,r,val);
	update_tree(2*id+1,(start+end)/2+1,end,l,r,val);
	tree[id].totsum=tree[2*id].totsum+tree[2*id+1].totsum;
	tree[id].minsal=min(tree[2*id].minsal,tree[2*id+1].minsal);
	return;
}
int main()	{
	int t,tc=0;
	scanf("%d",&t);
	int n,q,pa,sal,ch,ind;
	emp val;
	while(t--)	{
		printf("Case %d:\n",++tc);
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++)	{
			scanf("%d%d",&pa,&sal);
			g[pa].push_back(i);
			origsal[i]=sal;
		}
		tt=1;
		dfs(1);
		for(int i=1;i<=n;i++)	{
			cout<<timings[i].start<<" "<<timings[i].end<<endl;
			salary[timings[i].end]=origsal[i];
		}
		build_tree(1,1,n);
		while(q--)	{
			scanf("%d%d",&ch,&ind);
			if(ch==1)	{
				val=query_tree(1,1,n,timings[ind].start,timings[ind].end);
				printf("%lld\n",val.totsum);
			}
			else	{
				val=query_tree(1,1,n,timings[ind].start,timings[ind].end);
				val.totsum=min((long long int)1000,(long long int)val.minsal);
				update_tree(1,1,n,timings[ind].start,timings[ind].end,val.totsum);
			}
		}
		for(int i=0;i<=n;i++)	{
			g[i].clear();
		}
	}
}
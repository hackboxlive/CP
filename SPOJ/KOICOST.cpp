#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;
struct node	{
	int x;
	int y;
	int wt;
}edges[100100];
int sets[100100][2];
bool comp(const node &p1,const node &p2)	{
	return p1.wt>p2.wt;
}
int find_set(int u)	{
	if(sets[u][0]!=sets[sets[u][0]][0])	{
		sets[u][0]=find_set(sets[u][0]);
	}
	return sets[u][0];
}
int main()	{
	int n,m;
	int u,v,w;
	long long int edgesum=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)	{
		scanf("%d%d%d",&edges[i].x,&edges[i].y,&edges[i].wt);
		edgesum=edgesum+edges[i].wt;
	}
	sort(edges,edges+m,comp);
	for(int i=1;i<=n;i++)	{
		sets[i][0]=i;
		sets[i][1]=1;
	}
	long long int ans=0;
	int root_v,root_u;
	for(int i=0;i<m;i++)	{
		u=edges[i].x;
		v=edges[i].y;
		w=edges[i].wt;
		root_u=find_set(u);
		root_v=find_set(v);
		if(root_u==root_v)	{
			edgesum=edgesum-w;
			continue;
		}
		ans=(ans+(long long int)edgesum*sets[root_u][1]*sets[root_v][1])%MOD;
		edgesum=edgesum-w;
		if(sets[root_u][1]>sets[root_v][1])	{
			sets[root_v][0]=sets[root_u][0];
			sets[root_u][1]+=sets[root_v][1];
		}
		else	{
			sets[root_u][0]=sets[root_v][0];
			sets[root_v][1]+=sets[root_u][1];
		}
	}
	printf("%lld\n",ans);
	return 0;
}
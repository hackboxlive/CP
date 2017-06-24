#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > g;
bool comp(const pair<int,int> &p1,const pair<int,int> &p2)	{
	if(p1.first==p2.first)	{
		return p2.second<p2.second;
	}
	return p1.first>p2.first;
}
int main()	{
	int t;
	int mat[60][1100];
	scanf("%d",&t);
	while(t--)	{
		g.clear();
		int n,m;
		int wt,val;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++)	{
			scanf("%d%d",&wt,&val);
			g.push_back(make_pair(wt,val));
		}
		sort(g.begin(),g.end(),comp);
		for(int i=0;i<m;i++)	{
			mat[i][0]=0;
		}
		for(int i=0;i<=n;i++)	{
			if(g[0].first<=i)	{
				mat[0][i]=g[0].second;
			}
			else	{
				mat[0][i]=0;
			}
		}
		for(int i=1;i<m;i++)	{
			for(int j=1;j<=n;j++)	{
				if(j<g[i].first)	{
					mat[i][j]=mat[i-1][j];
				}
				else	{
					mat[i][j]=max(mat[i-1][j],g[i].second+mat[i-1][j-g[i].first]);
				}
			}
		}
		printf("Hey stupid robber, you can get %d.\n",mat[m-1][n]);
	}
	return 0;
}
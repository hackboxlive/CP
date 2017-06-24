#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int> > > g(100100);
int tt=1;
struct node	{
	int start;
	int end;
}timings[100100];
void dfs(int id)	{
	timings[id].start=tt;
	for(int i=0;i<g[id].size();i++)	{
		dfs(g[id][i].first);
	}
	timings[id].end=tt;
	tt++;
	return;
}
int main()	{
	int t,tc=0;
	scanf("%d",&t);
	int n,q,pa,sal;
	while(t--)	{
		printf("Case %d:\n",++c);
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++)	{
			scanf("%d%d",&pa,&sal);
			g[pa].push_back(make_pair(i,sal));
		}
		cout<<"HERE";
		dfs(1);
		for(int i=1;i<=n;i++)	{
			cout<<timings[i].start<<" "<<timings[i].end<<endl;
		}
	}
}
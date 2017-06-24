#include <bits/stdc++.h>
using namespace std;
struct node	{
	int x;
	int y;
	int stuff;
}shops[40];
int n,k;
double graph[40][40];
double dp[40][1<<15];
void create_graph()	{
	double dist;
	for(int i=0;i<=n;i++)	{
		for(int j=0;j<=n;j++)	{
			if(i!=j)	{
				dist=sqrt(pow((shops[i].x-shops[j].x),2)+pow((shops[i].y-shops[j].y),2));
				graph[i][j]=dist;
				graph[j][i]=dist;
			}
			else	{
				graph[i][j]=0;
			}
		}
	}
	return;
}
double solve(int cur,int mask,int depth)	{
	if(mask==(1<<k)-1)	{
		dp[cur][mask]=graph[cur][0];
		return dp[cur][mask];
	}
	if(dp[cur][mask]!=-1.0)	{
		return dp[cur][mask];
	}
	double ans,ansmin=1e9;
	int shot;
	for(int i=1;i<=n;i++)	{
		if(i!=cur && ((mask|shops[i].stuff)>mask))	{
			ans=solve(i,mask|shops[i].stuff,depth+1)+graph[cur][i];
			if(ansmin>ans)	{
				ansmin=ans;
				shot=i;
			}
		}
	}
	dp[cur][mask]=ansmin;
	return ansmin;
}
int main()	{
	int t;
	scanf("%d",&t);
	int temp;
	string s;
	while(t--)	{
		for(int i=0;i<40;i++)	{
			for(int j=0;j<(1<<15);j++)	{
				dp[i][j]=-1.0;
			}
		}
		scanf("%d %d",&n,&k);
		shops[0].x=0;
		shops[0].y=0;
		shops[0].stuff=0;
		for(int i=1;i<=n;i++)	{
			scanf("%d %d",&shops[i].x,&shops[i].y);
		}
		int check=0;
		for(int i=1;i<=n;i++)	{
			cin>>s;
			shops[i].stuff=0;
			for(int j=0;j<k;j++)	{
				shops[i].stuff*=2;
				if(s[j]=='1')	{
					shops[i].stuff+=1;
				}
			}
			check|=shops[i].stuff;
		}
		if(check!=(1<<k)-1)	{
			printf("-1\n");
			continue;
		}
		create_graph();
		solve(0,0,0);
		printf("%.10lf\n",dp[0][0]);
	}
	return 0;
}
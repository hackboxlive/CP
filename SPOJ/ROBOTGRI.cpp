#include <bits/stdc++.h>
using namespace std;
char mat[1010][1010];
bool visited[1010][1010];
long long int dp[1010][1010];
void simple_bfs()	{
	int movex[]={1,0,-1,0};
	int movey[]={0,1,0,-1};
	queue<pair<int,int> > q;
	q.push(make_pair(1,1));
	visited[1][1]=true;
	while(!(q.empty()))	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++)	{
			if(visited[x+movex[i]][y+movey[i]]==false && mat[x+movex[i]][y+movey[i]]=='.')	{
				visited[x+movex[i]][y+movey[i]]=true;
				q.push(make_pair(x+movex[i],y+movey[i]));
			}
		}
	}
	return;
}
void dp_bfs(int n)	{
	queue<pair<int,int> > q;
	long long int modu=pow(2,31)-1;
	q.push(make_pair(1,1));
	dp[1][1]=1;
	for(int i=2;i<=n;i++)	{
		if(mat[1][i]=='.')	{
			dp[1][i]=dp[1][i-1];
		}
		else	{
			dp[1][i]=0;
		}
	}
	for(int i=2;i<=n;i++)	{
		if(mat[i][1]=='.')	{
			dp[i][1]=dp[i-1][1];
		}
		else	{
			dp[i][1]=0;
		}
	}
	for(int i=2;i<=n;i++)	{
		for(int j=2;j<=n;j++)	{
			if(mat[i][j]=='#')	{
				dp[i][j]=0;
			}
			else	{
				dp[i][j]=(dp[i-1][j]+dp[i][j-1])%modu;
			}
		}
	}
	return;
}
int main()	{
	int n;
	string s;
	memset(mat,'#',sizeof(mat));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	{
		cin>>s;
		for(int j=1;j<=n;j++)	{
			mat[i][j]=s[j-1];
		}
	}
	simple_bfs();
	if(visited[n][n]==false)	{
		printf("INCONCEIVABLE\n");
		return 0;
	}
	memset(visited,false,sizeof(visited));
	dp_bfs(n);
	if(dp[n][n]==0)	{
		printf("THE GAME IS A LIE\n");
	}
	else	{
		printf("%lld\n",dp[n][n]);
	}
}
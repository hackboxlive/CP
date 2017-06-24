#include <bits/stdc++.h>
using namespace std;
char jail[1010][1010];
int kills[1010][1010];
void bfs(int n,int m)	{
	deque<pair<int,int> > q;
	q.push_front(make_pair(1,1));
	for(int i=0;i<=n+1;i++)	{
		for(int j=0;j<=m+1;j++)	{
			kills[i][j]=100000000;
		}
	}
	kills[1][1]=0;
	int x,y;
	while(!(q.empty()))	{
		x=q.front().first;
		y=q.front().second;
		q.pop_front();
		if(jail[x+1][y]!='#')	{
			if(jail[x+1][y]==jail[x][y])	{
				if(kills[x+1][y]>kills[x][y])	{
					kills[x+1][y]=kills[x][y];
					q.push_front(make_pair(x+1,y));
				}
			}
			else	{
				if(kills[x+1][y]>kills[x][y]+1)	{
					kills[x+1][y]=kills[x][y]+1;
					q.push_back(make_pair(x+1,y));
				}
			}
		}
		if(jail[x-1][y]!='#')	{
			if(jail[x-1][y]==jail[x][y])	{
				if(kills[x-1][y]>kills[x][y])	{
					kills[x-1][y]=kills[x][y];
					q.push_front(make_pair(x-1,y));
				}
			}
			else	{
				if(kills[x-1][y]>kills[x][y]+1)	{
					kills[x-1][y]=kills[x][y]+1;
					q.push_back(make_pair(x-1,y));
				}
			}
		}
		if(jail[x][y+1]!='#')	{
			if(jail[x][y+1]==jail[x][y])	{
				if(kills[x][y+1]>kills[x][y])	{
					kills[x][y+1]=kills[x][y];
					q.push_front(make_pair(x,y+1));
				}
			}
			else	{
				if(kills[x][y+1]>kills[x][y]+1)	{
					kills[x][y+1]=kills[x][y]+1;
					q.push_back(make_pair(x,y+1));
				}
			}
		}
		if(jail[x][y-1]!='#')	{
			if(jail[x][y-1]==jail[x][y])	{
				if(kills[x][y-1]>kills[x][y])	{
					kills[x][y-1]=kills[x][y];
					q.push_front(make_pair(x,y-1));
				}
			}
			else	{
				if(kills[x][y-1]>kills[x][y]+1)	{
					kills[x][y-1]=kills[x][y]+1;
					q.push_back(make_pair(x,y-1));
				}
			}
		}
	}
	return;
}
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		int n,m;
		register int c;
		scanf("%d%d",&n,&m);
		memset(jail,'#',sizeof(jail));
		for(int i=1;i<=n;i++)	{
			for(int j=1;j<=m;j++)	{
				c=getchar_unlocked();
				while(c<97 || c>122)	{
					c=getchar_unlocked();
				}
				jail[i][j]=c;
			}
		}
		bfs(n,m);
		printf("%d\n",kills[n][m]);
	}
	return 0;
}
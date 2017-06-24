#include <bits/stdc++.h>
using namespace std;
char orig_maze[110][110];
char maze[110][110][4];
int dist[110][110];
bool visited[110][110][4];
pair<int,int> starting;
pair<int,int> goal;
int minn;
struct node	{
	int x;
	int y;
	int num;
};
void change_face(int m,int n)	{
	for(int i=1;i<=m;i++)	{
		for(int j=1;j<=n;j++)	{
			if(orig_maze[i][j]=='<')	{
				orig_maze[i][j]='^';
			}
			else if(orig_maze[i][j]=='^')	{
				orig_maze[i][j]='>';
			}
			else if(orig_maze[i][j]=='>')	{
				orig_maze[i][j]='v';
			}
			else if(orig_maze[i][j]=='v')	{
				orig_maze[i][j]='<';
			}
		}
	}
	return;
}
void generate_maze(int m,int n)	{
	memset(maze,'#',sizeof(maze));
	change_face(m,n);
	for(int t=0;t<4;t++)	{
		//working on the t th maze
		for(int i=1;i<=m;i++)	{
			for(int j=1;j<=n;j++)	{
				if(orig_maze[i][j]=='.')	{
					maze[i][j][t]='.';
				}
				if(orig_maze[i][j]=='#')	{
					maze[i][j][t]='#';
				}
			}
		}
		//filled the t th maze with dots and hashes
		for(int i=1;i<=m;i++)	{
			for(int j=1;j<=n;j++)	{
				if(orig_maze[i][j]=='<')	{
					int k=j;
					orig_maze[i][j]='l';
					while(orig_maze[i][k]=='.' || orig_maze[i][k]=='l')	{
						maze[i][k][t]='l';
						k--;
					}
					orig_maze[i][j]='<';
				}
				else if(orig_maze[i][j]=='^')	{
					int k=i;
					orig_maze[i][j]='l';
					while(orig_maze[k][j]=='.' || orig_maze[k][j]=='l')	{
						maze[k][j][t]='l';
						k--;
					}
					orig_maze[i][j]='^';
				}
				else if(orig_maze[i][j]=='>')	{
					int k=j;
					orig_maze[i][j]='l';
					while(orig_maze[i][k]=='.' || orig_maze[i][k]=='l')	{
						maze[i][k][t]='l';
						k++;
					}
					orig_maze[i][j]='>';
				}
				else if(orig_maze[i][j]=='v')	{
					int k=i;
					orig_maze[i][j]='l';
					while(orig_maze[k][j]=='.' || orig_maze[k][j]=='l')	{
						maze[k][j][t]='l';
						k++;
					}
					orig_maze[i][j]='v';
				}
			}
		}
		//filled all the path of the lasers with l
		for(int i=1;i<=m;i++)	{
			for(int j=1;j<=n;j++)	{
				if(maze[i][j][t]=='l')	{
					maze[i][j][t]='#';
				}
			}
		}
		change_face(m,n);
	}
	return;
}
void bfs()	{
	memset(visited,false,sizeof(visited));
	queue<node> q;
	node st,pre;
	st.x=starting.first;
	st.y=starting.second;
	st.num=-1;
	int xx,yy,nn;
	q.push(st);
	dist[st.x][st.y]=0;
	while(!(q.empty()))	{
		xx=q.front().x;
		yy=q.front().y;
		nn=q.front().num;
		q.pop();
		if(maze[xx][yy+1][(nn+1)%4]=='.' && visited[xx][yy+1][(nn+1)%4]==false)	{
			pre.x=xx;
			pre.y=yy+1;
			pre.num=(nn+1)%4;
			q.push(pre);
			visited[xx][yy+1][(nn+1)%4]=true;
			dist[xx][yy+1]=dist[xx][yy]+1;
			if(xx==goal.first && yy+1==goal.second)	{
				if(minn>dist[xx][yy+1])	{
					minn=dist[xx][yy+1];
				}
			}
		}
		if(maze[xx+1][yy][(nn+1)%4]=='.' && visited[xx+1][yy][(nn+1)%4]==false)	{
			pre.x=xx+1;
			pre.y=yy;
			pre.num=(nn+1)%4;
			q.push(pre);
			visited[xx+1][yy][(nn+1)%4]=true;
			dist[xx+1][yy]=dist[xx][yy]+1;
			if(xx+1==goal.first && yy==goal.second)	{
				if(minn>dist[xx+1][yy])	{
					minn=dist[xx+1][yy];
				}
			}
		}
		if(maze[xx][yy-1][(nn+1)%4]=='.' && visited[xx][yy-1][(nn+1)%4]==false)	{
			pre.x=xx;
			pre.y=yy-1;
			pre.num=(nn+1)%4;
			q.push(pre);
			visited[xx][yy-1][(nn+1)%4]=true;
			dist[xx][yy-1]=dist[xx][yy]+1;
			if(xx==goal.first && yy-1==goal.second)	{
				if(minn>dist[xx][yy-1])	{
					minn=dist[xx][yy-1];
				}
			}
		}
		if(maze[xx-1][yy][(nn+1)%4]=='.' && visited[xx-1][yy][(nn+1)%4]==false)	{
			pre.x=xx-1;
			pre.y=yy;
			pre.num=(nn+1)%4;
			q.push(pre);
			visited[xx-1][yy][(nn+1)%4]=true;
			dist[xx-1][yy]=dist[xx][yy]+1;
			if(xx-1==goal.first && yy==goal.second)	{
				if(minn>dist[xx-1][yy])	{
					minn=dist[xx-1][yy];
				}
			}
		}
	}
}
int main()	{
	int t,tt=0;
	string s;
	scanf("%d",&t);
	while(t--)	{
		int n,m;
		scanf("%d%d",&m,&n);
		memset(orig_maze,'#',sizeof(orig_maze));
		for(int i=1;i<=m;i++)	{
			cin>>s;
			for(int j=1;j<=n;j++)	{
				if(s[j-1]=='S')	{
					starting.first=i;
					starting.second=j;
					orig_maze[i][j]='.';
				}
				else if(s[j-1]=='G')	{
					goal.first=i;
					goal.second=j;
					orig_maze[i][j]='.';
				}
				else	{
					orig_maze[i][j]=s[j-1];
				}
			}
		}
		minn=1e8;
		generate_maze(m,n);
		bfs();
//		int dis=dist[goal.first][goal.second];
		if(minn!=1e8)	{
			printf("Case #%d: %d\n",++tt,minn);
		}
		else	{
			printf("Case #%d: impossible\n",++tt);
		}
	}
	return 0;
}
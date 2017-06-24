#include <bits/stdc++.h>
using namespace std;
char mat[60][60];
struct node	{
	int sizeoflake;
	int row;
	int col;
}lake[10000];
bool comp(const node &p1,const node &p2)	{
	return p1.sizeoflake<p2.sizeoflake;
}
void bfs_ocean(int r,int c)	{
	queue<pair<int,int> > q;
	q.push(make_pair(r,c));
	mat[r][c]='o';
	while(!(q.empty()))	{
		int u=q.front().first;
		int v=q.front().second;
		q.pop();
		if(mat[u+1][v]=='.')	{
			q.push(make_pair(u+1,v));
			mat[u+1][v]='o';
		}
		if(mat[u-1][v]=='.')	{
			q.push(make_pair(u-1,v));
			mat[u-1][v]='o';
		}
		if(mat[u][v+1]=='.')	{
			q.push(make_pair(u,v+1));
			mat[u][v+1]='o';
		}
		if(mat[u][v-1]=='.')	{
			q.push(make_pair(u,v-1));
			mat[u][v-1]='o';
		}
	}
	return;
}
int bfs_lake(int r,int c)	{
	int ctr=1;
	queue<pair<int,int> > q;
	q.push(make_pair(r,c));
	mat[r][c]='V';
	while(!(q.empty()))	{
		int u=q.front().first;
		int v=q.front().second;
		q.pop();
		if(mat[u+1][v]=='.')	{
			q.push(make_pair(u+1,v));
			ctr++;
			mat[u+1][v]='V';
		}
		if(mat[u-1][v]=='.')	{
			q.push(make_pair(u-1,v));
			ctr++;
			mat[u-1][v]='V';
		}
		if(mat[u][v+1]=='.')	{
			q.push(make_pair(u,v+1));
			ctr++;
			mat[u][v+1]='V';
		}
		if(mat[u][v-1]=='.')	{
			q.push(make_pair(u,v-1));
			ctr++;
			mat[u][v-1]='V';
		}
	}
	return ctr;
}
void bfs_fill_lake(int r,int c)	{
	queue<pair<int,int> > q;
	q.push(make_pair(r,c));
	mat[r][c]='*';
	while(!(q.empty()))	{
		int u=q.front().first;
		int v=q.front().second;
		q.pop();
		if(mat[u+1][v]=='V')	{
			q.push(make_pair(u+1,v));
			mat[u+1][v]='*';
		}
		if(mat[u-1][v]=='V')	{
			q.push(make_pair(u-1,v));
			mat[u-1][v]='*';
		}
		if(mat[u][v+1]=='V')	{
			q.push(make_pair(u,v+1));
			mat[u][v+1]='*';
		}
		if(mat[u][v-1]=='V')	{
			q.push(make_pair(u,v-1));
			mat[u][v-1]='*';
		}
	}
	return;
}
void bfs_fill_lake2(int r,int c)	{
	queue<pair<int,int> > q;
	q.push(make_pair(r,c));
	mat[r][c]='.';
	while(!(q.empty()))	{
		int u=q.front().first;
		int v=q.front().second;
		q.pop();
		if(mat[u+1][v]=='V')	{
			q.push(make_pair(u+1,v));
			mat[u+1][v]='.';
		}
		if(mat[u-1][v]=='V')	{
			q.push(make_pair(u-1,v));
			mat[u-1][v]='.';
		}
		if(mat[u][v+1]=='V')	{
			q.push(make_pair(u,v+1));
			mat[u][v+1]='.';
		}
		if(mat[u][v-1]=='V')	{
			q.push(make_pair(u,v-1));
			mat[u][v-1]='.';
		}
	}
	return;
}
void bfs_fill_ocean(int r,int c)	{
	queue<pair<int,int> > q;
	q.push(make_pair(r,c));
	mat[r][c]='.';
	while(!(q.empty()))	{
		int u=q.front().first;
		int v=q.front().second;
		q.pop();
		if(mat[u+1][v]=='o')	{
			q.push(make_pair(u+1,v));
			mat[u+1][v]='.';
		}
		if(mat[u-1][v]=='o')	{
			q.push(make_pair(u-1,v));
			mat[u-1][v]='.';
		}
		if(mat[u][v+1]=='o')	{
			q.push(make_pair(u,v+1));
			mat[u][v+1]='.';
		}
		if(mat[u][v-1]=='o')	{
			q.push(make_pair(u,v-1));
			mat[u][v-1]='.';
		}
	}
	return;
}
int main()	{
	int n,m,k;
	string s;
	scanf("%d%d%d",&n,&m,&k);
	memset(mat,'O',sizeof(mat));
	for(int i=1;i<=n;i++)	{
		cin>>s;
		for(int j=1;j<=m;j++)	{
			mat[i][j]=s[j-1];
		}
	}
	for(int i=1;i<=m;i++)	{
		if(mat[1][i]=='.')	{
			bfs_ocean(1,i);
		}
		if(mat[n][i]=='.')	{
			bfs_ocean(n,i);
		}
	}
	for(int i=1;i<=n;i++)	{
		if(mat[i][1]=='.')	{
			bfs_ocean(i,1);
		}
		if(mat[i][m]=='.')	{
			bfs_ocean(i,m);
		}
	}
	int totctr=0;
	for(int i=1;i<=n;i++)	{
		for(int j=1;j<=m;j++)	{
			if(mat[i][j]=='.')	{
				lake[totctr].sizeoflake=bfs_lake(i,j);
				lake[totctr].row=i;
				lake[totctr].col=j;
				totctr++;
			}
		}
	}
	sort(lake,lake+totctr,comp);
	int mintot=0;
	for(int i=0;i<totctr-k;i++)	{
		mintot+=lake[i].sizeoflake;
		bfs_fill_lake(lake[i].row,lake[i].col);
	}
	for(int i=totctr-k;i<totctr;i++)	{
		bfs_fill_lake2(lake[i].row,lake[i].col);
	}
	for(int i=1;i<=m;i++)	{
		if(mat[1][i]=='o')	{
			bfs_fill_ocean(1,i);
		}
		if(mat[n][i]=='o')	{
			bfs_fill_ocean(n,i);
		}
	}
	for(int i=1;i<=n;i++)	{
		if(mat[i][1]=='o')	{
			bfs_fill_ocean(i,1);
		}
		if(mat[i][m]=='o')	{
			bfs_fill_ocean(i,m);
		}
	}
	cout<<mintot<<endl;
	for(int i=1;i<=n;i++)	{
		for(int j=1;j<=m;j++)	{
			cout<<mat[i][j];
		}
		cout<<endl;
	}
	return 0;
}
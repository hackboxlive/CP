#include <bits/stdc++.h>
using namespace std;
char mat[110][110];
bool visited[110][110];
int dist[110][110];
void bfs(int r,int c,pair<int,int> car)	{
	for(int i=1;i<=r;i++)	{
		for(int j=1;j<=c;j++)	{
			visited[i][j]=false;
		}
	}
	queue<pair<int,int> > q;
	q.push(car);
	visited[car.first][car.second]=true;
	dist[car.first][car.second]=0;
	int x,y;
	while(!(q.empty()))	{
		x=q.front().first;
		y=q.front().second;
		q.pop();
		if((mat[x+1][y]=='.' || mat[x+1][y]=='S') && visited[x+1][y]==false)	{
			q.push(make_pair(x+1,y));
			visited[x+1][y]=true;
			dist[x+1][y]=dist[x][y]+1;
		}
		if((mat[x-1][y]=='.' || mat[x-1][y]=='S') && visited[x-1][y]==false)	{
			q.push(make_pair(x-1,y));
			visited[x-1][y]=true;
			dist[x-1][y]=dist[x][y]+1;
		}
		if((mat[x][y+1]=='.' || mat[x][y+1]=='S') && visited[x][y+1]==false)	{
			q.push(make_pair(x,y+1));
			visited[x][y+1]=true;
			dist[x][y+1]=dist[x][y]+1;
		}
		if((mat[x][y-1]=='.' || mat[x][y-1]=='S') && visited[x][y-1]==false)	{
			q.push(make_pair(x,y-1));
			visited[x][y-1]=true;
			dist[x][y-1]=dist[x][y]+1;
		}
	}
	vector<int> shops;
	for(int i=1;i<=r;i++)	{
		for(int j=1;j<=c;j++)	{
			if(mat[i][j]=='S')	{
				shops.push_back(dist[i][j]);
			}
		}
	}
	sort(shops.begin(),shops.end());
	int timer=0;
	for(int i=0;i<shops.size();i++)	{
		timer+=60;
		timer+=shops[i]*2;
	}
	timer-=shops[(int)shops.size()-1];
	printf("%d\n",timer);
/*	for(int i=1;i<=r;i++)	{
		for(int j=1;j<=c;j++)	{
			cout<<dist[i][j]<<" ";
		}
		cout<<endl;
	}
*/	return;
}
int main()	{
	int m;
	string s;
	scanf("%d",&m);
	while(m--)	{
		int r,c;
		scanf("%d%d",&r,&c);
		for(int i=0;i<=r+1;i++)	{
			for(int j=0;j<=c+1;j++)	{
				mat[i][j]='#';
			}
		}
		pair<int,int> car;
		for(int i=1;i<=r;i++)	{
			cin>>s;
			for(int j=1;j<=c;j++)	{
				mat[i][j]=s[j-1];
				if(s[j-1]=='C')	{
					car.first=i;
					car.second=j;
				}
			}
		}
		bfs(r,c,car);
	}
	return 0;
}
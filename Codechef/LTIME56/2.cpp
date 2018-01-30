#include <bits/stdc++.h>
using namespace std;
int mat[1010][1010];
char yon[1010][1010];
bool vis[1010][1010];
struct node	{
	int x;
	int y;
	int cost;
}temp;
struct comp	{
	bool operator()(const node &p1,const node &p2)	{
		return p1.cost<p2.cost;
	}
};
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		int n,m;
		cin>>n>>m;
		for(int i=0;i<=n+1;i++)	{
			mat[i][0]=-1;
			mat[i][m+1]=-1;
		}
		for(int i=0;i<=m+1;i++)	{
			mat[0][i]=-1;
			mat[n+1][i]=-1;
		}
		priority_queue<node, vector<node>, comp> pq;
		for(int i=1;i<=n;i++)	{
			for(int j=1;j<=m;j++)	{
				vis[i][j]=false;
				cin>>mat[i][j];
				if(mat[i][j]==-1)	{
					yon[i][j]='B';
				}
				if(mat[i][j]==0)	{
					mat[i][j]=-2;
					yon[i][j]='N';
				}
				if(mat[i][j]>0)	{
					temp.x=i;
					temp.y=j;
					temp.cost=mat[i][j];
					pq.push(temp);
					yon[i][j]='Y';
				}
			}
		}
		int r,c,g;
		int d1[]={1,0,-1,0};
		int d2[]={0,1,0,-1};
		while(!pq.empty())	{
			r=pq.top().x;
			c=pq.top().y;
			g=pq.top().cost;
			pq.pop();
			if(vis[r][c]==true || g<0)	{
				continue;
			}
			vis[r][c]=true;
			yon[r][c]='Y';
			for(int i=0;i<4;i++)	{
				if(mat[r+d1[i]][c+d2[i]]!=-1)	{
					if(!vis[r+d1[i]][c+d2[i]])	{
						temp.x=r+d1[i];
						temp.y=c+d2[i];
						temp.cost=g-1;
						pq.push(temp);
					}
				}
			}
		}
		for(int i=1;i<=n;i++)	{
			for(int j=1;j<=m;j++)	{
				cout<<yon[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
char mat[22][22];
bool vis[22][22];
int bfs(int x,int y)	{
	int dirx[8]={1,-1,0,0,1,1,-1,-1};
	int diry[8]={0,0,1,-1,1,-1,1,-1};
	queue<pair<int,int> > q;
	q.push(make_pair(x,y));
	vis[x][y]=true;
	int i,j;
	int ans=0;
	while(!q.empty())	{
		i=q.front().first;
		j=q.front().second;
		q.pop();
		for(int k=0;k<4;k++)	{
			if(mat[i+dirx[k]][j+diry[k]]=='.')	{
				ans++;
			}
		}
		for(int k=0;k<8;k++)	{
			if(vis[i+dirx[k]][j+diry[k]]==false && mat[i+dirx[k]][j+diry[k]]=='X')	{
				vis[i+dirx[k]][j+diry[k]]=true;
				q.push(make_pair(i+dirx[k],j+diry[k]));
			}
		}
	}
	return ans;
}
int main()	{
	int r,c,x,y;
	string s;
	while(true)	{
		cin>>r>>c>>x>>y;
		if(r==0)	{
			break;
		}
		for(int i=0;i<=r+1;i++)	{
			for(int j=0;j<=c+1;j++)	{
				mat[i][j]='.';
				vis[i][j]=false;
			}
		}
		for(int i=1;i<=r;i++)	{
			cin>>s;
			for(int j=0;j<s.length();j++)	{
				mat[i][j+1]=s[j];
			}
		}
		int ans=bfs(x,y);
		cout<<ans<<endl;
	}
	return 0;
}
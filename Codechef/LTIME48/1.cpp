#include <bits/stdc++.h>
using namespace std;
struct node	{
	long long x,y;
	int id;
};
long long r;
vector<node> points;
vector<vector<int> > graph(10100);
bool vis[5100];
void dfs(int src)	{
	vis[src]=true;
	for(int i=0;i<graph[src].size();i++)	{
		if(!vis[graph[src][i]])	{
			dfs(graph[src][i]);
		}
	}
}
bool check(long long c,long long d,long long x,long long y)	{
	if(y<=c+d+r-x && y>=c+d-r-x && y<=d+r-c+x && y>=d-r-c+x)	{
		return true;
	}
	return false;
}
int main()	{
	long long q;
	node temp;
	string ch;
	cin>>q>>r;
	long long x,y;
	long long dist;
	long long c,d;
	for(int t=1;t<=q;t++)	{
		cin>>ch;
		if(ch[0]=='+')	{
			cin>>x>>y;
			temp.x=x;
			temp.y=y;
			temp.id=t;
			for(int i=0;i<points.size();i++)	{
				c=points[i].x;
				d=points[i].y;
				if(check(c,d,x+r,y) || check(c,d,x-r,y) || check(c,d,x,y+r) || check(c,d,x,y-r))	{
					graph[t].push_back(points[i].id);
					graph[points[i].id].push_back(t);
					continue;
				}
				if(check(x,y,c+r,d) || check(x,y,c-r,d) || check(x,y,c,d+r) || check(x,y,c,d-r))	{
					graph[t].push_back(points[i].id);
					graph[points[i].id].push_back(t);
					continue;
				}
//				cout<<"HERE"<<endl;
			}
			points.push_back(temp);
		}
		else	{
			cin>>x>>y;
			for(int i=1;i<=5000;i++)	{
				vis[i]=false;
			}
			dfs(x);
			if(vis[y])	{
				cout<<"DA\n";
			}
			else	{
				cout<<"NET\n";
			}
		}
	}
	return 0;
}
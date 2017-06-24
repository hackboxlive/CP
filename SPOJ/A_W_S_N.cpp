#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int> > > g(110);
int floor_map[110][110];
int visited[110][110];
int dist[110][110];
vector<pair<int,int> > dirty;
int numbering[110];
int mini;
void bfs(int x,int y,int pos)	{
	queue<pair<int,int> > q;
	q.push(make_pair(x,y));
	visited[x][y]=1;
	dist[x][y]=0;
	while(!(q.empty()))	{
		int a=q.front().first;
		int b=q.front().second;
		q.pop();
		if((visited[a+1][b]==0) && (floor_map[a+1][b]=='.' || floor_map[a+1][b]=='W' || floor_map[a+1][b]=='C'))	{
			visited[a+1][b]=1;
			q.push(make_pair(a+1,b));
			dist[a+1][b]=dist[a][b]+1;
		}
		if((visited[a][b-1]==0) && (floor_map[a][b-1]=='.' || floor_map[a][b-1]=='W' || floor_map[a][b-1]=='C'))	{
			visited[a][b-1]=1;
			q.push(make_pair(a,b-1));
			dist[a][b-1]=dist[a][b]+1;
		}
		if((visited[a-1][b]==0) && (floor_map[a-1][b]=='.' || floor_map[a-1][b]=='W' || floor_map[a-1][b]=='C'))	{
			visited[a-1][b]=1;
			q.push(make_pair(a-1,b));
			dist[a-1][b]=dist[a][b]+1;
		}
		if((visited[a][b+1]==0) && (floor_map[a][b+1]=='.' || floor_map[a][b+1]=='W' || floor_map[a][b+1]=='C'))	{
			visited[a][b+1]=1;
			q.push(make_pair(a,b+1));
			dist[a][b+1]=dist[a][b]+1;
		}
	}
}
int find_index(int x,int y)	{
	for(int i=0;i<dirty.size();i++)	{
		if(dirty[i].first==x && dirty[i].second==y)	{
			return i;
		}
	}
}
void permute(int l,int r)	{
	if(l==r)	{
		int numnum=numbering[0];
		for(int i=0;i<g[0].size();i++)	{
			if(g[0][i].first==numnum)	{
				numnum=i;
				break;
			}
		}
		int ans=g[0][numnum].second;
		for(int i=1;i<dirty.size()-1;i++)	{
			int find=numbering[i];
			for(int j=0;j<g[numbering[i-1]].size();j++)	{
				if(g[numbering[i-1]][j].first==find)	{
					find=j;
					break;
				}
			}
			ans+=g[numbering[i-1]][find].second;
		}
		if(ans<mini)	{
			mini=ans;
		}
		return;
	}
	for(int i=l;i<=r;i++)	{
		swap(numbering[l],numbering[i]);
		permute(l+1,r);
		swap(numbering[l],numbering[i]);
	}
}
int main()	{
	int t;
	int w,h;
	scanf("%d",&t);
	while(t--)	{
		memset(floor_map,'#',sizeof(floor_map));
		scanf("%d%d",&h,&w);
		string s;
		for(int i=1;i<=h;i++)	{
			cin>>s;
			for(int j=0;j<s.length();j++)	{
				floor_map[i][j+1]=s[j];
			}
		}
		pair<int,int> origin;
		pair<int,int> finall;
		for(int i=1;i<=h;i++)	{
			for(int j=1;j<=w;j++)	{
				if(floor_map[i][j]=='T')	{
					origin.first=i;
					origin.second=j;
					dirty.push_back(make_pair(i,j));
				}
				if(floor_map[i][j]=='W')	{
					finall.first=i;
					finall.second=j;
				}
			}
		}
		for(int i=1;i<=h;i++)	{
			for(int j=1;j<=w;j++)	{
				if(floor_map[i][j]=='C')	{
					dirty.push_back(make_pair(i,j));
				}
				if(floor_map[i][j]=='C')	{
					floor_map[i][j]='*';
				}
			}
		}
		for(int i=0;i<dirty.size();i++)	{
			for(int j=0;j<110;j++)	{
				for(int k=0;k<110;k++)	{
					dist[j][k]=100000;
				}
			}
			memset(visited,0,sizeof(visited));
			bfs(dirty[i].first,dirty[i].second,i);
			for(int j=1;j<=h;j++)	{
				for(int k=1;k<=w;k++)	{
					if(floor_map[j][k]=='C')	{
						int id=find_index(j,k);
						g[i].push_back(make_pair(id,dist[j][k]));
					}
				}
			}
		}
		for(int i=1;i<dirty.size();i++)	{
			numbering[i-1]=i;
		}
		mini=100000;
		permute(0,dirty.size()-2);
		if(mini==100000)	{
			printf("-1\n");
		}
		else	{
			printf("%d\n",mini);
		}
		for(int i=0;i<dirty.size();i++)	{
			g[i].clear();
		}
		dirty.clear();
		scanf("%d%d",&w,&h);
	}
	return 0;
}
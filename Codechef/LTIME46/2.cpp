#include <bits/stdc++.h>
using namespace std;
char mat[60][60];
bool vis[60][60];
struct node	{
	int count;
	int cc;
};
vector<node> bear;
long long int put_values(int n)	{
	queue<pair<int,int> > q;
	bear.clear();
	node tt;
	int u,v;
	int ctr;
	int b,g,p;
	for(int i=1;i<=n;i++)	{
		for(int j=1;j<=n;j++)	{
			if(mat[i][j]=='?' && vis[i][j]==false)	{
				while(!(q.empty()))	{
					q.pop();
				}
				q.push(make_pair(i,j));
				ctr=1;
				b=g=p=0;
				vis[i][j]=true;
				while(!(q.empty()))	{
					u=q.front().first;
					v=q.front().second;
					q.pop();
					if(mat[u][v+1]=='?' && vis[u][v+1]==false)	{
						q.push(make_pair(u,v+1));
						ctr++;
						vis[u][v+1]=true;
					}
					if(mat[u][v-1]=='?' && vis[u][v-1]==false)	{
						q.push(make_pair(u,v-1));
						ctr++;
						vis[u][v-1]=true;
					}
					if(mat[u+1][v]=='?' && vis[u+1][v]==false)	{
						q.push(make_pair(u+1,v));
						ctr++;
						vis[u+1][v]=true;
					}
					if(mat[u-1][v]=='?' && vis[u-1][v]==false)	{
						q.push(make_pair(u-1,v));
						ctr++;
						vis[u-1][v]=true;
					}


					if(mat[u][v+1]=='B' && vis[u][v+1]==false)	{
						q.push(make_pair(u,v+1));
						vis[u][v+1]=true;
						b=1;
					}
					if(mat[u][v-1]=='B' && vis[u][v-1]==false)	{
						q.push(make_pair(u,v-1));
						vis[u][v-1]=true;
						b=1;
					}
					if(mat[u+1][v]=='B' && vis[u+1][v]==false)	{
						q.push(make_pair(u+1,v));
						vis[u+1][v]=true;
						b=1;
					}
					if(mat[u-1][v]=='B' && vis[u-1][v]==false)	{
						q.push(make_pair(u-1,v));
						vis[u-1][v]=true;
						b=1;
					}


					if(mat[u][v+1]=='G')	{
						return 0;
					}
					if(mat[u][v-1]=='G')	{
						return 0;
					}
					if(mat[u+1][v]=='G')	{
						return 0;
					}
					if(mat[u-1][v]=='G')	{
						return 0;
					}


					if(mat[u][v+1]=='P' && vis[u][v+1]==false)	{
						q.push(make_pair(u,v+1));
						vis[u][v+1]=true;
						p=1;
					}
					if(mat[u][v-1]=='P' && vis[u][v-1]==false)	{
						q.push(make_pair(u,v-1));
						vis[u][v-1]=true;
						p=1;
					}
					if(mat[u+1][v]=='P' && vis[u+1][v]==false)	{
						q.push(make_pair(u+1,v));
						vis[u+1][v]=true;
						p=1;
					}
					if(mat[u-1][v]=='P' && vis[u-1][v]==false)	{
						q.push(make_pair(u-1,v));
						vis[u-1][v]=true;
						p=1;
					}
				}
				if(b+p>1)	{
					return 0;
				}
				if(b==1 || p==1)	{
					tt.count=ctr;
					tt.cc=1;
					bear.push_back(tt);
				}
				if(b==0 && p==0)	{
					tt.count=ctr;
					if(ctr==1)	{
						tt.cc=3;
					}
					else	{
						tt.cc=2;
					}
					bear.push_back(tt);
				}
			}
		}
	}
	long long int summ=1;
	for(int i=0;i<bear.size();i++)	{
		summ*=bear[i].cc;
		summ=summ%1000000007;
	}
	return summ;
}
void check(int n)	{
	for(int i=1;i<=n;i++)	{
		for(int j=1;j<=n;j++)	{
			if(mat[i][j]=='B')	{
				int ch=0;
				queue<pair<int,int> > q;
				q.push(make_pair(i,j));
				vis[i][j]=true;
				while(!(q.empty()))	{
					int u=q.front().first;
					int v=q.front().second;
					q.pop();
					if(mat[u][v+1]=='B' && vis[u][v+1]==false)	{
						q.push(make_pair(u,v+1));
						vis[u][v+1]=true;
					}
					if(mat[u][v-1]=='B' && vis[u][v-1]==false)	{
						q.push(make_pair(u,v-1));
						vis[u][v-1]=true;
					}
					if(mat[u+1][v]=='B' && vis[u+1][v]==false)	{
						q.push(make_pair(u+1,v));
						vis[u+1][v]=true;
					}
					if(mat[u-1][v]=='B' && vis[u-1][v]==false)	{
						q.push(make_pair(u-1,v));
						vis[u-1][v]=true;
					}
					if(mat[u][v+1]=='G' || mat[u][v+1]=='P' || mat[u][v-1]=='G' || mat[u][v-1]=='P' || mat[u+1][v]=='G' || mat[u+1][v]=='P' ||mat[u-1][v]=='G' || mat[u-1][v]=='P')	{
						printf("0\n");
						return;
					}
				}
			}
			if(mat[i][j]=='P')	{

				int ch=0;
				queue<pair<int,int> > q;
				q.push(make_pair(i,j));
				vis[i][j]=true;
				while(!(q.empty()))	{
					int u=q.front().first;
					int v=q.front().second;
					q.pop();
					if(mat[u][v+1]=='P' && vis[u][v+1]==false)	{
						q.push(make_pair(u,v+1));
						vis[u][v+1]=true;
					}
					if(mat[u][v-1]=='P' && vis[u][v-1]==false)	{
						q.push(make_pair(u,v-1));
						vis[u][v-1]=true;
//						b=1;
					}
					if(mat[u+1][v]=='P' && vis[u+1][v]==false)	{
						q.push(make_pair(u+1,v));
						vis[u+1][v]=true;
//						b=1;
					}
					if(mat[u-1][v]=='P' && vis[u-1][v]==false)	{
						q.push(make_pair(u-1,v));
						vis[u-1][v]=true;
//						b=1;
					}
					if(mat[u][v+1]=='G' || mat[u][v+1]=='B' || mat[u][v-1]=='G' || mat[u][v-1]=='B' || mat[u+1][v]=='G' || mat[u+1][v]=='B' ||mat[u-1][v]=='G' || mat[u-1][v]=='B')	{
						printf("0\n");
						return;
					}
				}
			}
			if(mat[i][j]=='G')	{
				int u=i;
				int v=j;
				if(mat[u][v+1]=='G' || mat[u][v+1]=='P' || mat[u][v+1]=='B' ||mat[u][v-1]=='G' || mat[u][v-1]=='P' || mat[u][v-1]=='B'||mat[u+1][v]=='G' || mat[u+1][v]=='P' || mat[u+1][v]=='B' || mat[u-1][v]=='G' || mat[u-1][v]=='P' || mat[u-1][v]=='B')	{
					printf("0\n");
					return;
				}
			}
		}
	}
	printf("1\n");
	return;
}
int main()	{
	int t,n;
	string s;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d",&n);
		memset(mat,'#',sizeof(mat));
		memset(vis,false,sizeof(vis));
		for(int i=1;i<=n;i++)	{
			cin>>s;
			for(int j=1;j<=n;j++)	{
				mat[i][j]=s[j-1];
			}
		}
		int ques=0;
		for(int i=1;i<=n;i++)	{
			for(int j=1;j<=n;j++)	{
				if(mat[i][j]=='?')	{
					ques=1;
					break;
				}
			}
			if(ques==1)	{
				break;
			}
		}
		if(ques==0)	{
			check(n);
			continue;
		}
		long long int ans = put_values(n);
		printf("%lld\n",ans);
	}
	return 0;
}
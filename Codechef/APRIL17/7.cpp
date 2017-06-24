#include <bits/stdc++.h>
using namespace std;
string s;
char mat[1100][1100];
int dist[1100][1100];
struct node	{
	int x;
	int y;
}moves[5500];
struct pointer	{
	node prev;
	node next;
}positions[1100][1100];
const int inf=1e9;
bool check_boundary(int x,int y,int n)	{
	if(x<1 || x>n)	{
		return false;
	}
	if(y<1 || y>n)	{
		return false;
	}
	if(mat[x][y]=='#')	{
		return false;
	}
	return true;
}
void subtask2(int n,int l)	{
	int x=0;
	int y=0;
	for(int i=0;i<l;i++)	{
		if(s[i]=='L')	{
			y--;
		}
		else if(s[i]=='R')	{
			y++;
		}
		else if(s[i]=='U')	{
			x--;
		}
		else	{
			x++;
		}
		moves[i].x=x;
		moves[i].y=y;
	}
	for(int i=1;i<=n;i++)	{
		int ptr=l;
		for(int j=0;j<l;j++)	{
			if(moves[j].y==i*(-1))	{
				ptr=j;
				break;
			}
		}
		for(int j=1;j<=n;j++)	{
			dist[j][i]=min(dist[j][i],ptr);
		}
	}
	for(int i=n;i>=1;i--)	{
		int ptr=l;
		for(int j=0;j<l;j++)	{
			if(moves[j].y==n-i+1)	{
				ptr=j;
				break;
			}
		}
		for(int j=1;j<=n;j++)	{
			dist[j][i]=min(dist[j][i],ptr);
		}
	}
	for(int i=1;i<=n;i++)	{
		int ptr=l;
		for(int j=0;j<l;j++)	{
			if(moves[j].x==i*(-1))	{
				ptr=j;
				break;
			}
		}
		for(int j=1;j<=n;j++)	{
			dist[i][j]=min(dist[i][j],ptr);
		}
	}
	for(int i=n;i>=1;i--)	{
		int ptr=l;
		for(int j=0;j<l;j++)	{
			if(moves[j].x==n-i+1)	{
				ptr=j;
				break;
			}
		}
		for(int j=1;j<=n;j++)	{
			dist[i][j]=min(dist[i][j],ptr);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)	{
		for(int j=1;j<=n;j++)	{
			ans=ans^dist[i][j];
		}
	}
	printf("%d\n",ans);
	return;
}
void subtask3(int n,int l,int ch)	{
	node last,first;
	last.x=0;
	last.y=0;
	for(int i=1;i<=n;i++)	{
		for(int j=1;j<=n;j++)		{
			if(mat[i][j]=='.')	{
				last.x=i;
				last.y=j;
				break;
			}
		}
		if(last.x!=0 && last.y!=0)	{
			break;
		}
	}
	first.x=last.x;
	first.y=last.y;
	positions[first.x][first.y].prev.x=-1;
	positions[first.x][first.y].prev.y=-1;
	for(int i=1;i<=n;i++)	{
		for(int j=1;j<=n;j++)	{
			if(mat[i][j]=='.' && !(i==last.x && j==last.y))	{
				positions[i][j].prev.x=last.x;
				positions[i][j].prev.y=last.y;
				positions[last.x][last.y].next.x=i;
				positions[last.x][last.y].next.y=j;
				last.x=i;
				last.y=j;
			}
		}
	}
	positions[last.x][last.y].next.x=-1;
	positions[last.x][last.y].next.y=-1;
	int x=0;
	int y=0;
	for(int i=0;i<l;i++)	{
		if(s[i]=='L')	{
			y--;
		}
		else if(s[i]=='R')	{
			y++;
		}
		else if(s[i]=='U')	{
			x--;
		}
		else	{
			x++;
		}
		moves[i].x=x;
		moves[i].y=y;
	}
	node temp;
	int ans=0;
	int x1,y1,x2,y2;
	for(int i=0;i<l && ch!=0;i++)	{
		while(ch)	{
			if(check_boundary(first.x+moves[i].x,first.y+moves[i].y,n)==false)	{
				x=positions[first.x][first.y].next.x;
				y=positions[first.x][first.y].next.y;
				ans=ans^i;
				first.x=x;
				first.y=y;
				ch--;
			}
			else	{
				break;
			}
		}
		temp.x=positions[first.x][first.y].next.x;
		temp.y=positions[first.x][first.y].next.y;
		while(ch>1 && !(temp.x==-1 && temp.y==-1) && !(positions[temp.x][temp.y].next.x==-1 && positions[temp.x][temp.y].next.y==-1))	{
			if(check_boundary(temp.x+moves[i].x,temp.y+moves[i].y,n)==false)	{
				x1=positions[temp.x][temp.y].prev.x;
				y1=positions[temp.x][temp.y].prev.y;
				x2=positions[temp.x][temp.y].next.x;
				y2=positions[temp.x][temp.y].next.y;
				ans=ans^i;
				positions[x1][y1].next.x=x2;
				positions[x1][y1].next.y=y2;
				positions[x2][y2].prev.x=x1;
				positions[x2][y2].prev.y=y1;
				temp.x=x2;
				temp.y=y2;
				ch--;
			}
			else	{
				x=positions[temp.x][temp.y].next.x;
				y=positions[temp.x][temp.y].next.y;
				temp.x=x;
				temp.y=y;
			}
		}
		if(ch>1 && check_boundary(temp.x+moves[i].x,temp.y+moves[i].y,n)==false)	{
			x=positions[temp.x][temp.y].prev.x;
			y=positions[temp.x][temp.y].prev.y;
			ans=ans^i;
			positions[x][y].next.x=-1;
			positions[x][y].next.y=-1;
			ch--;
		}
	}
	temp.x=first.x;
	temp.y=first.y;
	while(temp.x!=-1 && temp.y!=-1)	{
		ans=ans^l;
		x=positions[temp.x][temp.y].next.x;
		y=positions[temp.x][temp.y].next.y;
		temp.x=x;
		temp.y=y;
	}
	printf("%d\n",ans);
	return;
}
void subtask4(int n,int l,int ch)	{
	int x=0;
	int y=0;
	for(int i=0;i<l;i++)	{
		if(s[i]=='L')	{
			y--;
		}
		else if(s[i]=='R')	{
			y++;
		}
		else if(s[i]=='U')	{
			x--;
		}
		else	{
			x++;
		}
		moves[i].x=x;
		moves[i].y=y;
	}
	int ans=0;
	for(int i=1;i<=n;i++)	{
		for(int j=1;j<=n;j++)	{
			if(mat[i][j]=='.')	{
				dist[i][j]=l;
			}
		}
	}
	for(int i=0;i<=n+1;i++)	{
		for(int j=0;j<=n+1;j++)	{
			if(mat[i][j]=='#')	{
				for(int k=0;k<l;k++)	{
					if(check_boundary(i-moves[k].x,j-moves[k].y,n))	{
						if(k<dist[i-moves[k].x][j-moves[k].y])	{
							dist[i-moves[k].x][j-moves[k].y]=k;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)	{
		for(int j=1;j<=n;j++)	{
			if(mat[i][j]=='.')	{
				ans=ans^dist[i][j];
			}
		}
//		cout<<endl;
	}
	cout<<ans<<endl;
	return;
}
int main()	{
	int t,n,l;
	int cntbar;
	string temp;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d %d",&l,&n);
		cin>>s;
		int ans=0;
		for(int i=0;i<=n+1;i++)	{
			mat[0][i]='#';
			mat[n+1][i]='#';
			mat[i][0]='#';
			mat[i][n+1]='#';
		}
		cntbar=0;
		for(int i=1;i<=n;i++)	{
			cin>>temp;
			for(int j=1;j<=n;j++)	{
				mat[i][j]=temp[j-1];
				if(mat[i][j]=='#')	{
					cntbar++;
				}
			}
		}
		double p=(cntbar*1.0)/pow(n,2);
		if(n<=10 || p>=0.1)	{
			for(int i=1;i<=n;i++)	{
				for(int j=1;j<=n;j++)	{
					dist[i][j]=inf;
				}
			}
			for(int i=1;i<=n;i++)	{
				for(int j=1;j<=n;j++)	{
					int x=i;
					int y=j;
					if(mat[i][j]=='#')	{
						continue;
					}
					int ctr=0;
					for(int k=0;k<l;k++)	{
						if(s[k]=='L')	{
							y--;
						}
						else if(s[k]=='D')	{
							x++;
						}
						else if(s[k]=='R')	{
							y++;
						}
						else	{
							x--;
						}
						if(mat[x][y]=='#')	{
							dist[i][j]=ctr;
							break;
						}
						else	{
							ctr++;
						}
					}
					dist[i][j]=min(dist[i][j],ctr);
					ans=ans^dist[i][j];
				}
			}
			printf("%d\n",ans);
		}
		else if(p==0.0)	{
			for(int i=1;i<=n;i++)	{
				for(int j=1;j<=n;j++)	{
					dist[i][j]=inf;
				}
			}
			subtask2(n,l);
//			subtask3(n,l,n*n-cntbar);
		}
		else	{
//			subtask3(n,l,n*n-cntbar);
			subtask4(n,l,cntbar);
		}
	}
	return 0;
}
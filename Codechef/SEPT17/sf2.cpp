#include <bits/stdc++.h>
using namespace std;
int n;
int mat[110][110];
bool flag[110][110];
struct node	{
	int a1,a2,b1,b2,c1,c2,d,l,r;
};
vector<node> query;
void clear(int n)	{
	for(int i=0;i<n;i++)	{
		for(int j=0;j<n;j++)	{
			flag[i][j]=false;
		}
	}
	query.clear();
}
bool totflag;
void call_print()	{
	cout<<(int)query.size()<<endl;
	for(int i=0;i<query.size();i++)	{
		printf("%d %d %d %d %d %d %d %d %d\n",query[i].a1,query[i].a2,query[i].b1,query[i].b2,query[i].c1,query[i].c2,query[i].d,query[i].l,query[i].r);
	}
	totflag=true;
}
int main()	{
	int t;
	string s;
	cin>>t;
	while(t--)	{
		totflag=false;
		cin>>n;
		clear(n);
		for(int i=0;i<n;i++)	{
			cin>>s;
			for(int j=0;j<n;j++)	{
				mat[i][j]=(s[j]=='0')?0:1;
			}
		}
		int cntone=0;
		for(int i=0;i<n;i++)	{
			for(int j=0;j<n;j++)	{
				if(mat[i][j]==1)	{
					cntone++;
				}
			}
		}
		if(cntone<=100)	{
			cout<<"0\n";
			continue;
		}
		node temp;
//		cout<<"ER";
		for(int i=0;i<n;i++)	{
			int st=-1,en=-1;
			if(mat[0][i]==1)	{
				st=0;
				en=0;
			}
			for(int j=1;j<n;j++)	{
				if(mat[j][i]==1)	{
					if(mat[j-1][i]==0)	{
						st=j;
						en=j;
					}
					else	{
						en++;
					}
				}
				if(mat[j][i]==0)	{
					if(mat[j-1][i]==1)	{
						if(en-st>0)	{
							temp.a1=0;
							temp.a2=1;
							temp.b1=0;
							temp.b2=1;
							temp.c1=0;
							temp.c2=1;
							temp.d=i+1;
							temp.l=st+1;
							temp.r=en+1;
							for(int k=st;k<=en;k++)	{
								flag[k][i]=true;
							}
							cntone-=(en-st+1);
							query.push_back(temp);
							if(cntone<=100)	{
								call_print();
								break;
							}
						}
					}
				}
				if(en==n-1)	{
					if(en-st>0)	{
						temp.a1=0;
						temp.a2=1;
						temp.b1=0;
						temp.b2=1;
						temp.c1=0;
						temp.c2=1;
						temp.d=i+1;
						temp.l=st+1;
						temp.r=en+1;
						for(int k=st;k<=en;k++)	{
							flag[k][i]=true;
						}
						cntone-=(en-st+1);
						query.push_back(temp);
						if(cntone<=100)	{
								call_print();
								break;
						}
					}
				}
				if(totflag==true)	{
					break;
				}

			}
			if(totflag==true)	{
				break;
			}
			if(en==n-1)	{
				if(en-st>0)	{
					temp.a1=0;
					temp.a2=1;
					temp.b1=0;
					temp.b2=1;
					temp.c1=0;
					temp.c2=1;
					temp.d=i+1;
					temp.l=st+1;
					temp.r=en+1;
					for(int k=st;k<=en;k++)	{
						flag[k][i]=true;
					}
					cntone-=(en-st+1);
					query.push_back(temp);
					if(cntone<=100)	{
							call_print();
							break;
					}
				}
			}
			if(totflag==true)	{
				break;
			}
		}
		if(totflag==true)	{
			continue;
		}
		for(int i=0;i<n;i++)	{
			for(int j=0;j<n;j++)	{
				if(mat[i][j]==1 && flag[i][j]==false)	{
					temp.a1=0;
					temp.a2=1;
					temp.b1=0;
					temp.b2=1;
					temp.c1=0;
					temp.c2=1;
					temp.d=j+1;
					temp.l=i+1;
					temp.r=i+1;
					query.push_back(temp);
					cntone--;
					if(cntone<=100)	{
						call_print();
						break;
					}
				}
			}
			if(totflag==true)	{
				break;
			}
		}
	}
	return 0;
} 

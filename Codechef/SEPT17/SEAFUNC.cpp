#include <bits/stdc++.h>
using namespace std;
int n;
int mat[110][110];
bool flag[110][110],copy1[110][110],copy2[110][110];
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
					int fi=i+1;int fj=j+1;
					int fcct=1,bcct=1;
					int fcc=1,bcc=1;
					int l1=i,l2=i,r1=i,r2=i;
					while(fi<n && fj<n)	{
						if(mat[fi][fj]==1)	{
							fcc++;
							r2++;
							if(flag[fi][fj]==false)	{
								fcct++;
							}
						}
						else	{
							break;
						}
						fi++;
						fj++;
					}
					fi=i+1;fj=j-1;
					while(fi<n && fj>=0)	{
						if(mat[fi][fj]==1)	{
							bcc++;
							l2++;
							if(flag[fi][fj]==false)	{
								bcct++;
							}
						}
						else	{
							break;
						}
						fi++;
						fj--;
					}
					fi=i-1;fj=j+1;
					while(fi>=0 && fj<n)	{
						if(mat[fi][fj]==1)	{
							bcc++;
							l1--;
							if(flag[fi][fj]==false)	{
								bcct++;
							}
						}
						else	{
							break;
						}
						fi--;
						fj++;
					}
					fi=i-1;fj=j-1;
					while(fi>=0 && fj>=0)	{
						if(mat[fi][fj]==1)	{
							fcc++;
							r1--;
							if(flag[fi][fj]==false)	{
								fcct++;
							}
						}
						else	{
							break;
						}
						fi--;
						fj--;
					}
					if(fcct>=3)	{
						temp.a1=0;
						temp.a2=1;
						temp.b1=0;
						temp.b2=1;
						temp.c1=1;
						temp.c2=1;
						temp.d=i-j;
						temp.l=r1+1;
						temp.r=r2+1;
						for(int k=r1;k<=r2;k++)	{
							flag[k][k+i-j]=true;
						}
						query.push_back(temp);
						cntone-=fcct;
						if(cntone<=100)	{
							call_print();
							break;
						}
					}		
					if(bcct>=3)	{
						temp.a1=0;
						temp.a2=1;
						temp.b1=0;
						temp.b2=1;
						temp.c1=-1;
						temp.c2=1;
						temp.d=i+j+2;
						temp.l=l1+1;
						temp.r=l2+1;
						for(int k=l1;k<=l2;k++)	{
							flag[k][i+j-k]=true;
						}
						query.push_back(temp);
//						cout<<cntone<<endl;
						cntone-=bcct;
						if(cntone<=100)	{
							call_print();
							break;
						}
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
		//points
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
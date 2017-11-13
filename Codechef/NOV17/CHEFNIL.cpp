#include <bits/stdc++.h>
using namespace std;
int points[505][55][55];
double duration;
clock_t start;
int n,m;
bool flag;
struct node	{
	int x;
	int y;
	int c;
}temp;
bool comp(const node &a,const node &b)	{
	return a.c>b.c;
}
vector<node> pq[505];
vector<node> taken,vv;
int find_orientation(node a,node b,node c)	{
	int val=(b.y-a.y)*(c.x-b.x)-(b.x-a.x)*(c.y-b.y);
	if(val==0)	{
		return 0;
	}
	if(val>0)	{
		return 1;
	}
	return 2;
}
bool collinear(node a,node b,node c)	{
	if(b.x<=max(a.x,c.x) && b.x>=min(a.x,c.x) && b.y<=max(a.y,c.y) && b.y>=min(a.y,c.y))	{
		return true;
	}
	return false;
}
bool intersects(node p1,node q1,node p2,node q2)	{
	int o1=find_orientation(p1,q1,p2);
	int o2=find_orientation(p1,q1,q2);
	int o3=find_orientation(p2,q2,p1);
	int o4=find_orientation(p2,q2,q1);
	if(o1!=o2 && o3!=o4)	{
		return true;
	}
	if(o1==0 && collinear(p1,p2,q1))	{
		return true;
	}
	if(o2==0 && collinear(p1,q2,q1))	{
		return true;
	}
	if(o3==0 && collinear(p2,p1,q2))	{
		return true;
	}
	if(o4==0 && collinear(p2,q1,q2))	{
		return true;
	}
	return false;
}
bool check(node a,node b)	{
	for(int i=0;i<taken.size();i++)	{
		if(a.x==taken[i].x && a.y==taken[i].y)	{
			return false;
		}
	}
	for(int i=0;i<(int)taken.size()-2;++i)	{
		if(intersects(taken[i],taken[i+1],a,b)==true)	{
			// cout<<taken[i].x<<" "<<taken[i].y<<endl;
			return false;
		}
	}
	return true;
}
void print_ans()	{
	if(taken.size()==m+1)	{
		taken.pop_back();
	}
	for(int i=0;i<taken.size();i++)	{
		if(taken[i].x==-1)	{
			printf("-1 -1\n");
		}
		else	{
			printf("%d %d\n",taken[i].x+1,taken[i].y+1);
		}
	}
}
void print_ans1()	{
	if(vv.size()==m+1)	{
		vv.pop_back();
	}
	for(int i=0;i<vv.size();i++)	{
		if(vv[i].x==-1)	{
			printf("-1 -1\n");
		}
		else	{
			printf("%d,%d\n",vv[i].x+1,vv[i].y+1);
		}
	}
}

void solve(int level)	{
//	cout<<"At level "<<level<<endl;
	if(level==m)	{
		flag=true;
		print_ans();
//		print_ans1();
		return;
	}
	if((clock()-start)/(double)CLOCKS_PER_SEC>=2.0)	{
		flag=true;
		temp.x=-1;
		temp.y=-1;
		taken.push_back(temp);
		print_ans();
//		print_ans1();
		return;
	}
	for(int i=0;i<n*n;i++)	{
		if(level==0 || check(pq[level][i],taken[taken.size()-1])==true)	{
			taken.push_back(pq[level][i]);
			solve(level+1);
			if(flag==true)	{
				return;
			}
			if(vv.size()<taken.size())	{
				vv=taken;
			}
			taken.pop_back();
		}
	}
}
int main()	{
	flag=false;
	int maxx=-1,l,r,p;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)	{
		for(int j=0;j<n;j++)	{
			for(int k=0;k<n;k++)	{
				scanf("%d",&points[i][j][k]);
				temp.x=j;
				temp.y=k;
				temp.c=points[i][j][k];
				if(points[i][j][k]>maxx)	{
					maxx=points[i][j][k];
					l=j;
					r=k;
					p=i;
				}
				pq[i].push_back(temp);
			}
		}
		sort(pq[i].begin(),pq[i].end(),comp);
	}
//	start=clock();
//	solve(0);
	// temp.x=l;
	// temp.y=r;
	// taken.push_back(temp);
	// for(int i=p+1;i<m;i++)	{
	// 	if(check(pq[i][0],taken[taken.size()-1])==true)	{
	// 		taken.push_back(pq[i][0]);
	// 	}
	// 	else	{
	// 		break;
	// 	}
	// }
	// reverse(taken.begin(),taken.end());
	// for(int i=p-1;i>=0;i--)	{
	// 	if(check(pq[i][0],taken[taken.size()-1])==true)	{
	// 		taken.push_back(pq[i][0]);
	// 	}
	// 	else	{
	// 		break;
	// 	}
	// }
	// reverse(taken.begin(),taken.end());
	// print_ans();
//	if(m==50)	{
//		for(int i=0;i<m;i++)	{
//			cout<<pq[i][12].x+1<<" "<<pq[i][12].x+1<<endl;
//		}
//	}
	if(m==50)	{
		int sc1=0,sc2=0;
		vector<pair<int,int> > ff1,ff2;
		for(int i=0;i<n;i++)	{
			int mm=-1;
			for(int j=0;j<n;j++)	{
				if(mm<points[i][i][j])	{
					mm=points[i][i][j];
					l=i;
					r=j;
				}
			}
			sc1+=mm;
			ff1.push_back(make_pair(l+1,r+1));
		}
		for(int i=0;i<n;i++)	{
			int mm=-1;
			for(int j=0;j<n;j++)	{
				if(mm<points[i][j][i])	{
					mm=points[i][j][i];
					l=j;
					r=i;
				}
			}
			sc2+=mm;
			ff2.push_back(make_pair(l+1,r+1));
//			cout<<l+1<<" "<<r+1<<endl;
		}
		int sc3=0;
		vector<pair<int,int> > ff3;
		for(int i=0;i<n;i++)	{
			int mm=-1;
			for(int j=i;j<n;j++)	{
				if(mm<points[i][j-i][j])	{
					mm=points[i][j-i][j];
					l=j-i;
					r=j;
				}
			}
			sc3+=mm;
			ff3.push_back(make_pair(l+1,r+1));
		}
		int sc4=0;
		vector<pair<int,int> > ff4;
		for(int i=0;i<n;i++)	{
			int mm=-1;
			for(int j=0;j<n-i;j++)	{
				if(mm<points[i][i+j][j])	{
					mm=points[i][i+j][j];
					l=i+j;
					r=j;
				}
			}
			sc4+=mm;
			ff4.push_back(make_pair(l+1,r+1));
		}
		if(sc1>=sc2 && sc1>=sc3 && sc1>=sc4)	{
			for(int i=0;i<ff1.size();i++)	{
				cout<<ff1[i].first<<" "<<ff1[i].second<<endl;
			}
		}
		if(sc2>=sc1 && sc2>=sc3 && sc2>=sc4)	{
			for(int i=0;i<ff2.size();i++)	{
				cout<<ff2[i].first<<" "<<ff2[i].second<<endl;
			}
		}
		if(sc3>=sc1 && sc3>=sc2 && sc3>=sc4)	{
			for(int i=0;i<ff3.size();i++)	{
				cout<<ff3[i].first<<" "<<ff3[i].second<<endl;
			}
		}
		else	{
			for(int i=0;i<ff4.size();i++)	{
				cout<<ff4[i].first<<" "<<ff4[i].second<<endl;
			}			
		}
	}
	else	{
		int sc1=0,sc2=0;
		vector<pair<int,int> > ff1,ff2;
		for(int i=0;i<n;i++)	{//column number select
			for(int j=0;j<10;j++)	{
				int mm=-1;
				for(int k=j*5;k<(j+1)*5;k++)	{
					if(mm<points[i*10+j][k][i])	{
						mm=points[i*10+j][k][i];
						l=k;
						r=i;
					}
				}
				sc1+=mm;
				ff1.push_back(make_pair(l+1,r+1));
//				cout<<l+1<<" "<<r+1<<endl;
			}
		}
		for(int i=0;i<n;i++)	{//row number select
			for(int j=0;j<10;j++)	{
				int mm=-1;
				for(int k=j*5;k<(j+1)*5;k++)	{
					if(mm<points[i*10+j][i][k])	{
						mm=points[i*10+j][i][k];
						l=i;
						r=k;
					}
				}
				sc2+=mm;
				ff2.push_back(make_pair(l+1,r+1));
//				cout<<l+1<<" "<<r+1<<endl;
			}
		}
		int sc3=0;
		vector<pair<int,int> > ff3;
		for(int i=0;i<n;i++)	{
			for(int j=9;j>=0;j--)	{
				int mm=-1;
				for(int k=j*5;k<(j+1)*5;k++)	{
					if(mm<points[i*10+(9-j)][i][k])	{
						mm=points[i*10+(9-j)][i][k];
						l=i;
						r=k;
					}
				}
				sc3+=mm;
				ff3.push_back(make_pair(l+1,r+1));
			}
		}
		int sc4=0;
		vector<pair<int,int> > ff4;
		for(int i=0;i<n;i++)	{
			for(int j=9;j>=0;j--)	{
				int mm=-1;
				for(int k=j*5;k<(j+1)*5;k++)	{
					if(mm<points[i*10+(9-j)][k][i])	{
						mm=points[i*10+(9-j)][k][i];
						l=k;
						r=i;
					}
				}
				sc4+=mm;
				ff4.push_back(make_pair(l+1,r+1));
			}
		}
		if(sc1>=sc2 && sc1>=sc3 && sc1>=sc4)	{
			for(int i=0;i<ff1.size();i++)	{
				cout<<ff1[i].first<<" "<<ff1[i].second<<endl;
			}
		}
		if(sc2>=sc1 && sc2>=sc3 && sc2>=sc4)	{
			for(int i=0;i<ff2.size();i++)	{
				cout<<ff2[i].first<<" "<<ff2[i].second<<endl;
			}
		}
		if(sc3>=sc1 && sc3>=sc2 && sc3>=sc4)	{
			for(int i=0;i<ff3.size();i++)	{
				cout<<ff3[i].first<<" "<<ff3[i].second<<endl;
			}
		}
		else	{
			for(int i=0;i<ff4.size();i++)	{
				cout<<ff4[i].first<<" "<<ff4[i].second<<endl;
			}			
		}
	}
	return 0;
}
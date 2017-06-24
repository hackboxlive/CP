#include <bits/stdc++.h>
using namespace std;
long long dp[2710][2710];
long long inf=(long long)1e15;
long long f1[20010][6];
long long f2[200010][5];
struct node	{
	long long m;
	int index;
	vector<pair<long long,long long> > ans;
}query[110];
bool comp(const pair<long long,long long> &a,const pair<long long,long long> &b)	{
	if(a.first==b.first)	{
		return a.second<b.second;
	}
	return a.first<b.first;
}
bool comp2(const node &p1,const node &p2)	{
	return p1.m<p2.m;
}
bool comp3(const node &p3,const node &p4)	{
	return p3.index<p4.index;
}
void compute(int t)	{
	long long temp;
	long long lo;
	long long hi;
	long long mid;
	long long vv;
	for(int i=0;i<t;i++)	{
		temp=query[i].m;
		lo=200000+1;
		hi=45000000;
//		cout<<"for query="<<query[i].m<<endl;
		while(lo<=hi)	{
			mid=(lo+hi)/2;
//			cout<<lo<<" "<<mid<<" "<<hi<<endl;
			vv=mid*(mid-1);
			vv/=2;
			if(vv==temp)	{
				query[i].ans.push_back(make_pair(mid,2));
				query[i].ans.push_back(make_pair(mid,mid-2));
				break;
			}
			else if(vv<temp)	{
				lo=mid+1;
			}
			else	{
				hi=mid-1;
			}
		}
	}
}
int main()	{
	int t;
	for(int i=2;i<=2700;i++)	{
		dp[i][1]=i;
	}
	for(int i=4;i<=2700;i++)	{
		for(int j=2;j<=i/2;j++)	{
			if(dp[i][j-1]>inf)	{
				break;
			}
			dp[i][j]=(long long)dp[i][j-1]*(i-j+1);
			dp[i][j]=dp[i][j]/j;
		}
	}
	for(int i=2701;i<=20000;i++)	{
		f1[i][1]=i;
	}
	for(int i=20001;i<=200000;i++)	{
		f2[i][1]=i;
	}
	for(int i=2701;i<=20000;i++)	{
		for(int j=2;j<=4;j++)	{
			if(f1[i][j-1]>inf)	{
				break;
			}
			f1[i][j]=(long long)f1[i][j-1]*(i-j+1);
			f1[i][j]=f1[i][j]/j;
		}
	}
	for(int i=20001;i<=200000;i++)	{
		for(int j=2;j<=3;j++)	{
			if(f2[i][j-1]>inf)	{
				break;
			}
			f2[i][j]=(long long)f2[i][j-1]*(i-j+1);
			f2[i][j]=f2[i][j]/j;
		}
	}
	cin>>t;
	int tt=0;
	while(tt<t)	{
		long long m;
		cin>>m;
		query[tt].m=m;
		query[tt].index=tt;
		tt++;
	}
	sort(query,query+tt,comp2);
	long long temp;
	for(int i=0;i<t;i++)	{
		temp=query[i].m;
		query[i].ans.push_back(make_pair(temp,1));
		if(temp-1!=1)	{
			query[i].ans.push_back(make_pair(temp,temp-1));
		}
	}
	int ctr=0;
	int i;
	for(int j=2;j<=3;j++)	{
		ctr=0;
		i=20001;
		while(ctr<t && i<=200000)	{
			if(f2[i][j]==query[ctr].m)	{
				query[ctr].ans.push_back(make_pair(i,j));
				query[ctr].ans.push_back(make_pair(i,i-j));
				ctr++;
			}
			else if(f2[i][j]<query[ctr].m)	{
				i++;
			}
			else	{
				ctr++;
			}
		}
	}
	for(int j=2;j<=4;j++)	{
		ctr=0;
		i=2701;
		while(ctr<t && i<=20000)	{
			if(f1[i][j]==query[ctr].m)	{
				query[ctr].ans.push_back(make_pair(i,j));
				query[ctr].ans.push_back(make_pair(i,i-j));
				ctr++;
			}
			else if(f1[i][j]<query[ctr].m)	{
				i++;
			}
			else	{
				ctr++;
			}
		}
	}
	for(int j=2;j<=2700;j++)	{
		ctr=0;
		i=4;
		while(ctr<t && i<=2700)	{
			if(dp[i][j]==query[ctr].m)	{
				query[ctr].ans.push_back(make_pair(i,j));
				if(j!=i-j)	{
					query[ctr].ans.push_back(make_pair(i,i-j));
				}
				ctr++;
			}
			else if(dp[i][j]<query[ctr].m)	{
				i++;
			}
			else	{
				ctr++;
			}
		}
	}
	compute(t);
	for(int i=0;i<t;i++)	{
		sort(query[i].ans.begin(),query[i].ans.end(),comp);
	}
	sort(query,query+t,comp3);
	for(i=0;i<t;i++)	{
		cout<<(int)query[i].ans.size()<<endl;
		for(int j=0;j<query[i].ans.size();j++)	{
			cout<<"("<<query[i].ans[j].first<<","<<query[i].ans[j].second<<") ";
		}
		cout<<endl;
	}
	return 0;
}
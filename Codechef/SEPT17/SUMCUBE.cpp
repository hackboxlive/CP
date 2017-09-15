#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > graph[100100];
vector<pair<int,int> > edges;
map<pair<int,int> , bool> mp;
long long two[100100];
long long deg[100100];
long long totdeg[100100];
vector<int> heavy;
vector<int> light;
const long long modu=1000000007;
long long sqrtm;
bool comp(const pair<int,int> &a,const pair<int,int> &b)	{
	return a.second<b.second;
}
void precompute()	{
	two[0]=1;
	for(int i=1;i<=100000;i++)	{
		two[i]=two[i-1]*2;
		two[i]%=modu;
	}
}
long long testprecompute(int n,int m)	{
	for(int i=1;i<=n;i++)	{
		deg[i]=(int)graph[i].size();
		if(deg[i]>=sqrtm)	{
			heavy.push_back(i);
		}
		else	{
			light.push_back(i);
		}
	}
	int u,v;
	long long ans=0;
	for(int i=0;i<m;i++)	{
		u=edges[i].first;
		v=edges[i].second;
		ans+=deg[u];
		ans+=deg[v];
		ans-=2;
	}
	for(int i=1;i<=n;i++)	{
		totdeg[i]=0;
		for(int j=0;j<deg[i];j++)	{
			totdeg[i]+=deg[graph[i][j].first];
		}
	}
	return ans;
}
long long onetwoedge(int n,int m,int k)	{
	long long cur=0,fin=0,extra=0;
	int u,v;
	for(int i=0;i<m;i++)	{
		u=edges[i].first;
		v=edges[i].second;
		cur=deg[u]+deg[v]-2;
		extra+=(m-1-cur);
		fin+=cur;
	}
	extra/=2;
	fin/=2;
	long long ans=0;
	ans=two[n-2]*m;
//	cout<<m<<" "<<two[n-2]<<endl;

//	cout<<ans<<endl;
	ans%=modu;
	if(n>2)	{
		long long temp=two[n-3]*k;
		temp%=modu;
		temp*=fin;
		temp%=modu;
		ans+=temp;
		ans%=modu;
	}
	if(n>3)	{
		long long temp=two[n-4]*k;
		temp%=modu;
		temp*=extra;
		temp%=modu;
		ans+=temp;
		ans%=modu;
	}
	return ans;
}
long long trianglecount(int n,int m)	{
	long long cnt=0;
	int u,v,w;
	for(int i=0;i<heavy.size();i++)	{
		u=heavy[i];
		for(int j=i+1;j<heavy.size();j++)	{
			v=heavy[j];
			for(int k=j+1;k<heavy.size();k++)	{
				w=heavy[k];
				if(mp.find(make_pair(u,v))!=mp.end() && mp.find(make_pair(v,w))!=mp.end() && mp.find(make_pair(u,w))!=mp.end())	{
					cnt++;
				}
			}
		}
	}
	int hl=0;
	for(int i=0;i<heavy.size();i++)	{
		u=heavy[i];
		for(int j=0;j<m;j++)	{
			v=edges[j].first;
			w=edges[j].second;
			if(u!=v && u!=w)	{
				if(deg[v]<sqrtm && deg[w]<sqrtm)	{
					if(mp.find(make_pair(u,v))!=mp.end() && mp.find(make_pair(u,w))!=mp.end())	{
						cnt++;
					}
				}
				if((deg[v]>=sqrtm && deg[w]<sqrtm) || (deg[v]<sqrtm && deg[w]>=sqrtm))	{
					if(mp.find(make_pair(u,v))!=mp.end() && mp.find(make_pair(u,w))!=mp.end())	{
						hl++;
					}				
				}
			}
		}
	}
	hl/=2;
	cnt+=hl;
	hl=0;
	for(int i=0;i<edges.size();i++)	{
		u=edges[i].first;
		v=edges[i].second;
		if(deg[u]<sqrtm && deg[v]<sqrtm)	{
			for(int j=0;j<deg[u];j++)	{
				w=graph[u][j].first;
				if(deg[w]<sqrtm)	{
					if(mp.find(make_pair(v,w))!=mp.end())	{
						hl++;
					}
				}
			}
		}
	}
	hl/=3;
	cnt+=hl;
	return cnt;
}
long long treecount(int n,int m)	{
	long long cnt=0;
	int u,v;
	long long temp,claw=0,straight=0;
	for(int i=0;i<m;i++)	{
		u=edges[i].first;
		v=edges[i].second;
		temp=deg[u]-1;
		temp*=(deg[v]-1);
		straight+=temp;
		temp=deg[u]-1;
		temp*=(temp-1);
		temp/=2;
		claw+=temp;
		temp=deg[v]-1;
		temp*=(temp-1);
		temp/=2;
		claw+=temp;
	}
	claw/=3;
	cnt=claw+straight;
	return cnt;
}
long long mC3(int n)	{
	long long ans=1;
	ans*=n;
	ans*=(n-1);
	ans*=(n-2);
	ans/=6;
	return ans;
}
int main()	{
	int t;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	precompute();
	cin>>t;
	while(t--)	{
		int n,m,k,u,v;
		cin>>n>>m>>k;
		sqrtm=sqrt(m)+50;
		for(int i=0;i<m;i++)	{
			cin>>u>>v;
			graph[u].push_back(make_pair(v,i));
			graph[v].push_back(make_pair(u,i));
			edges.push_back(make_pair(u,v));
			mp[make_pair(u,v)]=true;
			mp[make_pair(v,u)]=true;
		}
		for(int i=1;i<=n;i++)	{
			sort(graph[i].begin(),graph[i].end(),comp);
		}
		if(k==1)	{
			long long ans=m;
			ans=ans*two[n-2];
			ans%=modu;
			cout<<ans<<endl;
		}
		if(k==2)	{
			long long twopair=testprecompute(n,m);
			long long ans=onetwoedge(n,m,2);
			cout<<ans<<endl;
		}
		if(k==3)	{
			long long twopair=testprecompute(n,m);
			twopair/=2;
			long long ans=onetwoedge(n,m,6);
			long long tricnt=trianglecount(n,m);
			long long treecnt=treecount(n,m);
			treecnt-=(3*tricnt);
			long long tosub=0;
			for(int i=0;i<m;i++)	{
				u=edges[i].first;
				v=edges[i].second;
				tosub+=((long long)(deg[u]+deg[v]-2)*(deg[u]+deg[v]-2));
				tosub+=totdeg[v]-deg[u];
				tosub+=totdeg[u]-deg[v];
			}
			tosub/=2;
			long long fivenode=m*twopair;
			fivenode-=tosub;
			fivenode+=(3*tricnt);
			long long sixnode=mC3(m);
			sixnode-=treecnt;
			sixnode-=tricnt;
			sixnode-=fivenode;
//			cout<<tricnt<<" "<<treecnt<<" "<<fivenode<<" "<<sixnode<<endl;
//			cout<<ans<<endl;
			if(n>2)	{
				tosub=6*two[n-3];
				tosub%=modu;
				tricnt%=modu;
				tosub*=tricnt;
				tosub%=modu;
				ans+=tosub;
				ans%=modu;
			}
//			cout<<ans<<endl;
			if(n>3)	{
				tosub=6*two[n-4];
				tosub%=modu;
				treecnt%=modu;
				tosub*=treecnt;
				tosub%=modu;
				ans+=tosub;
				ans%=modu;
			}
//			cout<<ans<<endl;
			if(n>4)	{
				tosub=6*two[n-5];
				tosub%=modu;
				fivenode%=modu;
				tosub*=fivenode;
				tosub%=modu;
				ans+=tosub;
				ans%=modu;
			}
//			cout<<ans<<endl;
			if(n>5)	{
				tosub=6*two[n-6];
				tosub%=modu;
				sixnode%=modu;
				tosub*=sixnode;
				tosub%=modu;
				ans+=tosub;
				ans%=modu;
			}
//			if(n<=15)	{
//				printf("%lld\n",computesmall(n));
//			}
//			else	{
//				printf("%lld\n",ans);
//			}
			cout<<ans<<endl;
		}
		for(int i=1;i<=n;i++)	{
			graph[i].clear();
		}
		edges.clear();
		heavy.clear();
		light.clear();
		mp.clear();
	}
	return 0;
}
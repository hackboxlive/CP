#include <bits/stdc++.h>
using namespace std;
long long tree[6006000];
int b[1000100];
long long p;
int dp[6006000][12];
vector<pair<int,int> > factors;
void precompute()	{
	long long temp = p;
	int ctr=0;
	if(temp%2==0)	{
		ctr=0;
		while(temp%2==0)	{
			temp/=2;
			ctr++;
		}
		factors.push_back(make_pair(2,ctr));
	}
	for(int i=3;i<=sqrt(temp);i+=2)	{
		if(temp%i==0)	{
			ctr=0;
			while(temp%i==0)	{
				temp/=i;
				ctr++;
			}
			factors.push_back(make_pair(i,ctr));
		}
	}
	if(temp>2)	{
		factors.push_back(make_pair(temp,1));
	}
}
void build_dp(int pos,int v)	{
	int ctr;
	for(int i=0;i<factors.size();i++)	{
		if(v%factors[i].first==0)	{
			ctr=0;
			while(v%factors[i].first==0)	{
				v/=factors[i].first;
				ctr++;
			}
			dp[pos][i]=ctr;
		}
		else	{
			dp[pos][i]=0;
		}
	}
}
void build_again(int n)	{
	for(int i=0;i<factors.size();i++)	{
		for(int j=1;j<n;j++)	{
			dp[j][i]+=dp[j-1][i];
		}
	}
}
void build(int id,int l,int r,int pos, int v)	{
	if(l>pos || r<pos)	{
		return;
	}
	if(l==pos && r==pos)	{
		tree[id]=v;
		return;
	}
	build(2*id,l,(l+r)/2,pos,v);
	build(2*id+1,(l+r)/2+1,r,pos,v);
	tree[id]=tree[2*id]*tree[2*id+1];
	tree[id]%=p;
}
long long query(int id,int s,int e,int l,int r)	{
	if(s>r || e<l)	{
		return 1;
	}
	if(s>=l && e<=r)	{
		return tree[id];
	}
	return (query(2*id,s,(s+e)/2,l,r)*query(2*id+1,(s+e)/2+1,e,l,r))%p;
}
int main()	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)	{
		int n,q,v;
		cin>>n>>p>>q;
		precompute();
		for(int i=0;i<n;i++)	{
			cin>>v;
			build_dp(i,v);
			build(1,0,n-1,i,v);
		}
		build_again(n);
		int bs=q/64+2;
		for(int i=0;i<bs;i++)	{
			cin>>b[i];
		}
		long long x=0;
		int l,r;
		for(int i=0;i<q;i++)	{
			if(i%64==0)	{
				l=(b[i/64]+x)%n;
				r=(b[i/64+1]+x)%n;
			}
			else	{
				l=(l+x)%n;
				r=(r+x)%n;
			}
			if(l>r)	{
				swap(l,r);
			}
			if(l==0)	{
				v=0;
				for(int j=0;j<factors.size();j++)	{
					if(dp[r][j]>=factors[j].second)	{
						v++;
					}
				}
			}
			else	{
				v=0;
				for(int j=0;j<factors.size();j++)	{
					if(dp[r][j]-dp[l-1][j]>=factors[j].second)	{
						v++;
					}
				}
			}
			if(v<factors.size())	{
				x=query(1,0,n-1,l,r);
			}
			else	{
				x=0;
			}
			x++;
			x%=p;
		}
		cout<<x<<endl;
	}
	return 0;
}
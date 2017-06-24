#include <stdio.h>
int inf=1e9;
int maxx=1e6;
int primes[1000010];
int arr[100100];
int dist[1000010];
struct nd	{
	int freq;
	int first;
	int second;
}occur[1000010];
int ans[100100];
struct ndd	{
	int fdist;
	int sdist;
	int fpos;
	int spos;
}data[1000010];
int ad[100100];
void sieve()	{
	for(int i=2;i<=maxx;i++)	{
		if(primes[i]==0){
			for(int j=i;j<=maxx;j+=i)	{
				if(primes[j]==0)	{
					primes[j]=i;
				}
			}
		}
	}
	dist[0]=dist[1]=1;
	for(int i=2;i<=maxx;i++)	{
		dist[i]=dist[i/primes[i]]+1;
	}
}
void precompute()	{
	for(int i=1;i<=maxx;i++)	{
		data[i].fdist=data[i].sdist=inf;
	}
	int d;
	for(int i=1;i<=maxx;i++)	{
		for(int j=i;j<=maxx;j+=i)	{
			if(occur[j].freq>0)	{
				d=dist[j]-dist[i];
				if(d<data[i].fdist)	{
					data[i].sdist=data[i].fdist;
					data[i].spos=data[i].fpos;
					data[i].fdist=d;
					data[i].fpos=occur[j].first;
				}
				else if(d==data[i].fdist && occur[j].first<data[i].fpos)	{
					data[i].sdist=data[i].fdist;
					data[i].spos=data[i].fpos;
					data[i].fdist=d;
					data[i].fpos=occur[j].first;					
				}
				else if(d<data[i].sdist)	{
					data[i].sdist=d;
					data[i].spos=occur[j].first;
				}
				else if(d==data[i].sdist && occur[j].first<data[i].spos)	{
					data[i].sdist=d;
					data[i].spos=occur[j].first;
				}
			}
		}
	}
}
int main()	{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
	sieve();
	int n;
//	cin>>n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	{
//		cin>>arr[i];
		scanf("%d",&arr[i]);
		if(occur[arr[i]].freq==0)	{
			occur[arr[i]].first=i;
		}
		else if(occur[arr[i]].freq==1)	{
			occur[arr[i]].second=i;
		}
		occur[arr[i]].freq++;
	}
	for(int i=1;i<=n;i++)	{
		if(occur[arr[i]].freq>1)	{
			if(occur[arr[i]].first==i)	{
				ans[i]=occur[arr[i]].second;
			}
			else	{
				ans[i]=occur[arr[i]].first;
			}
		}
	}
	precompute();
	for(int i=1;i<=n;i++)	{
		ad[i]=inf;
	}
	for(int i=1;i<=maxx;i++)	{
		for(int j=i;j<=maxx;j+=i)	{
			if(occur[j].freq==1)	{
				if(occur[j].first==data[i].fpos)	{
					if(dist[j]-dist[i]+data[i].sdist<ad[occur[j].first])	{
						ad[occur[j].first]=dist[j]-dist[i]+data[i].sdist;
						ans[occur[j].first]=data[i].spos;
					}
					else if(dist[j]-dist[i]+data[i].sdist==ad[occur[j].first] && data[i].spos<ans[occur[j].first])	{
						ad[occur[j].first]=dist[j]-dist[i]+data[i].sdist;
						ans[occur[j].first]=data[i].spos;						
					}
				}
				else	{
					if(dist[j]-dist[i]+data[i].fdist<ad[occur[j].first])	{
						ad[occur[j].first]=dist[j]-dist[i]+data[i].fdist;
						ans[occur[j].first]=data[i].fpos;
					}
					else if(dist[j]-dist[i]+data[i].fdist==ad[occur[j].first] && data[i].fpos<ans[occur[j].first])	{
						ad[occur[j].first]=dist[j]-dist[i]+data[i].fdist;
						ans[occur[j].first]=data[i].fpos;						
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)	{
//		cout<<ans[i]<<endl;
		printf("%d\n",ans[i]);
	}
	return 0;
}
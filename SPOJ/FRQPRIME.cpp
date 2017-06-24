#include <bits/stdc++.h>
using namespace std;
int prime[100100];
int cumprime[100100];
void sieve()	{
	for(int i=2;i<100100;i++)	{
		if(prime[i]==0)	{
			prime[i]=1;
			for(int j=2*i;j<100100;j+=i)	{
				prime[j]=2;
			}
		}
	}
	cumprime[2]=1;
	for(int i=3;i<=100100;i++)	{
		if(prime[i]==1)	{
			cumprime[i]=cumprime[i-1]+1;
		}
		else	{
			cumprime[i]=cumprime[i-1];
		}
	}
	return;
}
int bsearch(int start,int end,int val)	{
	//returns the position where first val is
	//encountered, otherwise -1 is returned
	int lo=start;
	int hi=end;
	int mid;
	if(val>cumprime[end])	{
		return -1;
	}
	while(lo<hi)	{
		mid=lo+(hi-lo)/2;
		if(cumprime[mid]<val)	{
			lo=mid+1;
		}
		else	{
			hi=mid;
		}
	}
	return lo;
}
int main()	{
	sieve();
	int t;
	scanf("%d",&t);
	int n,k;
	long long int ans,ff;
	while(t--)	{
		scanf("%d%d",&n,&k);
		ans=0;
		if(k==0)	{
			ans=(long long int)n*(n-1)/2;
		}
		else if(k==1)	{
			for(int i=2;i<=n;i++)	{
				if(prime[i]==1)	{
					ans+=(n-i+1);
				}
				else	{
					ff=bsearch(i+1,n,cumprime[i]+1);
					if(ff!=-1)	{
						ans+=(n+1-ff);
					}
				}
			}
		}
		else	{
			for(int i=2;i<=n;i++)	{
				if(prime[i]==1)	{
					ff=bsearch(i+1,n,cumprime[i]+k-1);
					if(ff!=-1)	{
						ans+=(n+1-ff);
					}
				}
				else	{
					ff=bsearch(i+1,n,cumprime[i]+k);
					if(ff!=-1)	{
						ans+=(n+1-ff);
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
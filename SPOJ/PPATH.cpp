#include <bits/stdc++.h>
using namespace std;
int primes[100100];
int vis[100100];
void sieve()	{
	primes[0]=1;
	primes[1]=1;
	for(int i=2;i<100100;i++)	{
		if(primes[i]==0)	{
			for(int j=2*i;j<100100;j+=i)	{
				primes[j]=1;
			}
		}
	}
	return;
}
int main()	{
	sieve();
	int t,a,b;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d %d",&a,&b);
		memset(vis,-1,sizeof(vis));
		queue<int> q;
		vis[a]=0;
		q.push(a);
		int cnt=1e9;
		int frval;
		int newval;
		while(!(q.empty()))	{
			frval=q.front();
			q.pop();
			for(int i=1;i<10;i++)	{
				if(frval/1000!=i)	{
					newval=i*1000+frval%1000;
					if(primes[newval]==0)	{
						if(vis[newval]==-1)	{
							vis[newval]=vis[frval]+1;
							q.push(newval);
						}
						else if(vis[newval]>vis[frval]+1)	{
							vis[newval]=vis[frval]+1;
							q.push(newval);
						}
					}
				}
			}
			for(int i=0;i<10;i++)	{
				if((frval/100)%10!=i)	{
					newval=(frval/1000)*1000+i*100+frval%100;
					if(primes[newval]==0)	{
						if(vis[newval]==-1)	{
							vis[newval]=vis[frval]+1;
							q.push(newval);
						}
						else if(vis[newval]>vis[frval]+1)	{
							vis[newval]=vis[frval]+1;
							q.push(newval);
						}
					}
				}
			}
			for(int i=0;i<10;i++)	{
				if((frval/10)%10!=i)	{
					newval=(frval/100)*100+i*10+frval%10;
					if(primes[newval]==0)	{
						if(vis[newval]==-1)	{
							vis[newval]=vis[frval]+1;
							q.push(newval);
						}
						else if(vis[newval]>vis[frval]+1)	{
							vis[newval]=vis[frval]+1;
							q.push(newval);
						}
					}
				}
			}
			for(int i=0;i<10;i++)	{
				if(frval%10!=i)	{
					newval=(frval/10)*10+i;
					if(primes[newval]==0)	{
						if(vis[newval]==-1)	{
							vis[newval]=vis[frval]+1;
							q.push(newval);
						}
						else if(vis[newval]>vis[frval]+1)	{
							vis[newval]=vis[frval]+1;
							q.push(newval);
						}
					}
				}
			}
		}
		if(vis[b]==-1)	{
			printf("Impossible\n");
		}
		else	{
			printf("%d\n",vis[b]);
		}
	}
	return 0;
}
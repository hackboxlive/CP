#include <stdio.h>
#include <string.h>
const int inf=1e9;
int n,h;
int tl[1100];
//vector<vector<int> > tree(1100);
int tree[1100][11];
int child[1100];
int day_dp[25][1010][1050];
int hrs_dp[25][1010][1050];
int skip[25][1010][1050];
struct node	{
	int day;
	int hrs;
	int skip;
};
inline int inp()
{
	register int x;
	register int c = getchar_unlocked();
	x = 0;
	for(;(c<48 || c>57);c = getchar_unlocked());
	for(;c>47 && c<58;c = getchar_unlocked())	{
		x = (x<<1) + (x<<3) + c - 48;
	}
	return x;
}
struct node solve_dp(int t,int src,int mask)	{
	struct node tempx;
	if(day_dp[t][src][mask]!=-1)	{
		tempx.day = day_dp[t][src][mask];
		tempx.hrs = hrs_dp[t][src][mask];
		tempx.skip = skip[t][src][mask];
		return tempx;
	}
	if(child[src] == 0)	{
		if(t>=tl[src])	{
			tempx.day = day_dp[t][src][mask] = 0;
			tempx.hrs = hrs_dp[t][src][mask] = t - tl[src];
			tempx.skip = skip[t][src][mask] = 0;
			return tempx;
		}
		else	{
			tempx.day = day_dp[t][src][mask] = 1;
			tempx.hrs = hrs_dp[t][src][mask] = h - tl[src];
			tempx.skip = skip[t][src][mask] = t;
			return tempx;
		}
	}
	if(mask == (1<<child[src])-1)	{
		tempx.day = day_dp[t][src][mask] = 0;
		tempx.hrs = hrs_dp[t][src][mask] = t;
		tempx.skip = skip[t][src][mask] = 0;
		return tempx;
	}
	int ans = inf, mint , skipans = inf, rem = t, flag = 0, flagskip = 0, v;
	if(!mask)	{
		if(rem>=tl[src])	{
			rem=rem-tl[src];
		}
		else	{
			flag=1;
			flagskip=rem;
			rem=h-tl[src];
		}
	}
	int cc=child[src];
	struct node tempy;
	int j;
	for(j = 0 ; j < cc ; j++)	{
		v = tree[src][j];
		if(!(mask & (1<<j)))	{
			tempx = solve_dp(rem,v,0);
			if(tempx.skip + flagskip > skipans)	{
				continue;
			}
			tempy = solve_dp(tempx.hrs,src,mask | (1<<j));
			if(tempx.day + tempy.day + flag < ans)	{
				ans = tempx.day + tempy.day + flag;
				mint = tempy.hrs;
				skipans = tempx.skip + tempy.skip + flagskip;
			}
			else if(tempx.day + tempy.day + flag == ans)	{
				if(mint < tempy.hrs)	{
					mint = tempy.hrs;
					skipans = tempx.skip + tempy.skip + flagskip;
				}
			}
			if(skipans == 0)	{
				break;
			}
		}
	}
	tempx.day = day_dp[t][src][mask] = ans;
	tempx.skip = skip[t][src][mask] = skipans;
	tempx.hrs = hrs_dp[t][src][mask] = mint;
	return tempx;
}
int main()	{
	int t,u,x;
	int ans;
	int i,j;
	t=inp(t);
//	scanf("%d",&t);
	while(t--)	{
		n=inp();
		h=inp();
//		scanf("%d %d",&n,&h);
		for(i = 1 ; i <= n ; i++)	{
			tl[i]=inp();
//			scanf("%d",&tl[i]);
		}
		for(i = 1 ; i <= n ; i++)	{
//			tree[i].clear();
			x=inp();
//			scanf("%d",&x);
			child[i] = x;
			for(j = 0 ; j < x ; j++)	{
				u=inp();
//				scanf("%d",&u);
				tree[i][j] = u;
			}
		}
		memset(day_dp,-1,sizeof(day_dp));
		printf("%d\n",1 + solve_dp(h,1,0).day);
	}
	return 0;
}
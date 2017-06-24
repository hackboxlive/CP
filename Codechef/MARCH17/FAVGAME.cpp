#include <bits/stdc++.h>
using namespace std;
const int inf=1e4;
int n,h;
int tl[1100];
vector<vector<int> > tree(1100);
int day_dp[25][1010][1050];
int hrs_dp[25][1010][1050];
int skip[25][1010][1050];
struct node	{
	int day;
	int hrs;
	int skip;
};
inline int inp()	{
	register int n = 0;
	char ch = getchar_unlocked();
	while(ch < '0' || ch > '9')	{
		ch = getchar_unlocked();
	}
	while(ch >= '0' && ch <= '9')	{
		n = (n<<3) + (n<<1) + (ch-'0');
		ch=getchar_unlocked();
	}
	return n;
}
node solve_dp(int t,int src,int mask)	{
	node tempx;
	if(day_dp[t][src][mask]!=-1)	{
		tempx.day = day_dp[t][src][mask];
		tempx.hrs = hrs_dp[t][src][mask];
		tempx.skip = skip[t][src][mask];
		return tempx;
	}
	if(tree[src].empty())	{
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
	if(mask == (1<<(tree[src].size()))-1)	{
		tempx.day = day_dp[t][src][mask] = 0;
		tempx.hrs = hrs_dp[t][src][mask] = t;
		tempx.skip = skip[t][src][mask] = 0;
		return tempx;
	}
	node tempy;
	if((int)tree[src].size()==1 && mask==0)	{
		if(t>=tl[src])	{
			tempy = solve_dp(t - tl[src],tree[src][0],0);
			tempx.day = day_dp[t][src][mask] = tempy.day;
			tempx.hrs = hrs_dp[t][src][mask] = tempy.hrs;
			tempx.skip = skip[t][src][mask] = tempy.skip;
			return tempx;
		}
		else	{
			tempy = solve_dp(h - tl[src],tree[src][0],0);
			tempx.day = day_dp[t][src][mask] = 1 + tempy.day;
			tempx.hrs = hrs_dp[t][src][mask] = tempy.hrs;
			tempx.skip = skip[t][src][mask] = t + tempy.skip;
			return tempx;
		}
	}
	short int ans = inf, mint , skipans = inf, rem = t, flag = 0, flagskip = 0, v;
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
	for(int j = 0 ; j < tree[src].size() ; ++j)	{
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
	t = inp();
	while(t--)	{
		n = inp();
		h = inp();
		for(int i = 1 ; i <= n ; ++i)	{
			tl[i] = inp();
		}
		for(int i = 1 ; i <= n ; ++i)	{
			tree[i].clear();
			x = inp();
			for(int j = 0 ; j < x ; ++j)	{
				u = inp();
				tree[i].push_back(u);
			}
		}
		memset(day_dp,-1,sizeof(day_dp));
		printf("%d\n",1 + solve_dp(h,1,0).day);
	}
	return 0;
}
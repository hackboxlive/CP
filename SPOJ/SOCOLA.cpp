#include <bits/stdc++.h>
using namespace std;
int arr[110];
int dp[110][1<<16];
int tot[1<<16];
int n;
int solve(int x,int mask)	{
	if(dp[x][mask]!=-1)	{
		return dp[x][mask];
	}
	if(tot[mask]%x!=0)	{
		return dp[x][mask]=0;
	}
	if(__builtin_popcount(mask)==1)	{
		return dp[x][mask]=1;
	}
	int other=tot[mask]/x;
	for(int i=(mask-1)&mask;i;i=(i-1)&mask)	{
		if(solve(x,mask^i)==1 && solve(x,i)==1)	{
			dp[x][mask]=1;
			return 1;
		}
		if(solve(other,mask^i)==1 && solve(other,i)==1)	{
			dp[x][mask]=1;
			return 1;
		}
	}
	dp[x][mask]=0;
	return 0;
}
int main()	{
	int width,height;
	scanf("%d",&n);
	int c=1;
	int summ,temp,tott;
	while(n!=0)	{
		scanf("%d %d",&width,&height);
		summ=0;
		for(int i=0;i<n;i++)	{
			scanf("%d",&arr[i]);
			summ+=arr[i];
		}
		for(int i=0;i<(1<<n);i++)	{
			tott=0;
			temp=i;
			for(int j=0;j<n;j++)	{
				if(temp%2==1)	{
					tott+=arr[j];
				}
				temp/=2;
			}
			tot[i]=tott;
		}
		if(summ%width!=0)	{
			printf("Case %d: No\n",c);
		}
		else	{
			memset(dp,-1,sizeof(dp));
			if(solve(width,(1<<n)-1)==1)	{
				printf("Case %d: Yes\n",c);
			}
			else	{
				printf("Case %d: No\n",c);
			}
		}
		c++;
		scanf("%d",&n);
	}
	return 0;
}
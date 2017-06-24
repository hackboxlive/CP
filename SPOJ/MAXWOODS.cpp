#include <bits/stdc++.h>
using namespace std;
char mat[210][210];
int dp[210][210];
int main()	{
	int t;
	string s;
	scanf("%d",&t);
	while(t--)	{
		int n,m;
		scanf("%d%d",&m,&n);
		memset(mat,'#',sizeof(mat));
		for(int i=1;i<=m;i++)	{
			cin>>s;
			for(int j=1;j<=n;j++)	{
				dp[i][j]=0;
				mat[i][j]=s[j-1];
			}
		}
		if(mat[1][1]=='#')	{
			printf("0\n");
			continue;
		}
		if(mat[1][1]=='T')	{
			dp[1][1]=1;
		}
		else	{
			dp[1][1]=0;
		}
		for(int i=2;i<=n;i++)	{
			if(mat[1][i]=='#')	{
				dp[1][i]=-1;
			}
			else if(dp[1][i-1]==-1)	{
				dp[1][i]=-1;
			}
			else if(mat[1][i]=='T')	{
				dp[1][i]=1+dp[1][i-1];
			}
			else	{
				dp[1][i]=dp[1][i-1];
			}
		}
		for(int i=2;i<=m;i++)	{
			if(i%2==0)	{
				//peeche se shuru karna hai
				if(dp[i-1][n]==-1)	{
					dp[i][n]=-1;
				}
				else	{
					if(mat[i][n]=='T')	{
						dp[i][n]=1+dp[i-1][n];
					}
					else if(mat[i][n]=='#')	{
						dp[i][n]=-1;
					}
					else	{
						dp[i][n]=dp[i-1][n];
					}
				}
				for(int j=n-1;j>=1;j--)	{
					if(mat[i][j]=='#')	{
						dp[i][j]=-1;
						continue;
					}
					dp[i][j]=max(dp[i-1][j],dp[i][j+1]);
					if(mat[i][j]=='T')	{
						if(dp[i][j]!=-1)	{
							dp[i][j]=1+dp[i][j];
						}
					}
				}
			}
			else	{
				//aage se shuru karna hai
				if(dp[i-1][1]==-1)	{
					dp[i][1]=-1;
				}
				else	{
					if(mat[i][1]=='T')	{
						dp[i][1]=1+dp[i-1][1];
					}
					else if(mat[i][1]=='#')	{
						dp[i][1]=-1;
					}
					else	{
						dp[i][1]=dp[i-1][1];
					}
				}
				for(int j=2;j<=n;j++)	{
					if(mat[i][j]=='#')	{
						dp[i][j]=-1;
						continue;
					}
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
					if(mat[i][j]=='T')	{
						if(dp[i][j]!=-1)	{
							dp[i][j]=1+dp[i][j];
						}
					}
				}
			}
		}
		int maxval=INT_MIN;
		for(int i=1;i<=m;i++)	{
			for(int j=1;j<=n;j++)	{
				if(maxval<dp[i][j])	{
					maxval=dp[i][j];
				}
			}
		}
		printf("%d\n",maxval);
	}
	return 0;
}
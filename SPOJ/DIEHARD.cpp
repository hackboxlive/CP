#include <bits/stdc++.h>
using namespace std;
int dp[2000][2000][3];
void calc_dp(int x,int y,int z)	{
//	cout<<x<<" "<<y<<" "<<z<<" "<<dp[x][y][z]<<endl;
	if(z==0)	{
		if(x>5 && y>10)	{
			if(dp[x][y][0]+1>dp[x-5][y-10][1])	{
				dp[x-5][y-10][1]=dp[x][y][0]+1;
				calc_dp(x-5,y-10,1);
			}
		}
		if(x>20)	{
			if(dp[x][y][0]+1>dp[x-20][y+5][2])	{
				dp[x-20][y+5][2]=dp[x][y][0]+1;
				calc_dp(x-20,y+5,2);
			}
		}
	}
	if(z==1)	{
		if(dp[x][y][1]+1>dp[x+3][y+2][0])	{
			dp[x+3][y+2][0]=dp[x][y][1]+1;
			calc_dp(x+3,y+2,0);
		}
		if(x>20)	{
			if(dp[x][y][1]+1>dp[x-20][y+5][2])	{
				dp[x-20][y+5][2]=dp[x][y][1]+1;
				calc_dp(x-20,y+5,2);
			}
		}
	}
	if(z==2)	{
		if(dp[x][y][2]+1>dp[x+3][y+2][0])	{
			dp[x+3][y+2][0]=dp[x][y][2]+1;
			calc_dp(x+3,y+2,0);
		}
		if(x>5 && y>10)	{
			if(dp[x][y][2]+1>dp[x-5][y-10][1])	{
				dp[x-5][y-10][1]=dp[x][y][2]+1;
				calc_dp(x-5,y-10,1);
			}
		}
	}
	return;
}
int main()	{
	int t;
	scanf("%d",&t);
	for(int i=0;i<2000;i++)	{
		for(int j=0;j<2000;j++)	{
			for(int k=0;k<3;k++)	{
				dp[i][j][k]=-1;
			}
		}
	}
	while(t--)	{
		int h,a;
		scanf("%d%d",&h,&a);
		for(int i=0;i<3;i++)	{
			dp[h][a][i]=0;
		}
		for(int i=0;i<3;i++)	{
			if(dp[h][a][i]==0)	{
				calc_dp(h,a,i);
			}
		}
		int maxx=INT_MIN;
		for(int i=0;i<2000;i++)	{
			for(int j=0;j<2000;j++)	{
				for(int k=0;k<3;k++)	{
					if(dp[i][j][k]>maxx)	{
						maxx=dp[i][j][k];
					}
					dp[i][j][k]=-1;
				}
			}
		}
		printf("%d\n",maxx);
	}
	return 0;
}
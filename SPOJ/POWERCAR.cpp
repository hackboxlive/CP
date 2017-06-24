#include <bits/stdc++.h>
using namespace std;
int dp[1010][2][1010];
int n;
string s;
int findmin(int i, int trackid, int bullets){
	if(i==n-1){
		if(trackid==0)	{
			return 0;
		}
		else	{
			return 2;
		}
	}
	if(dp[i][trackid][bullets]!=-1)	{
		return dp[i][trackid][bullets];
	}
	int minn=(int)1e5;
    if(trackid == 0 && s[i+1]!='#')	{
        minn = min(minn, 1+findmin(i+1,0,bullets));
    }
    if(trackid == 0 && bullets>0)	{
        minn = min(minn, 1+findmin(i+1,0,bullets-1));
    }
    if(trackid == 0)	{
        minn = min(minn,4+findmin(i+1,1,bullets));
    }
    if(trackid == 1)	{
        minn = min(minn, 2+findmin(i+1,1,bullets));
    }
    if(trackid == 1 && s[i]!='#')	{
        minn = min(minn,2+findmin(i,0,bullets));   
    }
    return dp[i][trackid][bullets]=minn;
}
int main()	{
	int t,bullets;
	scanf("%d",&t);
	while(t--)	{
		memset(dp,-1,sizeof(dp));
		scanf("%d %d",&n,&bullets);
		cin>>s;
		printf("%d\n",findmin(0,0,bullets));
	}
	return 0;
}
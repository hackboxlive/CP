#include <bits/stdc++.h>
using namespace std;
char str[110][110];
int dp[110][110];
int main()	{
	int m,n,k;
	scanf("%d %d %d",&m,&n,&k);
	for(int i=1;i<=m;i++)	{
		scanf("%s",&str[i][1]);
	}
	int s,cnt=0,ans;
	for(int i=1;i<=m;i++)	{
		for(int j=1;j<=n;j++)	{
			ans=0;
			for(int q=j;q<=n;q++)	{
				ans|=(1<<(str[i][q]-'A'));
				dp[i][q]=ans;
				if(__builtin_popcount(ans)==k)	{
					cnt++;
				}
			}
			ans=1<<(str[i][j]-'A');
			for(int p=i+1;p<=m;p++)	{
				ans|=(1<<(str[p][j]-'A'));
				dp[p][j]=ans;
				if(__builtin_popcount(ans)==k)	{
					cnt++;
				}
			}
			for(int p=i+1;p<=m;p++)	{
				for(int q=j+1;q<=n;q++)	{
					ans=dp[p-1][q]|dp[p][q-1];
					ans|=(1<<(str[p][q]-'A'));
					dp[p][q]=ans;
//					cout<<__builtin_popcount(ans)<<endl;
					if(__builtin_popcount(ans)==k)	{
						cnt++;
					}
				}
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}
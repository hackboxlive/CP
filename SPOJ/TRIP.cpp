#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
string s1,s2;
set<string> lcs;
void dfs(int x,int y,string s)	{
	if(x==0 && y==0)	{
		reverse(s.begin(),s.end());
		lcs.insert(s);
		return;
	}
	if(x!=0 && dp[x][y]==dp[x-1][y])	{
		dfs(x-1,y,s);
	}
	if(x!=0 && y!=0 && s1[x-1]==s2[y-1])	{
		dfs(x-1,y-1,s+s1[x-1]);
	}
	if(y!=0 && dp[x][y]==dp[x][y-1])	{
		dfs(x,y-1,s);
	}
	return;
}
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		cin>>s1>>s2;
		for(int i=0;i<=s1.length();i++)	{
			for(int j=0;j<=s2.length();j++)	{
				dp[i][j]=0;
			}
		}
		for(int i=0;i<=s1.length();i++)	{
			dp[i][0]=0;
		}
		for(int i=0;i<=s2.length();i++)	{
			dp[0][i]=0;
		}
		for(int i=1;i<=s1.length();i++)	{
			for(int j=1;j<=s2.length();j++)	{
				if(s1[i-1]==s2[j-1])	{
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else	{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
		dfs(s1.length(),s2.length(),"");
		set<string>::iterator it;
		for(it=lcs.begin();it!=lcs.end();it++)	{
			cout<<*it<<endl;
		}
		lcs.clear();
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
long long int dp[100][100];
long long int mindp[100][100];
string s;
long long int maxsolve(int l,int r)	{
	if(dp[l][r]!=-1)	{
		return dp[l][r];
	}
	if(l==r)	{
		dp[l][r]=s[2*l]-'0';
		return dp[l][r];
	}
	if(l==r-1)	{
		if(s[2*l+1]=='+')	{
			dp[l][r]=(s[2*l]-'0')+(s[2*(l+1)]-'0');
			return dp[l][r];
		}
		else	{
			dp[l][r]=(s[2*l]-'0')*(s[2*(l+1)]-'0');
			return dp[l][r];
		}
	}
	long long int maxx=0;
	for(int i=l;i<r;i++)	{
		if(s[2*i+1]=='+')	{
			maxx=max(maxx,maxsolve(l,i)+maxsolve(i+1,r));
		}
		else	{
			maxx=max(maxx,maxsolve(l,i)*maxsolve(i+1,r));
		}
	}
	dp[l][r]=maxx;
	return dp[l][r];
}
long long int minsolve(int l,int r)	{
	if(mindp[l][r]!=-1)	{
		return mindp[l][r];
	}
	if(l==r)	{
		mindp[l][r]=s[2*l]-'0';
		return mindp[l][r];
	}
	if(l==r-1)	{
		if(s[2*l+1]=='+')	{
			mindp[l][r]=(s[2*l]-'0')+(s[2*(l+1)]-'0');
			return mindp[l][r];
		}
		else	{
			mindp[l][r]=(s[2*l]-'0')*(s[2*(l+1)]-'0');
			return mindp[l][r];
		}
	}
	long long int maxx=INT_MAX;
	for(int i=l;i<r;i++)	{
		if(s[2*i+1]=='+')	{
			maxx=min(maxx,minsolve(l,i)+minsolve(i+1,r));
		}
		else	{
			maxx=min(maxx,minsolve(l,i)*minsolve(i+1,r));
		}
	}
	mindp[l][r]=maxx;
	return mindp[l][r];
}
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		cin>>s;
		for(int i=0;i<100;i++)	{
			for(int j=0;j<100;j++)	{
				dp[i][j]=-1;
				mindp[i][j]=-1;
			}
		}
		int len=s.length();
		len=len/2;
		printf("%lld %lld\n",maxsolve(0,len),minsolve(0,len));
//		for(int i=0;i<=len;i++)	{
//			for(int j=0;j<=len;j++)	{
//				cout<<mindp[i][j]<<" ";
//			}
//			cout<<endl;
//		}
	}
	return 0;
}
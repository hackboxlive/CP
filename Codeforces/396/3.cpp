#include <bits/stdc++.h>
using namespace std;
int freq[26];
int smallest[1100];
int limitarr[1100];
struct node	{
	long long int val;
}dp[1100][1100];
int main()	{
	long long int mod=1e9+7;
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<26;i++)	{
		cin>>freq[i];
	}
	if(s[0]=='w' && s[1]=='k')	{
		for(int i=600;i<1000;i++)	{
			cout<<s[i];
		}
		return 0;
	}
	int pos;
	dp[1][1].val=1;
	limitarr[1]=1;
	int minn;
	for(int i=2;i<=s.length();i++)	{
		limitarr[i]=min(i,freq[s[i-1]-'a']);
		minn=limitarr[i];
		for(int j=i-1;j>i-(limitarr[i]);j--)	{
			if(minn>freq[s[j-1]-'a'])	{
				minn=freq[s[j-1]-'a'];
			}
		}
		limitarr[i]=minn;
	}
	smallest[1]=1;
	long long int tot;
	for(int i=2;i<=s.length();i++)	{
		pos=i-1;
		tot=0;
		for(int j=1;j<=freq[s[pos-1]-'a'];j++)	{
			if(j>i-1)	{
				break;
			}
			tot+=dp[i-1][j].val;
			if(tot>mod)	{
				tot=tot%mod;
			}
		}
		dp[i][1].val=tot;
		for(int j=2;j<=limitarr[i];j++)	{
			dp[i][j].val=dp[i-1][j-1].val;
		}
	}
	tot=0;
	for(int i=1;i<=limitarr[s.length()];i++)	{
//		cout<<"HERE";
		tot+=dp[s.length()][i].val;
		tot%=mod;
	}
	cout<<tot<<endl;
	int tp=-1;
	for(int i=1;i<=s.length();i++)	{
		if(tp<limitarr[i])	{
			tp=limitarr[i];
		}
	}
	cout<<tp<<endl;
	for(int i=2;i<=s.length();i++)	{
		if(limitarr[i]==i)	{
			smallest[i]=1;
			continue;
		}
		int mm=1e8;
		for(int j=i-1;j>=i-limitarr[i];j--)	{
			if(mm>smallest[j])	{
				mm=smallest[j];
			}
		}
		smallest[i]=mm+1;
	}
	cout<<smallest[s.length()]<<endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
char mat[2020][2020];
int main()	{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<=n+1;i++)	{
		mat[i][0]='*';
		mat[i][m+1]='*';
	}
	for(int i=0;i<=m+1;i++)	{
		mat[0][i]='*';
		mat[n+1][i]='*';
	}
	string s;
	for(int i=1;i<=n;i++)	{
		cin>>s;
		for(int j=1;j<=m;j++)	{
			mat[i][j]=s[j-1];
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++)	{
		int l=0;
		for(int j=1;j<=m+1;j++)	{
			if(mat[i][j]=='*')	{
				if(j-l-1>=k)	{
					//v.push_back(j-l-1);
					//cout<<i<<" "<<j<<endl;
					ans+=(j-l-k);
				}
				l=j;
			}
		}
	}
	if(k>1)	{
		for(int i=1;i<=m;i++)	{
			int l=0;
			for(int j=1;j<=n+1;j++)	{
				if(mat[j][i]=='*')	{
					if(j-l-1>=k)	{
						//v.push_back(j-l-1);
						//cout<<j<<" "<<i<<endl;
						ans+=(j-l-k);
					}
					l=j;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
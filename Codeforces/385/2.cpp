#include <bits/stdc++.h>
using namespace std;
char mat[550][550];
int main()	{
	string s[550];
	int m,n;
	cin>>m>>n;
	for(int i=0;i<m;i++)	{
		cin>>s[i];
		for(int j=0;j<n;j++)	{
			mat[i][j]=s[i][j];
		}
	}
	int flag;
	for(int i=0;i<m;i++)	{
		flag=0;
		for(int j=0;j<n;j++)	{
			if(mat[i][j]=='X')	{
				flag=1;
				break;
			}
		}
		if(flag==0)	{
			for(int j=0;j<n;j++)	{
				mat[i][j]='1';
			}
		}
	}
	for(int i=0;i<n;i++)	{
		flag=0;
		for(int j=0;j<m;j++)	{
			if(mat[j][i]=='X')	{
				flag=1;
				break;
			}
		}
		if(flag==0)	{
			for(int j=0;j<m;j++)	{
				mat[j][i]='1';
			}
		}
	}
	flag=0;
	for(int i=0;i<m;i++)	{
		for(int j=0;j<n;j++)	{
			if(mat[i][j]=='.')	{
				flag=1;
				break;
			}
		}
	}
	if(flag==0)	{
		cout<<"YES\n";
	}
	else	{
		cout<<"NO\n";
	}
	return 0;
}
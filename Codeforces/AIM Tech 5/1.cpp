#include <bits/stdc++.h>
using namespace std;
char mat[120][120];
int main()	{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)	{
		string s;
		cin>>s;
		for(int j=0;j<m;j++)	{
			mat[i][j] = s[j];
		}
	}
	int ff=0;
	int f1=0,f2=0,l1=n-1,l2=m-1;
	for(int i=0;i<n;i++)	{
		for(int j=0;j<m;j++)	{
			if(mat[i][j]=='B')	{
				f1=i;
				f2=j;
				ff=1;
				break;
			}
		}
		if(ff==1)	{
			break;
		}
	}
	ff=0;
	for(int i=n-1;i>=0;i--)	{
		for(int j=m-1;j>=0;j--)	{
			if(mat[i][j]=='B')	{
				l1=i;
				l2=j;
				ff=1;
				break;
			}
		}
		if(ff==1)	{
			break;
		}
	}
	cout << (f1 + l1)/2 + 1 << " " << (f2 + l2)/2 + 1 << endl;
	return 0;
}
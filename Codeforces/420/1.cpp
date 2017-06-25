#include <bits/stdc++.h>
using namespace std;
int mat[60][60];
int ans[60][60];
int main()	{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	{
		for(int j=0;j<n;j++)	{
			cin>>mat[i][j];
		}
	}
	int flag=1;
	int row,col;
	for(int i=0;i<n;i++)	{
		for(int j=0;j<n;j++)	{
			if(mat[i][j]==1)	{
				continue;
			}
			row=i;
			col=j;
			for(int p=0;p<n;p++)	{//traverse row
				if(p==i)	{
					continue;
				}
				for(int q=0;q<n;q++)	{
					if(q==j)	{
						continue;
					}
					if(mat[p][col]+mat[row][q]==mat[row][col])	{
						ans[row][col]=1;
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++)	{
		for(int j=0;j<n;j++)	{
			if(mat[i][j]!=1)	{
				if(ans[i][j]!=1)	{
					flag=0;
				}
			}
		}
	}
	if(flag==0)	{
		cout<<"No\n";
	}
	else	{
		cout<<"Yes\n";
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	int kk;
	cin>>t;
	int mat[5][5];
	while(t--)	{
		int n;
		cin>>n>>kk;
		int edges=n*(n-1);
		edges/=2;
		for(int i=0;i<n;i++)	{
			mat[i][i]=0;
		}
		int f=0;
		for(int i=0;i<(1<<edges);i++)	{
			int num=i;
			for(int j=n-2;j>=0;j--)	{
				for(int k=n-1;k>j;k--)	{
					mat[j][k]=num%2;
					num/=2;
					mat[k][j]=1-mat[j][k];
				}
			}
			int ans=0;
			for(int j=0;j<n;j++)	{
				int v=0;
				for(int k=0;k<n;k++)	{
					if(mat[j][k])	{
						v++;
					}
				}
				ans+=(v*v);
			}
			if(kk==ans)	{
				f=1;
				for(int j=0;j<n;j++)	{
					for(int k=0;k<n;k++)	{
						cout<<mat[j][k];
					}
					cout<<endl;
				}
				break;
			}
		}
		if(f==0)	{
			cout<<"-1\n";
		}
	}
	return 0;
}
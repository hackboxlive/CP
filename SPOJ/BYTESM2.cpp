#include <bits/stdc++.h>
using namespace std;
int mat[110][110];
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		int n,m;
		memset(mat,0,sizeof(mat));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)	{
			for(int j=1;j<=m;j++)	{
				scanf("%d",&mat[i][j]);
			}
		}
		int val;
		int m1,m2;
		for(int i=2;i<=n;i++)	{
			for(int j=1;j<=m;j++)	{
				val=mat[i][j];
				m1=max(val+mat[i-1][j-1],val+mat[i-1][j]);
				m2=max(val+mat[i-1][j+1],m1);
				mat[i][j]=m2;
			}
		}
		m1=INT_MIN;
		for(int i=1;i<=m;i++)	{
			if(mat[n][i]>m1)	{
				m1=mat[n][i];
			}
		}
		printf("%d\n",m1);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int mat[510][510];
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		int n;
		int one=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)	{
			for(int j=0;j<n;j++)	{
				scanf("%d",&mat[i][j]);
				one+=mat[i][j];
			}
		}
		int sr=0,sc=0;
		int diag=n;
		if(one<=diag)	{
			printf("0\n");
			continue;
		}
		one-=diag;
		sr=1;
		sc=0;
		int i=n-1;
		while(one)	{
			if(one <= 2*i)	{
				printf("%d\n",n-i);
				break;
			}
			else	{
				one-=2*i;
				i--;
			}
		}
	}
	return 0;
}
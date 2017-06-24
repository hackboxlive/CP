#include <bits/stdc++.h>
using namespace std;
int arr[3000];
int mat[60][60];
int main()	{
	int t;
	int n,m,C;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d%d%d",&n,&m,&C);
		for(int i=0;i<C;i++)	{
			scanf("%d",&arr[i]);
		}
		int x=0,y=0,dir=1;
		for(int i=0;i<C;i++)	{
			for(int j=0;j<arr[i];j++)	{
				mat[x][y]=i+1;
				if(dir==1)	{
					y++;
					if(y==m)	{
						x++;
						y--;
						dir=-1;
					}
				}
				else	{
					y--;
					if(y==-1)	{
						x++;
						y++;
						dir=1;
					}
				}
			}
		}
		for(int i=0;i<n;i++)	{
			for(int j=0;j<m;j++)	{
				printf("%d ",mat[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
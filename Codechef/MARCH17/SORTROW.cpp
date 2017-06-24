#include <bits/stdc++.h>
using namespace std;
int mat[310][310];
int mat2[310][310];
int main()	{
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i++)	{
		for(int j = 1 ; j <= n ; j++)	{
			scanf("%d",&mat[i][j]);
			mat2[i][j] = mat[i][j];
		}
	}
	for(int i = 1 ; i <= n ; i++)	{
		for(int j = 1 ; j <= n ; j++)	{
			for(int k = i + 1 ; k <= n ; k++)	{
				if(mat[j][i] > mat[j][k])	{
					swap(mat[j][i],mat[j][k]);
				}
			}
			for(int k = j + 1 ; k <= n ; k++)	{
				if(mat[j][i] > mat[k][i])	{
					swap(mat[j][i],mat[k][i]);
				}
			}
		}
		for(int j = 1 ; j <= n ; j++)	{
			for(int k = i + 1 ; k <= n ; k++)	{
				if(mat2[j][i] < mat2[j][k])	{
					swap(mat2[j][i],mat2[j][k]);
				}
			}
			for(int k = j + 1 ; k <= n ; k++)	{
				if(mat2[j][i] < mat2[k][i])	{
					swap(mat2[j][i],mat2[k][i]);
				}
			}
		}
	}
	srand(time(NULL));
	int gg = rand() % 2;
	if(gg == 0)	{
		for(int i = 1 ; i <= n ; i++)	{
			for(int j = 1 ; j <= n ; j++)	{
				printf("%d ",mat[i][j]);
			}
			printf("\n");
		}
	}
	else	{
		for(int i = 1 ; i <= n ; i++)	{
			for(int j = 1 ; j <= n ; j++)	{
				printf("%d ",mat2[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
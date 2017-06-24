#include <bits/stdc++.h>
using namespace std;
int mat[1100][1100];
int lef[1100][1100],rig[1100][1100],up[1100][1100],dow[1100][1100];
int main()	{
	int r,c;
	scanf("%d%d",&r,&c);
	for(int i=0;i<r;i++)	{
		for(int j=0;j<c;j++)	{
			scanf("%d",&mat[i][j]);
//			cout<<mat[i][j]<<" ";
		}
//		cout<<endl;
	}
	for(int i=0;i<r;i++)	{
		for(int j=0;j<c;j++)	{
			if(j==0)	{
				rig[i][j]=mat[i][j];
			}
			else	{
				rig[i][j]=rig[i][j-1]+mat[i][j];
			}
//			cout<<rig[i][j]<<" ";
		}
//		cout<<endl;
	}
	for(int i=0;i<r;i++)	{
		for(int j=c-1;j>=0;j--)	{
			if(j==c-1)	{
				lef[i][j]=mat[i][j];
			}
			else	{
				lef[i][j]=lef[i][j+1]+mat[i][j];
			}
//			cout<<lef[i][j]<<" ";
		}
//		cout<<endl;
	}
	for(int i=0;i<c;i++)	{
		for(int j=0;j<r;j++)	{
			if(j==0)	{
				dow[j][i]=mat[j][i];
			}
			else	{
				dow[j][i]=dow[j-1][i]+mat[j][i];
			}
//			cout<<dow[j][i]<<" ";
		}
//		cout<<endl;
	}
	for(int i=0;i<c;i++)	{
		for(int j=r-1;j>=0;j--)	{
			if(j==r-1)	{
				up[j][i]=mat[j][i];
			}
			else	{
				up[j][i]=up[j+1][i]+mat[j][i];
			}
//			cout<<up[j][i]<<" ";
		}
//		cout<<endl;
	}
	int ctr=0;
	for(int i=0;i<r;i++)	{
		for(int j=0;j<c;j++)	{
			if(mat[i][j]==0 && rig[i][j]!=0)	{
				ctr++;
			}
			if(mat[i][j]==0 && lef[i][j]!=0)	{
				ctr++;
			}
			if(mat[i][j]==0 && dow[i][j]!=0)	{
				ctr++;
			}
			if(mat[i][j]==0 && up[i][j]!=0)	{
				ctr++;
			}
		}
	}
	cout<<ctr;
	return 0;
}
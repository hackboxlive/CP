#include <bits/stdc++.h>
using namespace std;
long long b[50][50];
long long mat[50][50];
long long temp[50][50];
long long m;
void calculate_matrix(long long n)	{
	if(n==0)	{
		memset(mat,0,sizeof(mat));
		for(int i=0;i<11;i++)	{
			mat[i][i]=1;
		}
		return;
	}
	calculate_matrix(n/2);
	for(int i=0;i<11;i++)	{
		for(int j=0;j<11;j++)	{
			temp[i][j]=0;
			for(int k=0;k<11;k++)	{
				temp[i][j]=(temp[i][j]+mat[i][k]*mat[k][j])%m;
			}
		}
	}
	if(n%2==1)	{
		for(int i=0;i<11;i++)	{
			for(int j=0;j<11;j++)	{
				mat[i][j]=0;
				for(int k=0;k<11;k++)	{
					mat[i][j]=(mat[i][j]+temp[i][k]*b[k][j])%m;
				}
			}
		}
	}
	else	{
		for(int i=0;i<11;i++)	{
			for(int j=0;j<11;j++)	{
				mat[i][j]=temp[i][j];
			}
		}
	}
}
int main()	{
	memset(b,0,sizeof(b));
	for(int i=0;i<10;i++)	{
		for(int j=i+1;j<10;j++)	{
			b[i][9-j]=b[9-j][i]=1;
		}
	}
	for(int i=0;i<10;i++)	{
		for(int j=0;j<10;j++)	{
			b[i][10]+=b[i][j];
		}
	}
	b[10][10]=1;
	long long t,n;
	long long ans;
	cin>>t;
	while(t--)	{
		cin>>n>>m;
		calculate_matrix(n-1);
		ans=0;
		for(int i=1;i<9;i++)	{
			ans=(ans+2*mat[i][10])%m;
		}
		ans=(ans+mat[0][10]+mat[9][10]+10*mat[10][10])%m;
		cout<<ans<<endl;
	}
	return 0;
}
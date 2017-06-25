#include <bits/stdc++.h>
using namespace std;
struct node	{
	long long a;
	long long b;
	long long c;
}ls[110];
long long tm[16][16];
long long imat[16];
long long[][] multiply(long long tt[][])	{
	long long pp[16][16];
	for(int i=0;i<16;i++)	{
		for(int j=0;j<16;j++)	{
			pp[i][j]=0;
			for(int k=0;k<16;k++)	{
				pp[i][j]+=tt[i][k]*tt[k][j];
			}
		}
	}
	return pp;
}
int power(int n)	{
	if(n==1)	{
		return F;
	}	

}
int main()	{
	int n,k;
	for(int i=0;i<n;i++)	{
		cin>>ls[i].a>>ls[i].b>>ls[i].c;
	}
	memset(imat,0,sizeof(imat));
	imat[0]=1;
	long long numtran;
	for(int i=0;i<n;i++)	{
		for(int j=ls[i].c+1;j<16;j++)	{
			imat[j]=0;
		}
		numtran=ls[i].b-ls[i].a;
		int offset;
		memset(tm,0,sizeof(tm));
		for(int j=1;j<ls[i].c;j++)	{
			tm[j][j-1]=1;
			tm[j][j]=1;
			tm[j][j+1]=1;
		}
		tm[0][0]=1;
		tm[0][1]=1;
		tm[ls[i].c][ls[i].c-1]=1;
		tm[ls[i].c][ls[i].c]=1;
		matrix_expo(numtran);
		multiplymat();
	}
}
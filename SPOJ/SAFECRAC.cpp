#include <bits/stdc++.h>
using namespace std;
long long int mat[100100][10];
int main()	{
	for(int i=0;i<10;i++)	{
		mat[1][i]=1;
	}
	for(int i=2;i<100100;i++)	{
		mat[i][0]=mat[i-1][7];
		mat[i][1]=(mat[i-1][2]+mat[i-1][4])%1000000007;
		mat[i][2]=(mat[i-1][1]+mat[i-1][3]+mat[i-1][5])%1000000007;
		mat[i][3]=(mat[i-1][2]+mat[i-1][6])%1000000007;
		mat[i][4]=(mat[i-1][1]+mat[i-1][5]+mat[i-1][7])%1000000007;
		mat[i][5]=(mat[i-1][2]+mat[i-1][4]+mat[i-1][6]+mat[i-1][8])%1000000007;
		mat[i][6]=(mat[i-1][3]+mat[i-1][5]+mat[i-1][9])%1000000007;
		mat[i][7]=(mat[i-1][4]+mat[i-1][8]+mat[i-1][0])%1000000007;
		mat[i][8]=(mat[i-1][5]+mat[i-1][7]+mat[i-1][9])%1000000007;
		mat[i][9]=(mat[i-1][8]+mat[i-1][6])%1000000007;
	}
	int t;
	scanf("%d",&t);
	while(t--)	{
		int n;
		scanf("%d",&n);
		long long int sum=0;
		for(int i=0;i<10;i++)	{
			sum=(sum+mat[n][i])%1000000007;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
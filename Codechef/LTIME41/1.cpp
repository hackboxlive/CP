#include <bits/stdc++.h>
using namespace std;
int main()	{
	long long int leaves[3][3];
	int t;
	scanf("%d",&t);
	while(t--)	{
		for(int i=0;i<3;i++)	{
			for(int j=0;j<3;j++)	{
				scanf("%lld",&leaves[i][j]);
			}
		}
		long long int maxval=-1;
		long long int a1=0,a2=0,a3=0;
		long long int b1=0,b2=0,b3=0;
		for(int i=0;i<3;i++)	{
			a1=a1+leaves[0][i];
			a2=a2+leaves[1][i];
			a3=a3+leaves[2][i];
			b1=b1+leaves[i][0];
			b2=b2+leaves[i][1];
			b3=b3+leaves[i][2];
		}
		if(a1%2==0)	{
			a1--;
		}
		if(a2%2==0)	{
			a2--;
		}
		if(a3%2==0)	{
			a3--;
		}
		if(b1%2==0)	{
			b1--;
		}
		if(b2%2==0)	{
			b2--;
		}
		if(b3%2==0)	{
			b3--;
		}
		maxval=max(maxval,a1);
		maxval=max(maxval,a2);
		maxval=max(maxval,a3);
		maxval=max(maxval,b1);
		maxval=max(maxval,b2);
		maxval=max(maxval,b3);
		if(maxval==-1)	{
			printf("0\n");
			continue;
		}
		printf("%lld\n",maxval);
	}
	return 0;
}
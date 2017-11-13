#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	scanf("%d",&t);
	long long n,sig;
	while(t--)	{
		cin>>n>>sig;
		if(n==1)	{
			if(sig==0)	{
				printf("1.0000000000000\n");
			}
			else	{
				printf("-1\n");
			}
		}
		else	{
			double ans=1.0;
			ans=ans*n;
			ans=ans/2;
			ans=sqrt(ans);
			ans=ans*sig;
			if(ans==0)	{
				for(int i=0;i<n;i++)	{
					printf("0 ");
				}
				continue;
			}
			printf("%.11lf ",ans);
			ans=ans*-1;
			printf("%.11lf ",ans);
			for(int i=2;i<n;i++)	{
				printf("0 ");
			}
			printf("\n");
		}
	}
	return 0;
}
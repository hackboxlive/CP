#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		int n;
		scanf("%d",&n);
		if(n&1)	{
			for(int i=1;i<=(n-3);i++)	{
				if(i&1)	{
					printf("%d ",i+1);
				}
				else	{
					printf("%d ",i-1);
				}
			}
			printf("%d %d %d\n",n-1,n,n-2);
		}
		else	{
			for(int i=1;i<=n;i++)	{
				if(i&1)	{
					printf("%d ",i+1);
				}
				else	{
					printf("%d ",i-1);
				}
			}
			printf("\n");
		}
	}
	return 0;
}
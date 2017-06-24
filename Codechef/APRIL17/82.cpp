#include <bits/stdc++.h>
using namespace std;
int dig[10];
int arr[10];
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		long long a,b;
		long long ctr=0;
		scanf("%lld %lld",&a,&b);
		for(int i=0;i<10;i++)	{
			scanf("%d",&arr[i]);
		}
		for(long long i=a;i<=b;i++)	{
			memset(dig,0,sizeof(dig));
			long long j=i;
			while(j)	{
				dig[j%10]++;
				j=j/10;
			}
			int flag=0;
			for(int k=0;k<10;k++)	{
				if(arr[k]==dig[k])	{
					flag=1;
					break;
				}
			}
			if(flag==0)	{
				ctr++;
			}
		}
		printf("%lld\n",ctr);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
long long arr[100100];
long long prefix[100100];
long long modulo[100100];
int main()	{
	int t,n,p;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d %d",&n,&p);
		for(int i=0;i<n;i++)	{
			scanf("%lld",&arr[i]);
		}
		prefix[0]=arr[0];
		for(int i=1;i<n;i++)	{
			prefix[i]=prefix[i-1]+arr[i];
		}
		for(int i=0;i<n;i++)	{
			modulo[i]=prefix[i]%p;
		}
		long long ansmax=modulo[0];
		int cntmax=1;
		for(int i=1;i<n;i++)	{
			if(ansmax<modulo[i])	{
				ansmax=modulo[i];
				cntmax=1;
			}
			else if(ansmax==modulo[i])	{
				cntmax++;
			}
		}
		//glitch
		for(int i=0;i<n-1;i++)	{
			for(int j=i+1;j<n;j++)	{
				prefix[j]=prefix[j]-arr[i];
				modulo[j]=prefix[j]%p;
				if(modulo[j]>ansmax)	{
					ansmax=modulo[j];
					cntmax=1;
				}
				else if(ansmax==modulo[j])	{
					cntmax++;
				}
			}
		}
		printf("%lld %d\n",ansmax,cntmax);
	}
	return 0;
}
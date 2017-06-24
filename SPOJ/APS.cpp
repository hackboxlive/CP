#include <bits/stdc++.h>
using namespace std;
int primes[10001000];
long long int val[10001000];
void precompute()	{
	for(int i=2;i<10001000;i++)	{
		if(primes[i]==0)	{
			for(int j=i;j<10001000;j+=i)	{
				if(primes[j]==0)	{
					primes[j]=i;
				}
			}
		}
	}
	val[0]=val[1]=0;
	for(int i=2;i<10001000;i++)	{
		val[i]=val[i-1]+primes[i];
	}
	return;
}
int main()	{
	precompute();
	int t,n;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d",&n);
		printf("%lld\n",val[n]);
	}
	return 0;
}
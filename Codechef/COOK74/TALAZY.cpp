#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	scanf("%d",&t);
	long long int n,b,m;
	while(t--)	{
		scanf("%lld%lld%lld",&n,&b,&m);
		long long int tott=0;
		int ctr=1;
		while(n>0)	{
			if(n%2==0)	{
				tott+=((n/2)*m);
				m=m*2;
				tott=tott+b;
				n=n-(n/2);
			}
			else	{
				tott+=(((n+1)/2)*m);
				m=m*2;
				tott=tott+b;
				n=n-((n+1)/2);
			}
		}
		tott=tott-b;
		printf("%lld\n",tott);
	}
	return 0;
}
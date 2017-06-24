#include <bits/stdc++.h>
using namespace std;
long long int totnum(long long int n)	{
	long long int ans=0;
	int x=0;
	for(int i=__lg(n);i>=0;i--)	{
		if(n & 1LL << i)	{
			ans+=((1LL << i)>>1)*i+1+(1LL<<i)*x++;
		}
	}
	return ans;
}
int main()	{
	int t;
	long long int n,l,r,m;
	scanf("%d",&t);
	while(t--)	{
		scanf("%lld",&n);
		l=0;
		r=n+1;
		while(l!=r)	{
			m=(l+r)/2;
			if(totnum(m)>=n)	{
				r=m;
			}
			else	{
				l=m+1;
			}
		}
		if(totnum(l)==n)	{
			printf("%lld\n",l);
		}
		else	{
			printf("Does Not Exist.\n");
		}
	}
	return 0;
}
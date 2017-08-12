#include <bits/stdc++.h>
using namespace std;
int a[100100];
int main()	{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)	{
		cin>>a[i];
	}
	int mx=a[0],mn=a[0];
	int g=a[0];
	for(int i=1;i<n;i++)	{
		g=__gcd(g,a[i]);
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
	}
	for(int i=0;i<n;i++)	{
		if((int)abs(a[i]-k)%g==0 && k<=mx)	{
			printf("POSSIBLE\n");
			return 0;
		}
	}
	printf("IMPOSSIBLE\n");
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
long long int a[100100];
long long int b[100100];
int main()	{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)	{
		scanf("%lld",&a[i]);
	}
	b[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--)	{
		b[i]=a[i]+a[i+1];
	}
	for(int i=0;i<n;i++)	{
		printf("%lld ",b[i]);
	}
	printf("\n");
	return 0;
}
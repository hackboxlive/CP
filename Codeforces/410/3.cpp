#include <bits/stdc++.h>
using namespace std;
long long arr[100100];
int main()	{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)	{
		scanf("%lld",&arr[i]);
	}
	if(n==1)	{
		printf("YES\n0\n");
		return 0;
	}
	int cnt=0;
	int x,y;
	int vv;
	for(int i=1;i<n;i++)	{
		vv=0;
		while(__gcd(arr[i],arr[i-1])==1)	{
			vv++;
			cnt++;
			x=abs(arr[i-1]-arr[i]);
			y=arr[i-1]+arr[i];
			arr[i-1]=x;
			arr[i]=y;
		}
	}
	printf("YES\n");
	printf("%d\n",cnt);
	return 0;
}
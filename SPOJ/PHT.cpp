#include <bits/stdc++.h>
using namespace std;
long long int arr[1000100];
int solve()	{
	arr[0]=0;
	int i;
	long long int llt=1e12+1000;
	long long int val=0;
	for(i=1;val<=llt;i++)	{
		val=arr[i-1]+i*2+1;
		arr[i]=val;
	}
	return i;
}
int main()	{
	int lt=solve();
	int t;
	long long int n;
	long long int * p;
	scanf("%d",&t);
	int c=0;
	while(t--)	{
		scanf("%lld",&n);
		p=upper_bound(arr,arr+lt,n);
		p--;
		printf("Case %d: %ld\n",++c,p-arr);
	}
	return 0;
}
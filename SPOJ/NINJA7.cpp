#include <bits/stdc++.h>
using namespace std;
int arr1[100100],arr2[100100];
int main()	{
	int t,n;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)	{
			scanf("%d",&arr1[i]);
		}
		for(int i=0;i<n;i++)	{
			scanf("%d",&arr2[i]);
		}
		for(int i=0;i<n;i++)	{
			arr1[i]=arr1[i]-arr2[i];
		}
		sort(arr1,arr1+n);
		long long int sum=0;
		int i;
		for(i=n-1;i>=0;i--)	{
			if(sum+arr1[i]<0)	{
				break;
			}
			sum=sum+arr1[i];
		}
		printf("%d\n",n-1-i);
	}
	return 0;
}
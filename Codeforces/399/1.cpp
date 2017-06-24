#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int main()	{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)	{
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n);
	int maxx=arr[n-1];
	int minn=arr[0];
	int ctr=0;
	for(int i=0;i<n;i++)	{
		if(arr[i]>minn && arr[i]<maxx)	{
			ctr++;
		}
	}
	printf("%d\n",ctr);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		int n,k;
		scanf("%d %d",&n,&k);
		for(int i=0;i<n;i++)	{
			scanf("%d",&arr[i]);
		}
		sort(arr,arr+n);
		int minn=1e9;
		for(int i=k-1;i<n;i++)	{
			if(arr[i]-arr[i-k+1]<minn)	{
				minn=arr[i]-arr[i-k+1];
			}
		}
		printf("%d\n",minn);
	}
	return 0;
}
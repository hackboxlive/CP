#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int main()	{
	int t,n;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d",&n);
		for(int i=0;i<2*n;i++)	{
			scanf("%d",&arr[i]);
		}
		sort(arr,arr+2*n);
		int median=3*n-1;
		median/=2;
		printf("%d\n",arr[median]);
		for(int i=0;i<n;i++)	{
			printf("%d %d ",arr[i],arr[n+i]);
		}
		printf("\n");
	}
	return 0;
}
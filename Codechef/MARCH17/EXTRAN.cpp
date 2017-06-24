#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)	{
			scanf("%d",&arr[i]);
		}
		sort(arr,arr+n);
		int flag=-1;
		if(arr[0]!=arr[1]-1 && arr[1]==arr[2]-1)	{
			printf("%d\n",arr[0]);
			continue;
		}
		for(int i=1;i<n;i++)	{
			if(arr[i]==arr[i-1])	{
				printf("%d\n",arr[i]);
				flag=0;
				break;
			}
		}
		if(flag==0)	{
			continue;
		}
		if(arr[n-1]!=arr[n-2]+1)	{
			printf("%d\n",arr[n-1]);
		}
	}
	return 0;
}
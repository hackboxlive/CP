#include <bits/stdc++.h>
using namespace std;
int arr[1100];
int main()	{
	int n;
	scanf("%d",&n);
	int c=0;
	while(n!=0)	{
		memset(arr,0,sizeof(arr));
		int tot_sum=0;
		int num;
		for(int i=0;i<n;i++)	{
			for(int j=0;j<n;j++)	{
				scanf("%d",&num);
				tot_sum=tot_sum+num;
				arr[i]=arr[i]-num;
				arr[j]=arr[j]+num;
			}
		}
		int red_sum=0;
		for(int i=0;i<n;i++)	{
			if(arr[i]>0)	{
				red_sum=red_sum+arr[i];
			}
		}
		printf("%d. %d %d\n",++c,tot_sum,red_sum);
		scanf("%d",&n);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n,b;
	int arr[100];
	int diff[100];
	scanf("%d%d",&n,&b);
	while(n!=0 && b!=0)	{
		int flag=0;
		memset(arr,0,sizeof(arr));
		memset(diff,0,sizeof(diff));
		for(int i=0;i<b;i++)	{
			scanf("%d",&arr[i]);
		}
		sort(arr,arr+b);
		for(int i=0;i<b;i++)	{
			for(int j=i;j<b;j++)	{
				diff[abs(arr[i]-arr[j])]=1;
			}
		}
		for(int i=0;i<=n;i++)	{
			if(diff[i]==0)	{
				flag=1;
				break;
			}
		}
		if(flag==1)	{
			printf("N\n");
		}
		else	{
			printf("Y\n");
		}
		scanf("%d%d",&n,&b);
	}
	return 0;
}
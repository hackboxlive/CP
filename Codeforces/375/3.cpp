#include <bits/stdc++.h>
using namespace std;
int arr[3000];
int check[3000];
int main()	{
	int n,m;
	memset(check,0,sizeof(check));
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)	{
		scanf("%d",&arr[i]);
	}
	int maxmin=n/m;
	int ptr=1;
	int count_changes=0;
	for(int i=0;i<n;i++)	{
		if(arr[i]<=m)	{
			check[arr[i]]++;
		}
	}
	int pos=1;
	int flag=0;
	for(int i=0;i<n;i++)	{
		flag=0;
		for(int j=1;j<=m;j++)	{
			if(check[j]<maxmin)	{
				flag=1;
				break;
			}
		}
		if(flag==1)	{
			while(check[pos]>=maxmin && pos<m)	{
				pos++;
			}
			if(arr[i]>m)	{
				count_changes++;
				arr[i]=pos;
				check[pos]++;
			}
		}
	}
	flag=0;
	for(int i=0;i<n;i++)	{
		flag=0;
		for(int j=1;j<=m;j++)	{
			if(check[j]<maxmin)	{
				flag=1;
				break;
			}
		}
		if(flag==1)	{
			while(check[pos]>=maxmin && pos<m)	{
				pos++;
			}
			if(arr[i]<=m && check[arr[i]]>maxmin)	{
				check[arr[i]]--;
				arr[i]=pos;
				check[arr[i]]++;
				count_changes++;
			}
		}
	}
	printf("%d %d\n",maxmin,count_changes);
	for(int i=0;i<n;i++)	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
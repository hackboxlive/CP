#include <bits/stdc++.h>
using namespace std;
int arr[7]={0};
int ans[100000]={0};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)	{
			ans[i]=0;
		}
		for (int i=0;i<n;++i)
		{
			for(int j=1;j<7;j++){
				arr[j]=0;
			}
			int cookienum;
			scanf("%d",&cookienum);
			for(int j=0;j<cookienum;j++)
			{
				int no;
				scanf("%d",&no);
				arr[no]++;
			}
			int minim=1000000;
			int index=-1;
			for(int j=1;j<=6;j++)
			{
				if(minim>arr[j])
				{
					minim=arr[j];
					index=j;
				}
			}
			ans[i]+=4*arr[index];
			if(arr[index]>0)
			{
				for(int j=1;j<=6;j++)
				{
					if(j!=index)
					{
						arr[j]=arr[j]-arr[index];
					}
				}
			}
			arr[index]=10000000;
			minim=1000000;
			index=-1;
			for(int j=1;j<=6;j++)
			{
				if(minim>arr[j])
				{
					minim=arr[j];
					index=j;
				}
			}
			ans[i]+=2*arr[index];
			if(arr[index]>0)
			{
				for(int j=1;j<=6;j++)
				{
					if(j!=index)
					{
						arr[j]=arr[j]-arr[index];
					}
				}
			}
			arr[index]=10000000;
			minim=1000000;
			index=-1;
			for(int j=1;j<=6;j++)
			{
				if(minim>arr[j])
				{
					minim=arr[j];
					index=j;
				}
			}
			ans[i]+=arr[index];
			arr[index]=10000000;
			ans[i]+=cookienum;
		}
		int max1=ans[0];
		int index=0;
		for (int i=0;i<n;++i)
		{
			if(max1<ans[i])
			{
				max1=ans[i];
				index=i;
			}
		}
		int count=0;
		for(int i=0;i<n;++i)
		{
			if(ans[i]==max1)
				count++;
		}
		if(count==1 && index==0)
		{
			printf("chef\n");
		}
		else if(count==1 && index!=0)
		{
			printf("%d\n",index+1);
		}
		else
			printf("tie\n");
		memset(ans,0,sizeof(ans));
	}
	return 0;
}
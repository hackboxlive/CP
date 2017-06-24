#include <bits/stdc++.h>
using namespace std;
int arr[1001000];
int state[1001000];
int main()	{
	int t,o1,o2;
	int val;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d%d",&o1,&o2);
		int n=o1*o2;
		for(int i=0;i<n;i++)	{
			scanf("%d",&val);
			if(val==0)	{
				arr[i]=-1;
			}
			else	{
				arr[i]=1;
			}
//			cout<<arr[i]<<" ";
		}
//		cout<<endl;
		for(int i=0;i<o1;i++)	{
			state[i]=0;
			for(int j=0;j<o2;j++)	{
				state[i]+=arr[i*o2+j];
			}
		}
		int cnt=0;
		for(int i=0;i<o1;i++)	{
//			cout<<state[i]<<" ";
			if(state[i]>0)	{
				cnt++;
			}
		}
//		cout<<cnt<<endl;
		if(cnt>o1-cnt)	{
			printf("1\n");
			continue;
		}
		int remdis;
		int adddis;
		int flag=0;
		for(int i=1;i<o2;i++)	{
			cnt=0;
			for(int j=0;j<o1;j++)	{
				remdis=o2*j+i-1;
				adddis=o2*(j+1)+i-1;
				if(adddis>=n)	{
					adddis-=n;
				}
				state[j]-=arr[remdis];
				state[j]+=arr[adddis];
				if(state[j]>0)	{
					cnt++;
				}
			}
			if(cnt>o1-cnt)	{
				printf("1\n");
				flag=1;
				break;
			}
		}
		if(flag==0)	{
			printf("0\n");
		}
	}
	return 0;
}
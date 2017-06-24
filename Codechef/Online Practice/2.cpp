#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int sum_arr[100100];
int rev_sum[100100];
bool comp(const int &p1,const int &p2)	{
	return p1>p2;
}
int main()	{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)	{
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n,comp);
	sum_arr[0]=arr[0];
	rev_sum[0]=arr[n-1];
	for(int i=1;i<n;i++)	{
		sum_arr[i]=sum_arr[i-1]+arr[i];
		rev_sum[i]=rev_sum[i-1]+arr[n-1-i];
//		cout<<sum_arr[i];
	}
	int q,val;
	scanf("%d",&q);
	while(q--)	{
		scanf("%d",&val);
		if(n%(val+1)==0)	{
			printf("%d\n",rev_sum[n/(val+1)-1]);
		}
		else	{
			printf("%d\n",rev_sum[(n/(val+1))]);
		}
	}
	return 0;
}
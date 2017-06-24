#include <bits/stdc++.h>
using namespace std;
int arr[15];
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)	{
			cin>>arr[i];
		}
		sort(arr,arr+n);
		int sum=0, totsum=0;
		int i;
		for(i=0;i<n;i++)	{
			if(sum+arr[i]>300)	{
				break;
			}
			sum=sum+arr[i];
			totsum += sum;
		}
//		cout << totsum << endl;
		int finalsum=0;
//		for(int j=0;j<i;j++)	{
//			for(int k=0;k<=j;k++)	{
//				finalsum+=arr[k];
//			}
//		}
		cout<<i<<" "<<totsum<<endl;
	}
	return 0;
}
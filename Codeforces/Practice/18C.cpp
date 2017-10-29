#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int main()	{
	int n;
	cin>>n;
	int summ=0;
	int ctr=0;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
		summ+=arr[i];
	}
	int pre=0;
	for(int i=1;i<=n-1;i++)	{
		pre+=arr[i-1];
		summ-=arr[i-1];
		if(pre==summ)	{
			ctr++;
		}
	}
	cout<<ctr<<endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int arr[200200];
int main()	{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	long long int minn=1e18;
	for(int i=1;i<n;i++)	{
		if(arr[i]-arr[i-1]<minn)	{
			minn=arr[i]-arr[i-1];
		}
	}
	int cnt=0;
	for(int i=1;i<n;i++)	{
		if(arr[i]-arr[i-1]==minn)	{
			cnt++;
		}
	}
	cout<<minn<<" "<<cnt;
	return 0;
}
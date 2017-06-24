#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int main()	{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int ctr=0;
	for(int i=0;i<n-1;i++)	{
		if(arr[i]==0)	{
			continue;
		}
		if(i<n-2)	{
			if(arr[i]==arr[i+2])	{
				cout<<"-1\n";
				return 0;
			}
		}
		if(arr[i]==arr[i+1])	{
			i++;
			ctr++;
		}
	}
	cout<<ctr<<endl;
	return 0;
}
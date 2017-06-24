#include <bits/stdc++.h>
using namespace std;
long long int arr[300300];
int main()	{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	bool flag=false;
	for(int i=0;i<n-2;i++)	{
		if(arr[i]+arr[i+1]>arr[i+2])	{
			flag=true;
			break;
		}
	}
	if(flag==true)	{
		cout<<"YES";
	}
	else	{
		cout<<"NO";
	}
	return 0;
}
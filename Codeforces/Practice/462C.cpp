#include <bits/stdc++.h>
using namespace std;
int arr[300300];
long long pre[300300];
int main()	{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	pre[n-1]=arr[n-1];
	for(int i=n-2;i>=0;i--)	{
		pre[i]=pre[i+1]+arr[i];
	}
	long long tot=pre[0];
	for(int i=0;i<n-1;i++)	{
		tot+=arr[i];
		tot+=pre[i+1];
	}
	cout<<tot<<endl;
	return 0;
}
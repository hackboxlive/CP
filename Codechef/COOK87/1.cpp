#include <bits/stdc++.h>
using namespace std;
int arr[10010];
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n;i++)	{
			cin>>arr[i];
		}
		sort(arr,arr+n);
		cout<<arr[(n+k)/2]<<endl;
	}
	return 0;
}
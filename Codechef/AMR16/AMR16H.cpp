#include <bits/stdc++.h>
using namespace std;
long long arr[100100];
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		long long prev=0;
		int n;
		cin>>n;
		for(int i=0;i<n;i++)	{
			cin>>arr[i];
		}
		sort(arr,arr+n);
		long long ans=0;
		prev=0;
		ans=prev;
		for(int i=n-2;i>=0;i--)	{
			prev+=arr[i];
			ans+=prev;
		}
		prev+=arr[n-1];
		ans+=prev;
		cout<<ans<<endl;
	}
	return 0;
}

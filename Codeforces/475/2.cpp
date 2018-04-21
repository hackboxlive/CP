#include <bits/stdc++.h>
using namespace std;
long long arr[1010];
int main()	{
	long long n,a,b,c,t;
	cin>>n>>a>>b>>c>>t;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
	}
	if(b>c)	{
		long long ans=n*a;
		cout<<ans<<endl;
	}
	else	{
		//sort(arr,arr+n);
		long long ans=0;
		long long left;
		for(int i=0;i<n;i++)	{
			left=t-arr[i];
			ans+=c*left;
			ans-=b*left;
			ans+=a;
		}
		cout<<ans<<endl;
	}
	return 0;
}
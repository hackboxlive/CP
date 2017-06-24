#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long arr[300300];
long long fastexpo(int power)	{
	if(power==1)	{
		return 2;
	}
	if(power==0)	{
		return 1;
	}
	if(power%2==0)	{
		long long val=fastexpo(power/2);
		val=(val*val)%mod;
		return val;
	}
	long long val=fastexpo(power/2);
	val=(val*val)%mod;
	val=(val*2)%mod;
	return val;
}
int main()	{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	for(int i=1;i<n;i++)	{
		arr[i]=arr[i-1]+arr[i];
	}
	if(n==1)	{
		cout<<"0\n";
		return 0;
	}
	int looplim=n-2;
	looplim=looplim/2;
	long long ans=0;
	long long powtwo1,powtwo2;
	long long firsttuple,sectuple;
	for(int i=0;i<=looplim;i++)	{
		powtwo1=fastexpo(i);
		powtwo2=fastexpo(n-2-i);
		if(n-2-i != i)	{
			powtwo1=(powtwo1+powtwo2)%mod;
		}
		firsttuple=arr[n-1]-arr[n-2-i];
		sectuple=arr[i];
		firsttuple=(firsttuple-sectuple)%mod;
//		cout<<firsttuple<<" "<<powtwo1<<endl;
		ans=(ans+((firsttuple*powtwo1)%mod))%mod;
	}
	cout<<ans<<endl;
	return 0;
}
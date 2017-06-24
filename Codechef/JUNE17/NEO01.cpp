#include <bits/stdc++.h>
using namespace std;
int arr[100100];
long long dp[100100];
int cnt[100100];
long long sum[100100];
bool comp(const int &a,const int &b)	{
	return a>b;
}
int main()	{
	int t;
	int n;
	cin>>t;
	while(t--)	{
		cin>>n;
		for(int i=0;i<n;i++)	{
			cin>>arr[i];
		}
		sort(arr,arr+n,comp);
		int k=0;
		sum[0]=arr[0];
		for(int i=1;i<n;i++)	{
			sum[i]=sum[i-1]+arr[i];
			if((sum[i-1]+arr[i])*(i+1)>=sum[i-1]*i+arr[i])	{
				k=i;
			}
			else	{
				break;
			}
		}
		k++;
		if(k==n)	{
			cout<<sum[n-1]*n<<endl;
		}
		else	{
			long long ans=0;
			for(int i=0;i<k;i++)	{
				ans=sum[i];
			}
			ans=ans*k;
			for(int i=k;i<n;i++)	{
				ans=ans+arr[i];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
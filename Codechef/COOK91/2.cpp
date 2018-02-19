#include <bits/stdc++.h>
using namespace std;

long long arr[100100];
int dp[100100];
int mxx[100100];
int main()	{
	int t;
	cin>>t;
	long long n,k,b;
	while(t--)	{
		cin>>n>>k>>b;
		if(k==0)	{
			//special case
			int ans=0;
			for(int i=0;i<n;i++)	{
				cin>>arr[i];
				if(arr[i]>=b)	{
					ans++;
				}
			}
			cout<<ans<<endl;
			continue;
		}
		for(int i=0;i<n;i++)	{
			mxx[i]=1;
			cin>>arr[i];
		}
		long long temp;int pos;
		sort(arr,arr+n);
		dp[0]=1;
		mxx[0]=1;
		int ans=1;
		for(int i=1;i<n;i++)	{
			dp[i]=1;
			temp=arr[i]-b;
			if(temp<0)	{
				mxx[i]=max(mxx[i-1],dp[i]);
			}
			else	{
				temp/=k;
				pos=upper_bound(arr,arr+i,temp)-arr;
				pos--;
				if(pos>=0)	{
					dp[i]=max(dp[i],mxx[pos]+1);
				}
				mxx[i]=max(mxx[i-1],dp[i]);
			}
			ans=max(ans,dp[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
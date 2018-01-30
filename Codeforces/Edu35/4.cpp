#include <bits/stdc++.h>
using namespace std;
int arr[1510];
int cnt[1510];
int main()	{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)	{
		cin>>arr[i];
		cnt[arr[i]]=i;
		if(cnt[arr[i]]<arr[i])	{
			ans+=(arr[i]-cnt[arr[i]]);
		}
	}
	int m,l,r,num;
	cin>>m;
	while(m--)	{
		cin>>l>>r;
		num=(r-l+1)/2;
		for(int i=0;i<num;i++)	{
			if(cnt[arr[l+i]]<arr[l+i])	{
				ans-=(arr[l+i]-cnt[arr[l+i]]);
			}
			if(cnt[arr[r-i]]<arr[r-i])	{
				ans-=(arr[r-i]-cnt[arr[r-i]]);
			}
			swap(cnt[arr[l+i]],cnt[arr[r-i]]);
			swap(arr[l+i],arr[r-i]);
			if(cnt[arr[l+i]]<arr[l+i])	{
				ans+=(arr[l+i]-cnt[arr[l+i]]);
			}
			if(cnt[arr[r-i]]<arr[r-i])	{
				ans+=(arr[r-i]-cnt[arr[r-i]]);
			}
			cout<<"ans="<<ans<<endl;
		}
		for(int i=1;i<=n;i++)	{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		for(int i=1;i<=n;i++)	{
			cout<<cnt[i]<<" ";
		}
		cout<<endl;
		cout<<ans<<endl;
		if(ans&1)	{
			cout<<"odd\n";
		}
		else	{
			cout<<"even\n";
		}
	}
	return 0;
}
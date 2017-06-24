#include <bits/stdc++.h>
using namespace std;
int main()	{
	long long int l,r,k,start,end;
	cin>>l>>r>>start>>end>>k;
	if(start>r || end<l)	{
		cout<<"0";
		return 0;
	}
	long long int ans;
	if(start>=l && end<=r)	{
		ans=end-start+1;
		if(k>=start && k<=end)	{
			ans--;
		}
		cout<<ans;
		return 0;
	}
	if(start<l && end<=r)	{
		start=l;
		ans=end-start+1;
		if(k>=start && k<=end)	{
			ans--;
		}
		cout<<ans;
		return 0;
	}
	if(start>=l && end>r)	{
		end=r;
		ans=end-start+1;
		if(k>=start && k<=end)	{
			ans--;
		}
		cout<<ans;
		return 0;
	}
	if(start<l && end>r)	{
		start=l;
		end=r;
		ans=end-start+1;
		if(k>=start && k<=end)	{
			ans--;
		}
		cout<<ans;
		return 0;
	}
}
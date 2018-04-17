#include <bits/stdc++.h>
using namespace std;
long long a[100100],b[100100];
//long long dp[1010][1010];
const long long modd=1e9+7;
int main()	{
	long long n;
	cin>>n;
	for(long long i=0;i<n;i++)	{
		cin>>a[i];
		a[i]+=(i+1);
	}
	for(long long i=0;i<n;i++)	{
		cin>>b[i];
		b[i]+=(i+1);
	}
	sort(a,a+n);
	sort(b,b+n);
	long long a_s=0,b_s=0;
	for(long long i=0;i<n;i++)	{
		a_s+=a[i];
		b_s+=b[i];
	}
	a_s%=modd;
	b_s%=modd;
	long long ans=0;
	for(long long i=0;i<n;i++)	{
		ans+=(a_s*b_s);
		ans%=modd;
		a_s-=a[i];
		a_s%=modd;
		if(a_s<0)	{
			a_s+=modd;
		}
		b_s-=b[i];
		b_s%=modd;
		if(b_s<0)	{
			b_s+=modd;
		}
	}
	cout<<ans<<endl;
	return 0;
}
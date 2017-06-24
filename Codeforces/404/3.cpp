#include <bits/stdc++.h>
using namespace std;
long long int findans(long long int n,long long int m)	{
	long long int lo = 0;
	long long int hi = 2e9;
	long long int mid;
	long long int val;
	while(lo<hi)	{
//		cout<<lo+m<<" "<<hi+m<<endl;
		mid = (lo + hi) / 2;
		val = mid * (mid+1)/2;
		if(val >= n)	{
			hi = mid;
		}
		else	{
			lo = mid + 1;
		}
	}
	return lo;
}
int main()	{
	long long int n,m;
	cin>>n>>m;
	if(n > m)	{
		long long int still = n - m;
		long long int i = m;
		long long int ans = m + findans(still,m);
		cout<<ans<<endl;
	}
	else	{
		cout<<n<<endl;
	}
	return 0;
}
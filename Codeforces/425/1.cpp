#include <bits/stdc++.h>
using namespace std;
int main()	{
	long long n,k;
	cin>>n>>k;
	long long rem=(long long)n%k;
	n=n-rem;
	long long one=(long long)n/k;
	if(one%2==0)	{
		cout<<"NO\n";
	}
	else	{
		cout<<"YES\n";
	}
	return 0;
}
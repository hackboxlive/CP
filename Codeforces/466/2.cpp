#include <bits/stdc++.h>
using namespace std;

int main()	{
	long long n,k,a,b;
	cin>>n>>k>>a>>b;
	long long ans=(n-1)*a;
	if(k==1)	{
		cout<<ans<<endl;
		return 0;
	}
	
	long long temp=0;
	while(n!=1)	{
		temp+=a*(n%k);
		temp+=b;
		n/=k;
		if(n<k)	{
			temp+=a*(n-1);
			break;
		}
	}
	cout<<min(ans,temp)<<endl;
	return 0;
}
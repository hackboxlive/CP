#include <bits/stdc++.h>
using namespace std;
const long long modu=1e9+7;
long long powerr(long long a,long long m)	{
	if(m==0)	{
		return 1;
	}
	if(m==1)	{
		return a;
	}
	long long ans=powerr(a,m/2);
	ans=(ans*ans)%modu;
	if(m%2==1)	{
		ans=(ans*a)%modu;
	}
	return ans;
}
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		long long n,w;
		cin>>n>>w;
		cout<<powerr(10,n-2)<<endl;
		if(abs(w)>9 || w==9)	{
			cout<<"0\n";
		}
		else if(w<0)	{
			cout<<((10-abs(w))*powerr(10,n-2))%modu<<endl;
		}
		else	{
			cout<<((9-abs(w))*powerr(10,n-2))%modu<<endl;
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n,k;
	cin>>n>>k;
	if(k==0)	{
		cout<<"0 0\n";
		return 0;
	}
	//minimum
	if(k==n)	{
		cout<<"0 ";
	}
	else	{
		cout<<"1 ";
	}
	//maximum
	if(n/k>=3)	{
		cout<<2*k<<endl;
	}
	else	{
		cout<<n-k<<endl;
	}
	return 0;
}
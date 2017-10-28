#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n;
	cin>>n;
	long long ans=1;
	if(n==0)	{
		cout<<"1\n";
		return 0;
	}
	for(int i=2;i<=n;i++)	{
		ans=ans*3;
		ans%=1000003;
	}
	cout<<ans<<endl;
	return 0;
}
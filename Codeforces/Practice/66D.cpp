#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n;
	cin>>n;
	if(n==2)	{
		cout<<"-1\n";
		return 0;
	}
	cout<<"15\n10\n";
	for(int i=1;i<=n-2;i++)	{
		cout<<(3LL<<i)<<endl;
	}
	return 0;
}
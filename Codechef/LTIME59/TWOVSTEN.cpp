#include <bits/stdc++.h>
using namespace std;

int main()	{
	int t;
	cin>>t;
	while(t--)	{
		int x;
		cin>>x;
		if(x%10==0)	{
			cout<<"0\n";
			continue;
		}
		if(x%5==0)	{
			cout<<"1\n";
			continue;
		}
		cout<<"-1\n";
	}
	return 0;
}
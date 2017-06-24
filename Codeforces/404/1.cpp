#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n;
	cin>>n;
	string s;
	long long int ans = 0;
	for(int i=0;i<n;i++)	{
		cin>>s;
		if(s[0] == 'T')	{
			ans += 4;
		}
		if(s[0] == 'C')	{
			ans += 6;
		}
		if(s[0] == 'O')	{
			ans += 8;
		}
		if(s[0] == 'D')	{
			ans += 12;
		}
		if(s[0] == 'I')	{
			ans += 20;
		}
	}
	cout<<ans<<endl;
	return 0;
}
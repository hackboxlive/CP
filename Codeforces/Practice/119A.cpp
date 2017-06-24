#include <bits/stdc++.h>
using namespace std;
int main()	{
	int a,b,n;
	int turn=0;
	cin>>a>>b>>n;
	while(true)	{
		if(turn == 0)	{
			int gg = __gcd(a,n);
			if(gg <= n)	{
				n = n - gg;
				turn = 1;
			}
			else	{
				cout<<"1";
				return 0;
			}
		}
		else	{
			int gg = __gcd(b,n);
			if(gg <= n)	{
				n = n - gg;
				turn = 0;
			}
			else	{
				cout<<"0";
				return 0;
			}
		}
	}
	return 0;
}
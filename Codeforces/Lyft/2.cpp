#include <bits/stdc++.h>
using namespace std;

int main()	{
	int t;
	cin>>t;
	while(t--)	{
		long long a, b;
		cin>>a>>b;
		if(a-b > 1)	{
			cout << "NO\n";
		}
		else	{
			a = a + b;
			b = sqrt(a);
			bool flag = true;
			for(int i = 2; i <= b; i++)	{
				if(a % i == 0)	{
					flag = false;
					break;
				}
			}
			if(flag)	{
				cout << "YES\n";
			}
			else	{
				cout << "NO\n";
			}
		}
	}
	return 0;
}
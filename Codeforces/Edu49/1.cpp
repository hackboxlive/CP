#include <bits/stdc++.h>
using namespace std;

int main()	{
	int t;
	cin >>t;
	while(t--)	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		int cnt = 0;
		for(int i = 0; i < n/2; i++)	{
			if(s[i] == 'a')	{
				if(s[n - 1 - i] == 'a' || s[n - 1 - i] == 'c')	{
					cnt++;
				}
			}
			else if(s[i] == 'z')	{
				if(s[n - 1 - i] == 'z' || s[n - 1 - i] == 'x')	{
					cnt++;
				}
			}
			else	{
				if(abs(s[i] - s[n - 1 - i]) == 2 || s[i] == s[n - 1 -i])	{
					cnt++;
				}
			}
		}
		if(cnt == n/2)	{
			cout << "YES\n";
		}
		else	{
			cout << "NO\n";
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()	{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ctr = 0;
	for(int i = 0; i < n; i++)	{
		if(s[i] == '8')	{
			ctr++;
		}
	}
	int ans;
	ans = n/11;
	cout << min(ctr, ans) << endl;
	return 0;
}
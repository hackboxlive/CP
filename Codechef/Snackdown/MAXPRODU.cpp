#include <bits/stdc++.h>
using namespace std;

const long long modu = 1e9 + 7;

int main()	{
	int t;
	cin >> t;
	while(t--)	{
		long long n, k;
		cin >> n >> k;
		if((k * (k + 1)) / 2 > n)	{
			cout << "-1\n";
			continue;
		}
		if(((k + 2) * (k + 1)) / 2 > n + 1)	{
			cout << "0\n";
			continue;
		}
		long long ans = 1;
		long long factor = (n - ((k + 2) * (k + 1)) / 2 + 1) / k;
		long long rem = (n - ((k + 2) * (k + 1)) / 2 + 1) - factor * k;
		//cout << factor << " " << rem << endl;
		for(int i = 1; i <= k - rem; i++)	{
			ans *= (i + 1 + factor);
			ans %= modu;
			ans *= (i + factor);
			ans %= modu;
		}
		for(int i = k - rem + 1; i <= k; i++)	{
			ans *= (i + 2 + factor);
			ans %= modu;
			ans *= (i + 1 + factor);
			ans %= modu;
		}
		cout << ans << endl;
	}
	return 0;
}

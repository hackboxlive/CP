#include <bits/stdc++.h>
using namespace std;

const int LIM = 1e5;
const long long MODD = 1e9 + 7;

int factors[200200];
int f[200200];

void precompute()	{
	factors[1] = 1;
	for(int i = 2; i <= 2 * LIM; i++)	{
		if(factors[i] == 0)	{
			for(int j = i; j <= 2 * LIM; j += i)	{
				if(factors[j] == 0)	{
					factors[j] = i;
				}
			}
		}
	}
}

long long power_expo(long long a, long long n, long long modd)	{
	if(n == 0)	{
		return 1;
	}
	if(n == 1)	{
		return a;
	}
	long long ans = power_expo(a, n/2, modd);
	ans = ans * ans;
	ans %= modd;
	if(n%2 == 1)	{
		ans = ans * a;
		ans %= modd;
	}
	return ans;
}

void get_factors(int n, int check)	{
	while(n != 1)	{
		f[factors[n]] += check;
		n /= factors[n];
	}
}

int main()	{
	precompute();
	int t;
	cin >> t;
	while(t--)	{
		long long a, b, n;
		cin >> a >> b >> n;
		for(int i = 1; i <= 2 * n; i++)	{
			f[i] = 0;
		}
		for(int i = 1; i <= n; i++)	{
			get_factors(i, -1);
			get_factors(n + i, 1);
		}
		long long ans = 1;
		for(int i = 2; i <= 2 * n; i++)	{
			ans *= power_expo(i, f[i], MODD - 2);
			ans %= (MODD - 2);
		}
		cout << ans << endl;
		ans = power_expo(b, ans, MODD - 1);
		//cout << ans << endl;
		ans = power_expo(a, ans, MODD);
		cout << ans << endl;
	}
	return 0;
}

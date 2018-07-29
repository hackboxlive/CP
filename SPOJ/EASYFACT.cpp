#include <bits/stdc++.h>
using namespace std;

const int LIM = 1e8;
vector<int> primes;

void precomute()
{
	bitset<LIM> sieve;
	for(int i = 3; i < sqrt(LIM); i += 2)
	{
		if(sieve[i] == 0)
		{
			primes.push_back(i);
			for(int j = i * i; j < LIM; j += i)
			{
				sieve[j] = 1;
			}
		}
	}
	for(int i = sqrt(LIM) - 1; i < LIM; i += 2)
	{
		if(sieve[i] == 0)
		{
			primes.push_back(i);
		}
	}
}

long long fast_expo(long long a, long long n, long long m)
{
	if(n == 0)
	{
		return 1;
	}
	if(n == 1)
	{
		return a;
	}
	long long ans = fast_expo(a, n/2, m);
	ans = ans * ans;
	ans %= m;
	if(n%2 == 1)
	{
		ans = ans * a;
	}
	return ans;
}

int main()
{
	precomute();
	cout << primes.size() <<endl;
	int t;
	cin >> t;
	while(t--)
	{
		long long n, m;
		cin >> n >> m;
		vector<long long> factors_count;
		long long fact;
		long long cnt;
		int id = -1;
		for(int i = 0; i < primes.size(); i++)
		{
			if(primes[i] > sqrt(n))
			{
				id = i;
				break;
			}
			fact = primes[i];
			cnt = 0;
			while(fact <= n)
			{
				cnt += n/fact;
				fact *= primes[i];
			}
			factors_count.push_back(cnt);
		}
		int rem = upper_bound(primes.begin(), primes.end(), n) - primes.begin();
		rem--;
		rem = rem - id + 1;
		long long ans = fast_expo(2, rem, m);
		for(int i = 0; i < factors_count.size(); i++)
		{
			ans *= (factors_count[i] + 1);
			ans %= m;
		}
		ans--;
		if(ans < 0)
		{
			ans += m;
			ans %= m;
		}
		cout << ans << endl;
	}
}

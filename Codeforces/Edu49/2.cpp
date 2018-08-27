#include <bits/stdc++.h>
using namespace std;

int main()	{
	long long n, q;
	cin >> n >> q;
	long long x, y;
	long long s;
	long long ans;
	long long half = n * n + 1;
	half /= 2;
	while(q--)	{
		cin >> x >> y;
		s = x + y;
		if(s % 2 == 0)	{
			ans = 0;
			ans += (((x - 1)/2) * n);
			if(x % 2 == 0)	{
				ans += (n + 1)/2;
				ans += y/2;
			}
			else	{
				ans += (y + 1)/2;
			}
		}
		else	{
			ans = half;
			ans += (((x - 1)/2) * n);
			if(x % 2 == 0)	{
				ans += n/2;
				ans += (y + 1)/2;
			}
			else	{
				ans += y/2;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
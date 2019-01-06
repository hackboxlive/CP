#include <bits/stdc++.h>
using namespace std;

int main()	{
	long long n;
	cin >> n;
	if(n==1)
	{
		cout << "2\n";
	}
	else
	{
		long long rt = sqrt(n);
		if(rt * rt == n)
		{
			long long ans = 2 * rt;
			cout << ans << endl;
		}
		else	{
			long long lo = rt * rt;
			long long hi = (rt + 1) * (rt + 1);
			if(hi - n < n - lo)
			{
				long long ans = 2 * rt + 2;
				cout << ans << endl;
			}
			else
			{
				long long ans = 2 * rt + 1;
				cout << ans << endl;
			}
		}
	}
	return 0;
}
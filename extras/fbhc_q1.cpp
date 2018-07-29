#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t,tt = 1;
	cin >> t;
	while(t--)
	{
		long long n,k,v;
		cin >> n >> k >> v;
		long long g = __gcd(n,k);
		g = n * k / g;
		v = (v - 1) % g;
		vector<string> vv;
		string s;
		for(int i = 0; i < n; i++)
		{
			cin >> s;
			vv.push_back(s);
		}
		while(v--)
		{
			vector<string> temp;
			for(int i = k; i < n; i++)
			{
				temp.push_back(vv[i]);
			}
			for(int i = 0; i < k; i++)
			{
				temp.push_back(vv[i]);
			}
			vv = temp;
		}
		cout << "Case #" << tt << ": ";
		for(int i = 0; i < k; i++)
		{
			cout << vv[i] << " ";
		}
		tt++;
		cout << endl;
	}
	return 0;
}

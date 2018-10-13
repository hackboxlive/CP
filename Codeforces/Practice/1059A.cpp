#include <bits/stdc++.h>
using namespace std;

int t[100100], l[100100];
int main()	{
	int n, L, a;
	cin >> n >> L >> a;
	for(int i = 0; i < n; i++)	{
		cin >> t[i] >> l[i];
	}
	int cur = 0;
	int ans = 0;
	ans += (t[0] - cur)/a;
	cur = t[0] + l[0];
	for(int i = 1; i < n; i++)	{
		ans += (t[i] - cur)/a;
		cur = t[i] + l[i];
	}
	ans += (L - cur)/a;
	cout << ans << endl;
	return 0;
}

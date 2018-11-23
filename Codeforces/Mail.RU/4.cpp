#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;
long long sex(int x)	{
	return (long long)x * (x - 1) / 2;
}
int main()	{
	int n, k;
	cin >> n >> k;
	int temp;
	int pre = 0;
	for(int i = 0; i < n; i++)	{
		cin >> temp;
		pre ^= temp;
		temp = min(pre, (1 << k) - 1 - pre);
		mp[temp]++;
	}
	long long ans = 0;
	for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)	{
		ans += (sex(it->second/2) + sex((it->second + 1)/2));
	}
	cout << ans << endl;
	return 0;
}

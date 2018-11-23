#include <bits/stdc++.h>
using namespace std;


int main()	{
	int x, y, z, t1, t2, t3;
	cin >> x >> y >> z >> t1 >> t2 >> t3;
	int ts = abs(x - y) * t1;
	int te = (abs(x - y) + abs(x - z)) * t2 + 3 * t3;
	if(te <= ts)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
	return 0;
}
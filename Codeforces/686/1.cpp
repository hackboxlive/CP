#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		for(int i = 0; i < n - 1; ++i)
		{
			cout << i + 2 << " ";
		}
		cout << 1 << endl;
	}
}
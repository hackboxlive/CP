#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, tt = 1;
	cin >> t;
	int p[51];
	while(t--)
	{
		int n;
		cin >> n;
		for(int i = 0; i <= n; i++)
		{
			cin >> p[i];
		}
		if(n % 2 == 1)
		{
			cout << "Case #" << tt << ": 1" << endl;
			cout << "0.0" << endl;
		}
		else
		{
			cout << "Case #" << tt << ": 0" << endl;
		}
		tt++;
	}
	return 0;
}

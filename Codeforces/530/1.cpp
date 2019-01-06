#include <bits/stdc++.h>
using namespace std;

int main()
{
	int w,h,u1,d1,u2,d2;
	cin >> w >> h;
	cin >> u1 >> d1;
	cin >> u2 >> d2;
	if(d1 < d2)
	{
		swap(d1, d2);
		swap(u1, u2);
	}
	int ans = w;
	for(int i = h; i >= 1; i--)
	{
		ans += i;
		if(i == d1)
		{
			ans = max(0, ans - u1);
		}
		if(i == d2)
		{
			ans = max(0, ans - u2);
		}
	}
	cout << ans << endl;
	return 0;
}
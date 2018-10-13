#include <bits/stdc++.h>
using namespace std;

int main()	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int g = 1;
	vector<int> a, b, ans;
	for(int i = 1; i <= n; i++)	{
		a.push_back(i);
	}
	bool flag = false;
	while(a.size() != 1)	{
		if(a.size() != 3)	{
			for(int i = 0; i < a.size(); i += 2)	{
				ans.push_back(g);
			}
			for(int i = 1; i < a.size(); i += 2)	{
				b.push_back(a[i]);
			}
			g *= 2;
		}
		else	{
			ans.push_back(g);
			ans.push_back(g);
			ans.push_back(g * 3);
			flag = true; break;
		}
		a.clear();
		for(int i = 0; i < b.size(); i++)	{
			a.push_back(b[i]);
		}
		b.clear();
	}
	if(!flag)	{
		ans.push_back(a[0]);
	}
	for(int i = 0; i < n; i++)	{
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
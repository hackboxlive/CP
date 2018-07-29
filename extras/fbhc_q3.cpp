#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, tt = 1;
	cin >> t;
	while(t--)
	{
		string s;
		string ans;
		cin >> s;
		int next_id = -1;
		for(int i = 1; i < s.length(); i++)
		{
			if(s[i] == s[0])
			{
				next_id = i;
				break;
			}
		}
		if(next_id == -1)
		{
			ans = "Impossible";
		}
		string temp = "";
		for(int i = 0; i < next_id; i++)
		{
			temp += s[i];
		}
		temp += s;
		if(temp.substr(0, s.length()).compare(s) == 0)
		{
			ans = "Impossible";
		}
		else
		{
			ans = temp;
		}
		cout << "Case #" << tt << ": " << ans << endl;
		tt++;
	}
	return 0;
}

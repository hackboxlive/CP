#include <bits/stdc++.h>
using namespace std;

bool isAlpha(char alp)
{
	if(alp >= 'a' && alp <= 'z')
	{
		return true;
	}
	return false;
}
int main()	{
	string s;
	cin >> s;
	int k;
	cin >> k;
	int cnd = 0, sf = 0, alp = 0;
	vector<int> sfp;
	vector<int> cndp;
	for(int i = 0; i < s.length(); i++)	
	{
		if(s[i] == '?')
		{
			cnd++;
			cndp.push_back(i);
		}
		if(s[i] == '*')
		{
			sf++;
			sfp.push_back(i);
		}
		if(isAlpha(s[i]))
		{
			alp++;
		}
	}
	if(sf == 0)
	{
		if(k < alp - cnd || k > alp)
		{
			cout << "Impossible\n";
			return 0;
		}
		else
		{
			int min_print = alp - cnd;
			string ans = "";
			for(int i = 0; i < s.length() - 1;)
			{
				if(isAlpha(s[i]) && isAlpha(s[i + 1]))
				{
					ans += s[i];
					i++;				
				}
				else// if(isAlpha(s[i]) && s[i + 1] == '?')
				{
					if(min_print < k)
					{
						ans += s[i];
						min_print++;
					}
					i+=2;
				}
			}
			if(isAlpha(s[s.length() - 1]))
			{
				ans += s[s.length() - 1];
			}
			cout << ans << endl;
			return 0;
		}
	}
	else
	{
		if(k < alp - cnd - sf)
		{
			cout << "Impossible\n";
			return 0;
		}
		else
		{
			int min_print = alp - cnd - sf;
			string ans = "";
			for(int i = 0; i < s.length() - 1;)
			{
				if(isAlpha(s[i]) && isAlpha(s[i + 1]))
				{
					ans += s[i];
					i++;				
				}
				else if(isAlpha(s[i]) && s[i + 1] == '?')
				{
					i+=2;
				}
				else
				{
					for(int j = min_print + 1; j <= k; j++)
					{
						ans += s[i];
						min_print++;
					}
					i+=2;
				}
			}
			if(isAlpha(s[s.length() - 1]))
			{
				ans += s[s.length() - 1];
			}
			cout << ans << endl;
			return 0;
		}
	}
	return 0;
}
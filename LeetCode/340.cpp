#include <bits/stdc++.h>
using namespace std;

class Solution	{
public:
	int lengthOfLongestSubstringKDistinct(string s, int k)	{
		if(s == "" || s.length() == 0 || k == 0)	{
			return 0;
		}
		if(s.length() < k)	{
			return s.length();
		}
		if(k == 1)	{
			return 1;
		}
		map<char, int> mp;
		mp[s[0]] = 1;
		int l = 0;
		int ans = 1;
		for(int i = 1; i < s.length(); i++)	{
			mp[s[i]]++;
			if(mp.size() > k)	{
				while(mp.size() > k)	{
					mp[s[l]]--;
					if(mp[s[l]] == 0)	{
						mp.erase(s[l]);
					}
					l++;
				}
			}
			else	{
				ans = max(ans, i - l + 1);
			}
		}
		return ans;
	}
};

int main()	{
	Solution ob;
	string inp = "abcbbbbcccbdddadacb";
	cout << ob.lengthOfLongestSubstringKDistinct(inp, 2) << endl;
	return 0;
}
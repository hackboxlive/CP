#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string licenseKeyFormatting(string S, int K) {
		vector<char> v;
		for(int i = 0; i < S.length(); i++)	{
			if(S[i] != '-')	{
				v.push_back(S[i]);
			}
		}
		string s = "";
		int ctr = 0;
		for(int i = v.size() - 1; i >= 0; i--)	{
			ctr++;
			s += ((v[i] >= 'a' && v[i] <= 'z') ? v[i] - ' ' : v[i]);
			if(ctr == K && i != 0)	{
				s += "-";
				ctr = 0;
			}
		}
		reverse(s.begin(), s.end());
		return s;
	}
};

int main()	{
	string s = "2-5g-3-J";//"5F3Z-2e-9-w";
	int k = 2;
	Solution ob;
	cout << ob.licenseKeyFormatting(s, k) << endl;
	return 0;
}
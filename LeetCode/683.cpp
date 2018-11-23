#include <bits/stdc++.h>
using namespace std;

class Solution	{
public:
	int kEmptySlots(vector<int> flowers, int k)	{
		set<int> s;
		s.insert(flowers[0]);
		for(int i = 1; i < flowers.size(); i++)	{
			set<int>::iterator it = s.lower_bound(flowers[i]);
			if(it != s.end())	{
				if(it == s.begin())	{
					if(*it - flowers[i] -1 == k)	{
						return i;
					}
				}
				else	{
					int temp1 = *it;
					it--;
					int temp2 = *it;
					if(temp1 - flowers[i] - 1 == k || flowers[i] - temp2 - 1 == k)	{
						return i;
					}
				}
			}
			else	{
				it--;
				if(flowers[i] - *it - 1 == k)	{
					return i;
				}
			}
			s.insert(flowers[i]);
		}
		return -2;
	}
};

int main()	{
	Solution ob;
	vector<int> flowers;//[] = {1, 3, 2};
	flowers.push_back(1);
	flowers.push_back(2);
	flowers.push_back(3);
	int k = 1;
	cout << ob.kEmptySlots(flowers, k) + 1 << endl;
	return 0;
}
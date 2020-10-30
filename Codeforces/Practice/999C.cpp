#include <iostream>
#include <random>
#include <algorithm>

template<typename T>
void read(T& _val)
{
    std::cin >> _val;
}

template<typename T, typename... Args>
void read(T& _val, Args&... _args)
{
    std::cin >> _val;
    read(_args...);
}

template<typename T>
void print(const T& _val)
{
    std::cout << _val << std::endl;
}

template<typename T, typename... Args>
void print(const T& _val, const Args&... _args)
{
    std::cout << _val << " ";
    print(_args...);
}

template<typename T>
void permuteVector(std::vector<T>& v, int _seed = 10)
{
	shuffle(v.begin(), v.end(), std::default_random_engine(_seed));
}

/*
*   Main starts below
*/

#include <unordered_set>
#include <vector>
#include <sstream>

#include <cstring>
#include <stack>

int main()
{
	int n, k;
	read(n, k);
	std::string s;
	read(s);
	std::vector<int> freq[26];
	memset(freq, 0, sizeof(freq));
	for(int i = 0; i < n; ++i)
	{
		freq[s[i] - 'a'].push_back(i);
	}
	std::unordered_set<int> st;
	for(int i = 0; i < 26; ++i)
	{
		for(int j = 0; j < freq[i].size() && st.size() != k; ++j)
		{
			st.insert(freq[i][j]);
		}
	}
	std::string ans;
	for(int i = 0; i < n; ++i)
	{
		if(st.find(i) == st.end())
		{
			ans += s[i];
		}
	}
	print(ans);
}
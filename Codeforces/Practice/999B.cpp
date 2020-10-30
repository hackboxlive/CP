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
	int n;
	read(n);
	std::string s;
	read(s);
	std::vector<int> v;
	for(int i = 1; i <= n; ++i)
	{
		if(n % i == 0)
			v.push_back(i);
	}
	for(int i : v)
	{
		std::string t = s.substr(0, i);
		std::reverse(t.begin(), t.end());
		t += s.substr(i, n - i);
		//print(i, t, s.substr(0, i), s.substr(i, n - 1));
		s = t;
	}
	print(s);
}
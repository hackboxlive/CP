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

#include <unordered_map>
#include <vector>
#include <sstream>

int main()
{
	int n;
	read(n);
	std::unordered_map<long long, long long> st;
	std::string s;
	for(int i = 0; i < n; ++i)
	{
		read(s);
		//s = pp;
		int net1 = 0;
		int net2 = 0;
		for(int i = 0; i < s.length(); ++i)
		{
			if(s[i] == '(')
				net2++;
			else
				if(net2 > 0)
				{
					net2--;
				}
				else
				{
					net1--;
				}
		}
		//print(s, net1 + net2);
		if(net1 != 0 && net2 > 0)
		{
			continue;
		}
		//print(s, net1 + net2);
		st[net2 + net1]++;
	}
	unsigned long long ans = 0;
	for(auto it : st)
	{
		if(it.first > 0)
		{
			int rev = it.first * -1;
			ans += it.second * st[rev];
			//print(it.first, ans);
		}
	}
	//print(st[0]);
	ans += st[0] * st[0];
	print(ans);
}
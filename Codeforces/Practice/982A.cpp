#include <iostream>
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

long long lcm(long long a, long long b)
{
	return (a * b) / std::__gcd(a, b);
}

/*
*   Main starts below
*/

int main()
{
	int n;
	read(n);
	std::string s;
	read(s);
	s = "0" + s + "0";
	std::string ans = "Yes";
	for(int i = 1; i <= n; ++i)
	{
		if(s[i] == '1' && (s[i - 1] == '1' || s[i + 1] == '1'))
		{
			ans = "No";
		}
	}
	for(int i = 1; i <= n; ++i)
	{
		if(s[i] == '0' && (s[i - 1] == '0' && s[i + 1] == '0'))
		{
			ans = "No";
		}
	}
	print(ans);
}
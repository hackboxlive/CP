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
	long long n, k;
	read(n);
	read(k);
	long long maxx = 1;
	for(int i = 2; i <= k; ++i)
	{
		maxx = lcm(maxx, i);
		if(maxx > 1e18)
		{
			print("No");
			return 0;
		}
	}
	if((n + 1) % maxx == 0)
	{
		print("Yes");
	}
	else
	{
		print("No");
	}
}
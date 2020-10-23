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

#include <vector>

int main()
{
	int n;
	int x;
	read(n);
	std::vector<int> v;
	for(int i = 0; i < n; ++i)
	{
		read(x);
		v.push_back(x);
	}
	if(n == 1)
	{
		print(std::min(v[0] - 1, (int)1e6 - v[0]));
	}
	else
	{
		int ans = 1e9;
		for(int i = 1; i < n; ++i)
		{
			ans = std::min(ans, std::max(v[i - 1] - 1, (int)1e6 - v[i]));
			//print(ans);
		}
		ans = std::min(ans, v[n - 1] - 1);
		ans = std::min(ans, (int)1e6 - v[0]);
		print(ans);
	}
}
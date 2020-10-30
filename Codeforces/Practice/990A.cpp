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

int main()
{
	long long n, m, a, b;
	read(n, m, a, b);
	long long rem = n % m;
	long long rem2 = m - rem;
	long long a1 = rem2 * a;
	long long a2 = rem * b;
	if(a1 <= a2)
	{
		print(a1);
	}
	else
	{
		print(a2);
	}
}
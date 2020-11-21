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

//main begins here

int main()
{
	int t;
	read(t);
	while(t--)
	{
		int x, y;
		read(x, y);
		if(x > y)
		{
			std::swap(x, y);
		}
		if(x == y)
		{
			print(2 * x);
		}
		else
		{
			print(2 * x + 1 + (y - x - 1) * 2);
		}
	}
}
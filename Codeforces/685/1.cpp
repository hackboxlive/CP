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
		int n;
		read(n);
		if(n == 1)
		{
			print(0);
		}
		else if(n == 2)
		{
			print(1);
		}
		else if(n == 3)
		{
			print(2);
		}
		else if(n % 2 == 0)
		{
			print(2);
		}
		else
		{
			print(3);
		}
	}
}
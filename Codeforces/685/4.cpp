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

bool check(long long x, long long y, long long d)
{
	x = x * x;
	y = y * y;
	d = d * d;
	return x + y <= d;
}

int main()
{
	int t;
	read(t);
	while(t--)
	{
		long long d, k;
		read(d, k);
		int moves = 0;
		long long x = 0, y = 0;
		long long a, b;
		while(true)
		{
			if(x < y)
			{
				break;
			}
			if(check(x + k, y, d))
			{
				x = x + k;
				moves++;
			}
			else if(check(x, y + k, d))
			{
				y = y + k;
				moves++;
			}
			else
			{
				x -= k;
				y += k;
			}
			//print(x, y);
		}
		//print(moves);
		if(moves % 2 == 1)
		{
			print("Ashish");
		}
		else
		{
			print("Utkarsh");
		}
	}
}
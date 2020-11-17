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

long long arr[200200];
int main()
{
	int t;
	read(t);
	while(t--)
	{
		int n, k;
		read(n, k);
		for(int i = 0; i < n * k; ++i)
		{
			read(arr[i]);
		}
		long long sum = 0;
		int from_back = n - ((n + 1) / 2) + 1;
		//print("back: ", from_back);
		for(int i = 1; i <= k; ++i)
		{
			sum += arr[n * k - i * from_back];
		}
		print(sum);
	}
}
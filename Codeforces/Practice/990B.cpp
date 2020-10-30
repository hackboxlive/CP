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
	int n, k;
	read(n, k);
	int arr[200100];
	for(int i = 0; i < n; ++i)
	{
		read(arr[i]);
	}
	std::sort(arr, arr + n);
	int check = 1;
	int ans = 0;
	for(int i = 0; i < n - 1; ++i)
	{
		while(check < n && arr[i] == arr[check])
		{
			check++;
		}
		if(check != n)
		{
			if(arr[check] <= arr[i] + k)
			{
				ans++;
			}
		}
	}
	print(n - ans);
}
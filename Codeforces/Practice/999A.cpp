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

#include <cstring>
#include <stack>

int main()
{
	int n, k;
	read(n, k);
	int arr[101];
	for(int i = 0; i < n; ++i)
	{
		read(arr[i]);
	}
	int fr = 0, bk = n - 1;
	int ans = 0;
	while(1)
	{
		bool solved = false;
		if(fr <= bk && arr[fr] <= k)
		{
			ans++;
			fr++;
			solved = true;
		}
		if(bk >= fr && arr[bk] <= k)
		{
			ans++;
			bk--;
			solved = true;
		}
		if(!solved)
		{
			break;
		}
	}
	print(ans);
}
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
	long long arr[100100];
	int n, k, l;
	read(n, k, l);
	for(int i = 0; i < n * k; ++i)
	{
		read(arr[i]);
	}
	std::sort(arr, arr + n * k);
	int maxx = 0;
	for(int i = 1; i < n * k; ++i, maxx++)
	{
		if(arr[i] > arr[0] + l)
		{
			break;
		}
	}
	if(maxx == n * k)
	{
		maxx--;
	}
	//print(maxx);
	if(maxx + 1 < n)
	{
		print(0);
		return 0;
	}
	long long ans = 0;
	int made = 0;
	for(int i = 0; i < n * k && n - made < maxx + 1 - i; i += k, made++)
	{
		ans += arr[i];
	}
	for(int i = maxx; made < n; i--, made++)
	{
		ans += arr[i];
	}
	print(ans);
}
#include <iostream>

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

/*
*   Main starts below
*/

int main()
{
	int n;read(n);
	int s[3030];
	for(int i = 0; i < n; ++i)
	{
		read(s[i]);
	}
	long long c[3030];
	for(int i = 0; i < n; ++i)
	{
		read(c[i]);
	}
	long long ans = 1e9;
	for(int j = 1; j < n - 1; ++j)
	{
		long long int min1 = 1e9;
		for(int i = 0; i < j; ++i)
		{
			if(s[i] < s[j])
			{
				min1 = std::min(min1, c[i]);
			}
		}
		long long int min2 = 1e9;
		for(int i = j + 1; i < n; ++i)
		{
			if(s[i] > s[j])
			{
				min2 = std::min(min2, c[i]);
			}
		}
		if(min1 != 1e9 && min2 != 1e9)
		{
			ans = std::min(ans, min1 + min2 + c[j]);
		}
	}
	if(ans == 1e9)
	{
		print(-1);
	}
	else
	{
		print(ans);
	}
}
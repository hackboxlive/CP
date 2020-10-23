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
	int n;
	read(n);
	int ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = i; j <= n; ++j)
		{
			int x = j ^ i;
			if(x < j + i && x >= j && x <= n)
			{
				//print(i, j, x);
				ans += 1;
			}
		}
	}
	print(ans);
}
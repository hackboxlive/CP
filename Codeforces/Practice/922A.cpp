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
	int x, y;
	read(x, y);
	std::string ans = "No";
	if(y != 0)
	{
		if(y == 1)
		{
			if(x == 0)
			{
				ans = "Yes";
			}
		}
		else
		{
			if(x >= y - 1)
			{
				if((x - y + 1) % 2 == 0)
				{
					ans = "Yes";
				}
			}
		}
	}
	print(ans);
}
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
	int k;read(k);
	if(k > 36)
	{
		print(-1);
	}
	else
	{
		std::string ans = "";
		while(k)
		{
			if(k >= 2)
			{
				ans += "8";
				k -= 2;
			}
			else
			{
				ans += "4";
				k -= 1;
			}
		}
		print(ans);
	}
}
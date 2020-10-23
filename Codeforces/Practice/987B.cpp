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

#include <cmath>

int main()
{
	int x, y;
	read(x, y);
	long double xy = (long double)y * log(x);
	long double yx = (long double)x * log(y);
	//print(xy, yx);
	if(x == y || (x == 2 && y == 4) || (x == 4 && y == 2))
	{
		print("=");
	}
	else if(xy < yx)
	{
		print("<");
	}
	else
	{
		print(">");
	}
}
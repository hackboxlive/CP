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
	int k[3];
	read(k[0], k[1], k[2]);
	int two = 0;
	int three = 0;
	int four = 0;
	int one = 0;
	for(int i = 0; i < 3; ++i)
	{
		if(k[i] == 1)
		{
			one++;
		}
		if(k[i] == 2)
		{
			two++;
		}
		if(k[i] == 3)
		{
			three++;
		}
		if(k[i] == 4)
		{
			four++;
		}
	}
	std::string ans = "No";
	if(one >= 1 || two >= 2 || three == 3 || (two == 1 && four == 2))
	{
		ans = "Yes";
	}
	print(ans);
}
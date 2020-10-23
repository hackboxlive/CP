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

std::string solve(std::string s)
{
	for(int i = 1; i < s.length(); ++i)
	{
		switch(s[i])
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'y':
				{
					switch(s[i - 1])
					{
						case 'a':
						case 'e':
						case 'i':
						case 'o':
						case 'u':
						case 'y':
							return s.substr(0, i) + s.substr(i + 1);						
					}
				}
		}
	}
	return s;
}

int main()
{
	int n;
	read(n);
	std::string s;
	read(s);
	while(solve(s) != s)
	{
		s = solve(s);
	}
	print(s);
}
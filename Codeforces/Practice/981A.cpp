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
	std::string s;
	read(s);
	for(int i = 0; i < s.length(); ++i)
	{
		for(int j = 0; j <= i; ++j)
		{
			std::string ss = s.substr(j, s.length() - i);
			for(int k = 0; k < ss.length() / 2; ++k)
			{
				if(ss[k] != ss[ss.length() - 1 - k])
				{
					print(s.length() - i);
					return 0;
				}
			}
		}
	}
	print(0);
}
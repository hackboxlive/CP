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
	int ans = 0;
	for(int i = 0; i < s.length(); ++i)
	{
		switch(s[i])
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case '1':
			case '3':
			case '5':
			case '7':
			case '9':
				ans++;
		}
	}
	print(ans);
}
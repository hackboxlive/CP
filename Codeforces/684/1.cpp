#include <iostream>
#include <random>
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

template<typename T>
void permuteVector(std::vector<T>& v, int _seed = 10)
{
	shuffle(v.begin(), v.end(), std::default_random_engine(_seed));
}

/*
*   Main starts below
*/

int main()
{
	int t;
	read(t);
	while(t--)
	{
		int n, c0, c1, h;
		read(n, c0, c1, h);
		std::string s;
		read(s);
		bool flipped = false;
		if(c1 < c0)
		{
			int temp = c0;
			c0 = c1;
			c1 = temp;
			flipped = true;
		}
		if(c1 - c0 > h)
		{
			int ans = 0;
			for(int i = 0; i < s.length(); ++i)
			{
				if((s[i] == '0' && flipped) || (s[i] == '1' && !flipped))
				{
					ans += (c0 + h);
				}
				else
				{
					ans += c0;
				}
			}
			print(ans);
		}
		else
		{
			int ans = 0;
			for(int i = 0; i < s.length(); ++i)
			{
				if((s[i] == '0' && flipped) || (s[i] == '1' && !flipped))
				{
					ans += c1;
				}
				else
				{
					ans += c0;
				}
			}
			print(ans);
		}
	}
}
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

int main(int argc, char const *argv[])
{
	int t;
	read(t);
	while(t--)
	{
		int n, x;
		read(n, x);
		int a[55], b[55], c[55];
		for(int i = 0; i < n; ++i)
		{
			int p;
			read(p);
			a[i] = x - p;
		}
		for(int i = 0; i < n; ++i)
		{
			int p;
			read(p);
			b[i] = p;
			c[i] = 0;
		}
		std::string ans = "Yes";
		for(int i = 0; i < n; ++i)
		{
			int maxi = -1;
			for(int j = 0; j < n; ++j)
			{
				if(b[j] <= a[i] && c[j] == 0)
				{
					if(maxi == -1)
					{
						maxi = j;
					}
					else
					{
						if(b[maxi] < b[j])
						{
							maxi = j;
						}
					}
				}
			}
			if(maxi == -1)
			{
				ans = "No";
			}
			else
			{
				c[maxi] = 1;
			}
		}
		print(ans);
	}
	return 0;
}
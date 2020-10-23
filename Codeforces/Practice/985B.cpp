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
#include <unordered_map>

std::unordered_map<int, int> mp;
std::string mat[2020];

int main()
{
	int n, m;
	read(n, m);
	std::string s;
	for(int i = 0; i < n; ++i)
	{
		read(mat[i]);
		for(int j = 0; j < m; ++j)
		{
			if(mat[i][j] == '1')
			{
				mp[j]++;
			}
		}
	}
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(mat[i][j] == '1')
			{
				mp[j]--;
				if(mp[j] == 0)
				{
					mp.erase(j);
				}
			}
		}
		if(mp.size() == m)
		{
			print("YES");
			return 0;
		}
		for(int j = 0; j < m; ++j)
		{
			if(mat[i][j] == '1')
			{
				mp[j]++;
			}
		}
	}
	print("NO");
}
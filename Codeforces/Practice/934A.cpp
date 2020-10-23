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

#include <vector>
#include <climits>

std::vector<long long> a, b;

long long solve(int idx)
{
	long long ans = LLONG_MIN;
	for(int i = 0; i < a.size(); ++i)
	{
		if(i != idx)
		{
			for(int j = 0; j < b.size(); ++j)
			{
				ans = std::max(ans, a[i] * b[j]);
			}
		}
	}
	return ans;
}

int main()
{
	int n, m;read(n, m);
	long long x;
	for(int i = 0; i < n; ++i)
	{
		read(x);
		a.push_back(x);
	}
	for(int i = 0; i < m; ++i)
	{
		read(x);
		b.push_back(x);
	}
	long long ans = LLONG_MAX;
	for(int i = 0; i < n; ++i)
	{
		ans = std::min(ans, solve(i));
	}
	print(ans);
}
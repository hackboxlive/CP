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

#include <unordered_map>

struct elem
{
	elem()
	{
		a = 0;
		b = 0;
	}

	long long a;
	long long b;
};

int main()
{
	std::unordered_map<int, elem> mp;
	int n, m;
	int x, y;
	read(n);
	for(int i = 0; i < n; ++i)
	{
		read(x, y);
		mp[x].a = y;
	}
	read(m);
	for(int i = 0; i < m; ++i)
	{
		read(x, y);
		mp[x].b = y;
	}
	long long ans = 0;
	for(auto& it : mp)
	{
		ans += std::max(it.second.a, it.second.b);
	}
	print(ans);
}
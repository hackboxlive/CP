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
#include <cstring>
#include <cassert>

int main()
{
	std::vector<int> v[100100];
	int deg[100100];
	memset(deg, 0, sizeof(deg));
	int n;
	read(n);
	int x, y;
	for(int i = 1; i < n; ++i)
	{
		read(x, y);
		v[x].push_back(y);
		v[y].push_back(x);
		deg[x]++;
		deg[y]++;
	}
	x = 0;
	int vertex = -1;
	std::vector<int> gg;
	for(int i = 1; i <= n; ++i)
	{
		if(deg[i] > 2)
		{
			x++;
			vertex = i;
		}
		if(deg[i] == 1)
		{
			gg.push_back(i);
		}
	}
	if(x > 1)
	{
		print("No");
	}
	else
	{
		print("Yes");
		if(vertex == -1)
		{
			assert(gg.size() == 2);
			print(1);
			print(gg[0], gg[1]);
		}
		else
		{
			print(gg.size());
			for(auto cc : gg)
			{
				print(cc, vertex);
			}
		}
	}
}
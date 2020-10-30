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

#include <unordered_map>
#include <vector>
#include <sstream>

void transpose(std::vector<std::vector<int>>& mat)
{
	for(int i = 0; i < mat.size(); ++i)
	{
		for(int j = 0; j < mat[i].size(); ++j)
		{
			if(i != j)
			{
				mat[i][j] = mat[i][j] == 1 ? 0 : 1;
			}
		}
	}
}

int main()
{
	int n, a, b;
	read(n, a, b);
	std::vector<std::vector<int>> mat(n);
	if(a != 1 && b != 1)
	{
		print("NO");
	}
	else if(n == 2 && a == 1 && b == 1) {print("NO");
	}
	else if(n == 3 && a == 1 && b == 1) {print("NO");
	}
	else
	{
		int c = a != 1 ? a : b;
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				mat[i].push_back(0);
			}
		}
		for(int i = 0; i < n - c; ++i)
		{
			mat[i][i + 1] = 1;
			mat[i + 1][i] = 1;
		}
		if(a == 1)
		{
			transpose(mat);
		}
		print("YES");
		for(int i = 0; i < n; ++i)
		{
			std::stringstream ss;
			for(int j = 0; j < n; ++j)
			{
				ss << mat[i][j];
			}
			print(ss.str());
		}
	}
}
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

//main begins here

#include <sstream>

int arr[100100];

int query(std::string type, int i, int j)
{
	print(type, i + 1, j + 1);
	std::cout.flush();
	int x;
	read(x);
	return x;
}

void print_array(int n)
{
	std::stringstream ss;
	ss << "! ";
	for(int i = 0; i < n; ++i)
	{
		ss << arr[i] << " ";
	}
	print(ss.str());
}

int main()
{
	int n;
	read(n);
	std::vector<std::pair<int, int>> xors;
	std::vector<std::pair<int, int>> sorted_xors;
	xors.push_back(std::make_pair(0, 0));
	sorted_xors.push_back(std::make_pair(0, 0));
	for(int i = 1; i < n; ++i)
	{
		int x = query("XOR", 0, i);
		xors.push_back(std::make_pair(x, i));
		sorted_xors.push_back(std::make_pair(x, i));
	}
	std::sort(sorted_xors.begin(), sorted_xors.end());
	for(int i = 0; i < sorted_xors.size() - 1; ++i)
	{
		if(sorted_xors[i].first == sorted_xors[i + 1].first)
		{
			//j and k are same
			int j = sorted_xors[i].second;
			int k = sorted_xors[i + 1].second;
			int x = query("AND", j, k);
			arr[j] = x;
			arr[k] = x;
			arr[0] = xors[j].first ^ x;
			for(int p = 1; p < n; ++p)
			{
				arr[p] = xors[p].first ^ arr[0];
			}
			print_array(n);
			return 0;
		}
	}
	//permutation
	int j = sorted_xors[1].second;
	int k = sorted_xors[2].second;
	int x = query("AND", 0, j);
	int y = query("AND", 0, k);
	arr[0] = ((x >> 1) << 1) | (y & 1);
	for(int p = 1; p < n; ++p)
	{
		arr[p] = xors[p].first ^ arr[0];
	}
	print_array(n);
}
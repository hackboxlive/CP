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

#include <unordered_map>
#include <map>

int main()
{
	int t;
	read(t);
	std::map<int, int> mp;
	std::unordered_map<int, int> mp2;
	while(t--)
	{
		mp.clear();
		mp2.clear();
		int n;
		int x;
		read(n);
		for(int i = 0; i < n; ++i)
		{
			read(x);
			mp[x]++;
			mp2[x] = i + 1;
		}
		int ans = -1;
		for(auto it : mp)
		{
			if(it.second == 1)
			{
				ans = mp2[it.first];
				break;
			}
		}
		print(ans);
	}
}
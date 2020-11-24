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

int main()
{
	int t;
	read(t);
	std::unordered_map<int, std::vector<int>> mp;
	while(t--)
	{
		mp.clear();
		int n, x;
		read(n);
		for(int i = 0; i < n; ++i)
		{
			read(x);
			mp[x].push_back(i);
		}
		int ans = 1e9;
		for(auto it : mp)
		{
			int this_ans = 0;
			if(it.second[0] != 0)
			{
				this_ans++;
			}
			for(int j = 1; j < it.second.size(); ++j)
			{
				if(it.second[j] != it.second[j - 1] + 1)
				{
					this_ans++;
				}
			}
			if(it.second[it.second.size() - 1] != n - 1)
			{
				this_ans++;
			}
			ans = std::min(ans, this_ans);
		}
		print(ans);
	}
}
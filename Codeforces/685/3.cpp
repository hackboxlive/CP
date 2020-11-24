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

int main()
{
	int t;
	read(t);
	int n, k;
	std::string s1, s2;
	int f1[26], f2[26];
	while(t--)
	{
		for(int i = 0; i < 26; ++i)
		{
			f1[i] = 0;
			f2[i] = 0;
		}
		read(n, k);
		read(s1);
		read(s2);
		for(int i = 0; i < n; ++i)
		{
			f1[s1[i] - 'a']++;
			f2[s2[i] - 'a']++;
		}
		for(int i = 0; i < 26; ++i)
		{
			f1[i] -= f2[i];
		}
		std::string ans = "Yes";
		for(int i = 0; i < 25; ++i)
		{
			while(f1[i] > 0)
			{
				if(f1[i] < k)
				{
					ans = "No";
					break;
				}
				else
				{
					f1[i] -= k;
					f1[i + 1] += k;
				}
			}
		}
		if(f1[25] != 0)
		{
			ans = "No";
		}
		print(ans);
	}
}
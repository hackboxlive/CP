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
	while(t--)
	{
		int n, q;
		read(n, q);
		std::string s;
		std::string ans;
		read(s);
		int l, r;
		for(int i = 0; i < q; i++)
		{
			read(l, r);
			l--; r--;
			ans = "NO";
			for(int i = l - 1; i >= 0; i--)
			{
				if(s[i] == s[l])
				{
					ans = "YES";
				}
			}
			for(int i = r + 1; i < n; ++i)
			{
				if(s[i] == s[r])
				{
					ans = "YES";
				}
			}
			print(ans);
		}
	}
}
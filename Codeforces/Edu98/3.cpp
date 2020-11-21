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

//int dp[200200][2];
int main()
{
	int t;
	read(t);
	std::string s;
	while(t--)
	{
		read(s);
		int n = s.length();
		int ans = 0;
		int dp[2] = {0, 0};
		for(int i = 0; i < n; ++i)
		{
			if(s[i] == '(')
			{
				dp[0]++;
			}
			if(s[i] == ')')
			{
				if(dp[0] > 0)
				{
					dp[0]--;
					ans++;
				}
			}
			if(s[i] == '[')
			{
				dp[1]++;
			}
			if(s[i] == ']')
			{
				if(dp[1] > 0)
				{
					dp[1]--;
					ans++;
				}
			}
			//print(dp[0], dp[1], ans);
		}
		print(ans);
	}
}
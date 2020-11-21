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

long long arr[200200];

int main()
{
	int t;
	read(t);
	while(t--)
	{
		long long n;
		read(n);
		long long sum = 0;
		long long v;
		long long ans = 1e9;
		long long check;
		long long max = 0;
		for(int i = 0; i < n; ++i)
		{
			read(arr[i]);
			sum += arr[i];
			max = std::max(arr[i], max);
		}
		long long k;
		if(max % (n - 1) == 0)
		{
			k = max;
		}
		else
		{
			k = ((max / (n - 1)) + 1) * (n - 1);
		}
		//print("k", k);
		for(int i = 0; i < n; ++i)
		{
			v = (k - arr[i]) + (k - 1) * (n - 1) - (sum - arr[i]);
			if(arr[i] == 0)
			{
				check = (k - 1) * (n - 1) - (sum - arr[i]);
				v = std::min(v, check);
			}
			//print("here", v);
			ans = std::min(ans, v);
		}
		print(ans);
	}
}
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

#include <unordered_set>
#include <vector>
#include <sstream>

int main()
{
	std::unordered_set<int> st;
	int n, k;
	read(n, k);
	int arr[110];
	std::vector<int> ans;
	for(int i = 0; i < n; ++i)
	{
		read(arr[i]);
		if(st.find(arr[i]) == st.end())
		{
			st.insert(arr[i]);
			//print("Pushing", arr[i]);
			ans.push_back(i + 1);
			//print(ans.size());
		}
	}
	if(ans.size() >= k)
	{
		print("YES");
		std::stringstream ss;
		for(int i = 0; i < k; ++i)
		{
			ss << ans[i] << " ";
		}
		print(ss.str());
	}
	else
	{
		print("NO");
	}
}
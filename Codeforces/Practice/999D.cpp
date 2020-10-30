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

#include <cstring>
#include <stack>

int main()
{
	int maxx = 200200;
	int n, m;
	read(n, m);
	int k = n / m;
	int x;
	int arr[maxx];
	std::stack<int> pos[maxx];
	int mat[maxx];
	memset(arr, 0, sizeof(arr));
	for(int i = 0; i < n; ++i)
	{
		read(x);
		arr[x % m]++;
		pos[x % m].push(i);
		mat[i] = x;
	}
	std::unordered_set<int> free;
	long long ans = 0;
	for(int j = 1; j <= 2; ++j)
	{
		for(int i = 1; i <= m; ++i)
		{
			// print("j", j, "i", i);
			// for(int pp = 0; pp < m; ++pp)
			// {
			// 	print("PP:", pp, arr[pp]);
			// }
			// std::stringstream ss;
			// for(auto it : free)
			// {
			// 	ss << it << " ";
			// }
			// print("FREE:", ss.str());
			if(arr[i % m] < k)
			{
				while(pos[i % m].size() != k && free.size() > 0)
				{
					int first = *free.begin();
					//print("First", first);
					pos[i % m].push(first);
					arr[i % m]++;
					free.erase(first);
					if(mat[first] % m > i)
					{
						ans += (m - (mat[first] % m) + i);
						//print("Ans1:", ans);
					}
					else
					{
						ans += i - (mat[first] % m);
						//print("Ans2:", ans);
					}
				}
			}
			else if(arr[i % m] > k)
			{
				//ans += (arr[i % m] - k);
				//arr[(i + 1) % m] += arr[i % m] - k;
				while(pos[i % m].size() > k)
				{
					arr[i % m]--;
					free.insert(pos[i % m].top());
					pos[i % m].pop();
				}
			}
		}
	}
	print(ans);
	for(int i = 0; i < m; ++i)
	{
		while(!pos[i].empty())
		{
			int pois = pos[i].top();
			//print("changing pos: ", pois, i);
			mat[pois] += (i - (mat[pois] % m) + m) % m;
			//print("changed pos: ", mat[pois]);
			pos[i].pop();
		}
	}
	std::stringstream ss;
	for(int i = 0; i < n; ++i)
	{
		ss << mat[i] << " ";
	}
	print(ss.str());
}
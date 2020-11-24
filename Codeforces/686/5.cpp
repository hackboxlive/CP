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

#include <unordered_map>

typedef long long ll;

std::vector<int> g[200200];
int vis[200200];
int circle_elem;
std::unordered_map<int, int> cycle;

bool detect_cycle(int src, int parent)
{
	//print("here2", src, parent);
	vis[src] = 1;
	bool isCycle = false;
	for(int i = 0; i < g[src].size(); ++i)
	{
		if(g[src][i] != parent)
		{
			if(vis[g[src][i]] == 1)
			{
				cycle[src] = 1;
				circle_elem = g[src][i];
				//print("inserting", src, circle_elem);
				return true;
			}
			isCycle |= detect_cycle(g[src][i], src);
			if(isCycle)
			{
				cycle[src] = 1;
				//print("inserting1", src, circle_elem);
				if(src == circle_elem)
				{
					return false;
				}
				return isCycle;
			}
		}
	}
	//print("here3", src, parent, isCycle);
	return isCycle;
}

int cnt;
void dfs(int src, int par)
{
	for(int i = 0; i < g[src].size(); ++i)
	{
		if(g[src][i] != par && cycle.find(g[src][i]) == cycle.end())
		{
			cnt++;
			dfs(g[src][i], src);
		}
	}
}

int main()
{
	int t;
	read(t);
	while(t--)
	{
		int n, x, y;
		read(n);
		for(int i = 1; i <= n; ++i)
		{
			g[i].clear();
			vis[i] = 0;
		}
		for(int i = 0; i < n; ++i)
		{
			read(x, y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		cycle.clear();
		detect_cycle(1, 1);
		//print("here");
		std::vector<int> vv;
		for(auto it : cycle)
		{
			cnt = 1;
			dfs(it.first, it.first);
			vv.push_back(cnt);
		}
		//print("here");
		long long ans = n;
		ans *= (n - 1);
		
		for(auto i : vv)
		{
			//print(i);
			long long cc = i;
			cc *= (i - 1);
			cc /= 2;
			ans -= cc;
		}
		print(ans);
	}
}
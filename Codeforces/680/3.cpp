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

#include<bits/stdc++.h>

std::vector<unsigned long long> primes;
void sieve()
{
	int lt = 1e5;
	std::vector<int> sv(lt, 0);
	for(int i = 2; i < lt; ++i)
	{
		for(int j = 2; j * i < lt; ++j)
		{
			sv[j * i] = 1;
		}
	}
	for(int i = 2; i < lt; ++i)
	{
		if(sv[i] == 0)
		{
			primes.push_back(i);
		}
	}
}

std::vector<unsigned long long> factors;

typedef unsigned long long ull;

void generateAllFactors(std::vector<std::pair<ull, ull>>& _pf, int idx, ull num)
{
	if(idx == _pf.size())
	{
		//print("inserting num:", num);
		factors.push_back(num);
		return;
	}
	ull pp = 1;
	for(int i = 0; i <= _pf[idx].second; ++i)
	{
		if(i != 0)
		{
			pp *= _pf[idx].first;
		}
		// print("Calling:", idx + 1, pp, num);
		generateAllFactors(_pf, idx + 1, num * pp);
	}
}

void getFactors(ull num1, ull num2)
{
	std::vector<std::pair<ull, ull>> primeFactors1;
	for(auto prime : primes)
	{
		int cnt = 0;
		while(num1 % prime == 0)
		{
			cnt++;
			num1 /= prime;
		}
		if(cnt > 0)
		{
			primeFactors1.push_back(std::make_pair(prime, cnt));
		}
	}
	primeFactors1.push_back(std::make_pair(num1, 1));
	std::vector<std::pair<ull, ull>> primeFactors2;
	for(auto prime : primes)
	{
		int cnt = 0;
		while(num2 % prime == 0)
		{
			cnt++;
			num2 /= prime;
		}
		if(cnt > 0)
		{
			primeFactors2.push_back(std::make_pair(prime, cnt));
		}
	}
	primeFactors2.push_back(std::make_pair(num2, 1));
	std::vector<std::pair<ull, ull>> pf;
	for(auto& it : primeFactors1)
	{
		int cnt = it.second;
		for(auto& jt : primeFactors2)
		{
			if(it.first == jt.first)
			{
				cnt += jt.second;
				jt.second = 0;
			}
		}
		pf.push_back(std::make_pair(it.first, cnt));
	}
	for(auto& it : primeFactors2)
	{
		if(it.second != 0)
		{
			pf.push_back(std::make_pair(it.first, it.second));
		}
	}
	// for(auto i : primeFactors1)
	// {
	// 	print("PF1", i.first, i.second);
	// }
	// for(auto i : primeFactors2)
	// {
	// 	print("PF1", i.first, i.second);
	// }
	// for(auto i : pf)
	// {
	// 	print("PF:", i.first, i.second);
	// }
	generateAllFactors(pf, 0, 1);
	std::sort(factors.begin(), factors.end());
	// for(auto i : factors)
	// {
	// 	print(i);
	// }
}

int main(int argc, char const *argv[])
{
	sieve();
	int t;
	read(t);
	while(t--)
	{
		factors.clear();
		unsigned long long p, q;
		read(p, q);
		if(p % q != 0)
		{
			print(p);
		}
		else
		{
			factors.clear();
			getFactors(p / q, q);
			for(int i = factors.size() - 1; i >= 0; --i)
			{
				if(factors[i] % q != 0)
				{
					print(factors[i]);
					break;
				}
			}
		}
	}
	return 0;
}
#include <iostream>
#include <sstream>
#include <vector>

int sie[100100];

void sieve(std::vector<long long>& primes)
{
	for(int i = 2; i < 100100; ++i)
	{
		if(sie[i] == 0)
		{
			primes.push_back(i);
			for(int j = 2; j * i < 100100; ++j)
			{
				sie[j * i] = 1;
			}
		}
	}
}

int main()
{
	std::vector<long long> primes;
	sieve(primes);
	int t;
	//read(t);
	std::cin >> t;
	std::vector<std::pair<long long, long long>> factors;
	while(t--)
	{
		factors.clear();
		long long n, n1;
		//read(n);
		std::cin >> n;
		n1 = n;
		for(auto& i : primes)
		{
			int cnt = 0;
			while(n % i == 0)
			{
				cnt++;
				n /= i;
			}
			if(cnt > 0)
			{
				factors.push_back(std::make_pair(i, cnt));
			}
		}
		if(n > 0)
		{
			factors.push_back(std::make_pair(n, 1));
		}
		//std::cout << "here " << factors.size() << std::endl;
		int maxCnt = 0, maxFct;
		for(auto& it : factors)
		{
			if(it.second > maxCnt)
			{
				maxCnt = it.second;
				maxFct = it.first;
			}
		}
		std::vector<long long> fcts;
		long long takenOut = 1;
		for(int i = 0; i < maxCnt - 1; ++i)
		{
			fcts.push_back(maxFct);
			takenOut *= maxFct;
		}
		fcts.push_back(n1 / takenOut);
		std::cout << fcts.size() << std::endl;
		for(int i = 0; i < fcts.size(); ++i)
		{
			std::cout << fcts[i] << " ";
		}
		std::cout << std::endl;
	}
}
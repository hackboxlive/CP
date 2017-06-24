#include <bits/stdc++.h>
using namespace std;
int arr[100010000];
long long int x[1000];
long long int d[1000];
void sieve()	{
	arr[1]=1;
	for(int i=2;i<10001000;i++)	{
		if(arr[i]==0)	{
			for(int j=1;j*i<10001000;j++)	{
				if(arr[j*i]==0)	{
					arr[j*i]=i;
				}
			}
		}
	}
	return;
}
long long int fast_exp(long long int base, int exp,long long int mod)
{
	if(exp==1)
		return base;
	else
	{
		if(exp%2 == 0)
		{
			long long int base1 = pow(fast_exp(base, exp/2,mod),2);
			if(base1 >= mod)
				return base1%mod;
			else
				return base1;
		}
		else
		{
			long long int ans = (base*  pow(fast_exp(base,(exp-1)/2,mod),2));
			if(ans >= mod)
				return ans%mod;
			else
				return ans;
		}
	}
}
bool witness(long long int n, long long int s, long long int d, long long int a)
{
    long long int x = fast_exp(a, d, n);
    long long int y;
    while (s) {
        y = (x * x) % n;
        if (y == 1 && x != 1 && x != n-1)
            return false;
        x = y;
        --s;
    }
    if (y != 1)
        return false;
    return true;
}
bool is_prime_mr(long long int n)
{
    if (((!(n & 1)) && n != 2 ) || (n < 2) || (n % 3 == 0 && n != 3))
        return false;
    if (n <= 3)
        return true;
 
    long long int d = n / 2;
    long long int s = 1;
    while (!(d & 1)) {
        d /= 2;
        ++s;
    }
 
    if (n < 1373653)
        return witness(n, s, d, 2) && witness(n, s, d, 3);
    if (n < 9080191)
        return witness(n, s, d, 31) && witness(n, s, d, 73);
    if (n < 4759123141)
        return witness(n, s, d, 2) && witness(n, s, d, 7) && witness(n, s, d, 61);
    if (n < 1122004669633)
        return witness(n, s, d, 2) && witness(n, s, d, 13) && witness(n, s, d, 23) && witness(n, s, d, 1662803);
    if (n < 2152302898747)
        return witness(n, s, d, 2) && witness(n, s, d, 3) && witness(n, s, d, 5) && witness(n, s, d, 7) && witness(n, s, d, 11);
    if (n < 3474749660383)
        return witness(n, s, d, 2) && witness(n, s, d, 3) && witness(n, s, d, 5) && witness(n, s, d, 7) && witness(n, s, d, 11) && witness(n, s, d, 13);
    return witness(n, s, d, 2) && witness(n, s, d, 3) && witness(n, s, d, 5) && witness(n, s, d, 7) && witness(n, s, d, 11) && witness(n, s, d, 13) && witness(n, s, d, 17);
}
long long int PollardRho(long long int n)
{
    if (n==1) return n;
    if (n % 2 == 0) return 2;
    long long int x = (rand()%(n-2))+2;
    long long int y = x;
    long long int c = (rand()%(n-1))+1;
    long long int d = 1;  
    while (d==1)
    {
        x = (fast_exp(x, 2, n) + c + n)%n;
        y = (fast_exp(y, 2, n) + c + n)%n;
        y = (fast_exp(y, 2, n) + c + n)%n;
		d = __gcd(abs(x-y), n);
		if (d==n) return PollardRho(n);
	}
	return d;
}
int main()	{
	memset(arr,0,sizeof(arr));
	int t;
	int ctr;
	int even,odd;
	sieve();
	long long int n;
	vector<int> factors,power;
    srand (time(NULL));
	scanf("%d",&t);
	while(t--)	{
		scanf("%lld",&n);
		if(n==1)	{
			printf("Ordinary Number\n");
			continue;
		}
		if(is_prime_mr(n))	{
			printf("Ordinary Number\n");
			continue;
		}
		while(n>1)	{
			long long int divi=0;
			while(divi==0 && n>10000000)	{
				divi=PollardRho(n);
			}
			if(n<10000000)	{
				divi=n;
			}
			if(divi>10001000)	{
				divi=n/divi;
			}
			long long int f=divi;
			while(f>1)	{
				factors.push_back(arr[f]);
				f=f/arr[f];
			}
			n=n/divi;
		}
		sort(factors.begin(),factors.end());
		power.push_back(1);
		ctr=0;
		for(int i=1;i<factors.size();i++)	{
			if(factors[i]==factors[i-1])	{
				power[ctr]++;
			}
			else	{
				power.push_back(1);
				ctr++;
			}
		}
		even=0;
		odd=0;
		for(int i=0;i<power.size();i++)	{
			if(power[i]%2==0)	{
				even++;
			}
			else	{
				odd++;
			}
		}
		if(even>odd)	{
			printf("Psycho Number\n");
		}
		else	{
			printf("Ordinary Number\n");
		}
		power.clear();
		factors.clear();
	}
	return 0;
}
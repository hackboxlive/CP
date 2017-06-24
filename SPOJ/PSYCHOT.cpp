#include <bits/stdc++.h>
using namespace std;
int arr[100010000];
long long int x[1000];
long long int d[1000];
vector<int> primes;
int prime_ctr;
void sieve()	{
	arr[1]=1;
	for(int i=2;i<10001000;i++)	{
		if(arr[i]==0)	{
			primes.push_back(i);
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
	//cout<<mod<<endl;
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
long long int gcd(long long int a,long long int b) {
    return b == 0 ? a : gcd(b, a % b);
}
long long int find_factor(long long int n)	{
//		cout<<n<<endl;
//	int aa=rand()%100+2;
//	int aa=582;
//	cout<<aa<<endl;
	int aa=primes[prime_ctr];
	int ctr=0;
	long long int a,b,temp;
	x[0]=aa;
	d[0]=1;
	while((d[ctr]<=1 || d[ctr]>=n) && ctr<30)	{
//		cout<<x[ctr]<<" "<<d[ctr]<<" "<<ctr<<endl;
		ctr++;
		x[ctr]=fast_exp(x[ctr-1],ctr,n);
		a=x[ctr];
		b=n;
		if(a<b)	{
			temp=a;
			a=b;
			b=temp;
		}
		d[ctr]=gcd(a,b-1);
		if(d[ctr]>1 && d[ctr]<n)	{
			return d[ctr];
		}
	}
	return 0;
}
int main()	{
	memset(arr,0,sizeof(arr));
	int t;
	int ctr;
	int even,odd;
	sieve();
	long long int n;
	vector<int> factors,power;
//		srand (time(NULL));
//	cout<<gcd(123456789,338724);
	scanf("%d",&t);
	while(t--)	{
		scanf("%lld",&n);
		if(n==1)	{
			printf("Ordinary Number\n");
			continue;
		}
		prime_ctr=0;
//		cout<<"Here";
		while(n>1)	{
			long long int divi=0;
			while(divi==0 && n>10000000)	{
				divi=find_factor(n);
				prime_ctr++;
//				cout<<divi<<endl;
			}
			if(n<10000000)	{
				divi=n;
			}
//			cout<<divi<<endl;
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
//		for(int i=0;i<factors.size();i++)	{
//			cout<<factors[i]<<endl;
//		}
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
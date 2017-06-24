#include <bits/stdc++.h>
using namespace std;
int arr[10001000];
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
int main()	{
	memset(arr,0,sizeof(arr));
	sieve();
	int t,n;
	vector<int> factors;
	vector<int> power;
	int ctr;
	int even;
	int odd;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d",&n);
		if(n==1)	{
			printf("Ordinary Number\n");
			continue;
		}
		while(n>1)	{
			factors.push_back(arr[n]);
			n=n/arr[n];
		}
		power.push_back(1);
		ctr=0;
//		printf("%d\n",factors[0]);
		for(int i=1;i<factors.size();i++)	{
//			printf("%d\n",factors[i]);
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
}
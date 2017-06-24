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
int trailzero(int n)	{
	int cnt=0;
	for(int i=5;n/i>=1;i*=5)	{
		cnt+=n/i;
	}
	return cnt;
}
int main()	{
	memset(arr,0,sizeof(arr));
	sieve();
	int t;
	int k,b;
	long long int p;
	vector<int> factors;
	vector<int> power;
	int ctr;
	int even;
	int odd;
	int zero;
	int n;
	int ld;
	int mat[][4]={{0,0,0,0},{1,1,1,1},{2,4,8,6},{3,9,7,1},{4,6,4,6},{5,5,5,5},{6,6,6,6},{7,9,3,1},{8,4,2,6},{9,1,9,1}};
	scanf("%d",&t);
	while(t--)	{
		scanf("%d%d%lld",&k,&b,&p);
		zero=trailzero(k);
		b=b%10;
		if(p==0)	{
			ld=1;
		}
		else	{
			p=(p-1)%4;
			ld=mat[b][p];
//			printf("%d %d\n",zero,ld);
		}
		n=zero*ld;
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
}
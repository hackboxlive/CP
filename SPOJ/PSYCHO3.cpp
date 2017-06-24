#include <bits/stdc++.h>
using namespace std;
int arr[10001000];
int inp[110];
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
vector<int> numbers;
//int table[100100];
/*int checkif(int val)	{
	memset(table,0,sizeof(table));
	table[0]=1;
	for(int i=0;i<numbers.size();i++)	{
		for(int j=numbers[i];j<=val;j++)	{
			table[j]+=table[j-numbers[i]];
			if(table[val]>0)	{
				return 1;
			}
		}
	}
	return table[val];
}*/
int main()	{
	memset(arr,0,sizeof(arr));
	sieve();
	int t,n,m;
	int mm;
	vector<int> factors;
	vector<int> power;
	int ctr;
	int even;
	int odd;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d%d",&m,&mm);
		for(int i=0;i<m;i++)	{
			scanf("%d",&inp[i]);
		}
		for(int j=0;j<m;j++)	{
			n=inp[j];
			if(n==1 || n==0)	{
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
				numbers.push_back(inp[j]);
			}
			power.clear();
			factors.clear();
		}
		int ssum=0;
		for(int i=0;i<numbers.size();i++)	{
			ssum=ssum+numbers[i];
		}
//		int val=checkif(mm);
		int ans[ssum+10];
		for(int i=0;i<ssum+10;i++)	{
			ans[i]=0;
		}
		ans[0]=1;
		for(int i=0;i<numbers.size();i++)	{
			for(int j=ssum;j>=numbers[i];j--)	{
				ans[j]|=ans[j-numbers[i]];
			}
		}
		if(mm>ssum)	{
			printf("No\n");
		}
		else if(ans[mm])	{
			printf("Yes\n");
		}
		else	{
			printf("No\n");
		}
		numbers.clear();
	}
	return 0;
}
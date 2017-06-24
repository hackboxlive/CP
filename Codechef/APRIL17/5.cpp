#include <bits/stdc++.h>
using namespace std;
int primes[1001000];
vector<vector<int> > factors(100100);
vector<vector<int> > numfact(100100);
void sieve()	{
	for(int i=2;i<1001000;i++)	{
		if(primes[i]==0)	{
			for(int j=2*i;j<1001000;j+=i)	{
				primes[j]=1;
			}
		}
	}
	return;
}
int main()	{
	sieve();
	long long a,b;
	long long num;
	scanf("%lld %lld",&a,&b);
	for(int i=2;i<1001000;i++)	{
		if(primes[i]==0)	{
			if(a%i==0)	{
				num=a;
			}
			else	{
				num=(a/i + 1)*i;
			}
			while(num<=b)	{
//				cout<<num<<" "<<i<<endl;
//				getchar();
				factors[num-a].push_back(i);
				num+=i;
			}
		}
	}
//	for(int i=a;i<=b;i++)	{
//		for(int j=0;j<factors[i-a].size();j++)	{
//			cout<<factors[i-a][j]<<" ";
//		}
//		cout<<endl;
//	}
	int tot=0;
	long long val;
	for(long long i=a;i<=b;i++)	{
		num=i-a;
		val=i;
		for(int j=0;j<factors[num].size();j++)	{
			int ctr=0;
			while(val%factors[num][j]==0)	{
				val=val/factors[num][j];
				ctr++;
			}
			numfact[num].push_back(ctr);
		}
		if(val!=1)	{
			factors[num].push_back(val);
			numfact[num].push_back(1);
		}
	}
//	for(int i=a;i<=b;i++)	{
//		cout<<"for i="<<i<<endl;
//		for(int j=0;j<factors[i-a].size();j++)	{
//			cout<<factors[i-a][j]<<" "<<numfact[i-a][j]<<endl;
//		}
//	}
	int ctr=0;
	int prev;
	int id;
	int totthis;
	int maxx;
	for(int i=0;i<=b-a;i++)	{
//		cout<<"i="<<i+a<<endl;
		prev=1;
		id=0;
		for(int j=0;j<numfact[i].size();j++)	{
			id+=numfact[i][j];
		}
		while(id>0)	{
//			cout<<id<<" "<<numfact[i].size()<<endl;
			maxx=0;
			prev=1;
			for(int j=0;j<numfact[i].size();j++)	{
				prev*=(numfact[i][j]+1);
				if(numfact[i][j]>numfact[i][maxx])	{
					maxx=j;
				}
			}
//			cout<<"ans of "<<i+a<<"= "<<prev<<endl;
			tot+=prev;
			numfact[i][maxx]--;
			id--;
		}
		cout<<"ans of "<<i+a<<"is "<<tot<<endl;
	}
	printf("%d\n",tot);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
bool prime[1001000];
void sieve()	{
	prime[0]=prime[1]=true;
	for(int i=2;i<1001000;i++)	{
		if(!prime[i])	{
			for(int j=i+i;j<1001000;j+=i)	{
				prime[j]=true;
			}
		}
	}
}
int main()	{
	sieve();
	int a,b,k;
	cin>>a>>b>>k;
	int hi=b-a+1;
	int lo=1,mid;
	int ansmid=1e9;
	while(lo<=hi)	{
		mid=(lo+hi)/2;
		int gotk=0,mink;
		for(int i=a;i<=a+mid-1;i++)	{
			if(!prime[i])	{
				gotk++;
			}
		}
		mink=gotk;
		for(int i=a+1;i<=b-mid+1;i++)	{
			if(!prime[i+mid-1])	{
				gotk++;
			}
			if(!(prime[i-1]))	{
				gotk--;
			}
			if(gotk<mink)	{
				mink=gotk;
			}
		}
		if(mink>=k)	{
			hi=mid-1;
			ansmid=min(ansmid,mid);
		}
		else	{
			lo=mid+1;
		}
	}
	if(ansmid!=1e9)	{
		cout<<ansmid<<endl;
	}
	else	{
		cout<<"-1\n";
	}
	return 0;
}
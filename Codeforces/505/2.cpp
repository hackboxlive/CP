#include <bits/stdc++.h>
using namespace std;

long long a[200200], b[200200];

vector<int> get_factors(long long a)	{
	vector<int> facts;
	long long temp=a;
	for(int i=2;i<=sqrt(a);i++)	{
		if(temp%i==0)	{
			facts.push_back(i);
			while(temp%i==0)	{
				temp/=i;
			}
		}
	}
	if(temp>1)	{
		facts.push_back(temp);
	}
	return facts;
}
int main()	{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>a[i]>>b[i];
	}
	vector<int> f1 = get_factors(a[0]);
	vector<int> f2 = get_factors(b[0]);
	for(int i=0;i<f1.size();i++)	{
		int ctr=0;
		for(int j=0;j<n;j++)	{
			if(a[j]%f1[i]==0 || b[j]%f1[i]==0)	{
				ctr++;
			}
		}
		if(ctr==n)	{
			cout<<f1[i]<<endl;
			return 0;
		}
	}
	for(int i=0;i<f2.size();i++)	{
		int ctr=0;
		for(int j=0;j<n;j++)	{
			if(a[j]%f2[i]==0 || b[j]%f2[i]==0)	{
				ctr++;
			}
		}
		if(ctr==n)	{
			cout<<f2[i]<<endl;
			return 0;
		}
	}
	cout<<"-1\n";
	return 0;
}
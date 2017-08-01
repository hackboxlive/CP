#include <bits/stdc++.h>
using namespace std;
int prime[100100];
vector<long long> pr;
void precompute()	{
	for(int i=2;i<=100000;i++)	{
		if(prime[i]==0)	{
			for(int j=2*i;j<=100000;j+=i)	{
				prime[j]=1;
			}
		}
	}
	long long v;
	for(int i=2;i<=100000;i++)	{
		if(prime[i]==0)	{
			v=(long long)i*i;
			pr.push_back(v);
		}
	}
}
int main()	{
	precompute();
	int t;
	cin>>t;
	long long n,k;
	while(t--)	{
		cin>>n>>k;
		int pos=lower_bound(pr.begin(),pr.end(),n)-pr.begin();
		int kpos=upper_bound(pr.begin(),pr.end(),k)-pr.begin();
		if(kpos>pos)	{
			cout<<pos<<" 0\n";
		}
		else	{
			cout<<pos<<" "<<pos-kpos<<endl;
		}
	}
	return 0;
}

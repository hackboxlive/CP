#include <bits/stdc++.h>
using namespace std;
int main()	{
	long long n;
	cin>>n;
	long long tot=n*(n+1);
	tot/=2;
	vector<int> v;
	if(tot%2==1)	{
		cout<<"1\n";
		long long half=tot/2;
		half++;
		int c=n;
		while(half>0)	{
			if(half>c)	{
				v.push_back(c);
				half-=c;
				c--;
			}
			else	{
				v.push_back(half);
				half=0;
			}
		}
	}
	else	{
		cout<<"0\n";
		long long half=tot/2;
		int c=n;
		while(half>0)	{
			if(half>c)	{
				v.push_back(c);
				half-=c;
				c--;
			}
			else	{
				v.push_back(half);
				half=0;
			}
		}		
	}
	cout<<(int)v.size()<<" ";
	for(int i=0;i<v.size();i++)	{
		cout<<v[i]<<" ";
	}
	return 0;
}
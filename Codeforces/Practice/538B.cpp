#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n;
	cin>>n;
	vector<int> vals;
	while(n)	{
		int nn=n;
		int m=0;
		int p=1;
		while(nn)	{
			if(nn%10)	{
				m=m+p;
			}
			nn=nn/10;
			p=p*10;
		}
		vals.push_back(m);
		n=n-m;
	}
	cout<<vals.size()<<endl;
	for(int i=0;i<vals.size();i++)	{
		cout<<vals[i]<<" ";
	}
}
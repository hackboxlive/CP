#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t=5;
	cout<<t<<endl;
	int n=100000;
	int q=100000;
	cout<<n<<" "<<q<<endl;
	srand(time(NULL));
	int val;
	for(int i=0;i<n;i++)	{
		val=rand()%100000;
		cout<<val<<" ";
	}
	cout<<endl;
	int l,r,k;
	for(int i=0;i<q;i++)	{
		l=rand()%100000;
		r=rand()%100000;
		if(l>r)	{
			swap(l,r);
		}
		k=1;
		cout<<l<<" "<<r<<" "<<k<<endl;
	}
	return 0;
}
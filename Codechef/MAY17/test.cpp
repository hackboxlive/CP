#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n=500;
	long long h,c;
	cout<<"1\n500"<<endl;
	srand(time(NULL));
	for(int i=0;i<n;i++)	{
		h=rand()%10000;
		c=rand()%100000;
		cout<<h<<" "<<c<<endl;
	}
	int u,v;
	for(int i=0;i<n-1;i++)	{
		cin>>u>>v;
		cout<<u<<" "<<v<<endl;
	}
}
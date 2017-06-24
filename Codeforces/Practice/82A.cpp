#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n;
	cin>>n;
	int minus=5;
	int nump=1;
	int queue=1;
	while(n - minus > 0)	{
		n = n - minus;
		minus = minus * 2;
		nump = nump * 2;
	}
	while(n - nump > 0)	{
		n = n - nump;
		queue++;
	}
	if(queue == 1)	{
		cout<<"Sheldon";
	}
	else if(queue ==2)	{
		cout<<"Leonard";
	}
	else if(queue ==3)	{
		cout<<"Penny";
	}
	else if(queue ==4)	{
		cout<<"Rajesh";
	}
	else {
		cout<<"Howard";
	}
	return 0;
}
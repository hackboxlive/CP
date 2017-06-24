#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n;
	cin>>n;
	if(n%2==0)	{
		int num=n/2;
		cout<<num<<endl;
		for(int i=0;i<n/2;i++)	{
			cout<<"2 ";
		}
	}
	else	{
		int num=(n-3)/2;
		cout<<num+1<<endl;
		for(int i=0;i<(n-3)/2;i++)	{
			cout<<"2 ";
		}
		cout<<"3";
	}
	return 0;
}
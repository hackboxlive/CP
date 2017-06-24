#include <bits/stdc++.h>
using namespace std;
int arr[100100];
void sieve()	{
	for(int i=2;i<=100100;i++)	{
		if(arr[i]==0)	{
			for(int j=2*i;j<=100100;j+=i)	{
				arr[j]=1;
			}
		}
	}
	return;
}
int main()	{
	int n;
	cin>>n;
	sieve();
	if(n<=2)	{
		cout<<"1\n";
	}
	else	{
		cout<<"2\n";
	}
	for(int i=2;i<=n+1;i++)	{
		if(arr[i])	{
			cout<<"2 ";
		}
		else	{
			cout<<"1 ";
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int main()	{
	int n;
	cin>>n;
	int v;
	for(int i=0;i<n;i++)	{
		cin>>v;
		arr[v]++;
	}
	for(int i=1;i<=100000;i++)	{
		if(arr[i]%2==1)	{
			cout<<"Conan\n";
			return 0;
		}
	}
	cout<<"Agasa"<<endl;
	return 0;
}
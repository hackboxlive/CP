#include <bits/stdc++.h>
using namespace std;
int c[1010];
int t[1010];
int main()	{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>c[i];
	}
	for(int i=0;i<n;i++)	{
		cin>>t[i];
	}
	int one=-1,two=-1,three=-1;
	for(int i=0;i<n;i++)	{
		if(t[i]==1 && (one==-1 || c[i]<one))	{
			one=c[i];
		}
		if(t[i]==2 && (two==-1 || c[i]<two))	{
			two=c[i];
		}
		if(t[i]==3 && (three==-1 || c[i]<three))	{
			three=c[i];
		}
	}
	if(one==-1 || two==-1)	{
		cout<<three<<endl;
	}
	else if(three==-1)	{
		cout<<one+two<<endl;
	}
	else	{
		cout<<min(one+two,three)<<endl;
	}
	return 0;
}
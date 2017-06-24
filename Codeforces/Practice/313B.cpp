#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int main()	{
	string s;
	cin>>s;
	arr[s.length()-1]=0;
	for(int i=s.length()-2;i>=0;i--)	{
		if(s[i]==s[i+1])	{
			arr[i]=1;
		}
		else	{
			arr[i]=0;
		}
	}
	for(int i=1;i<s.length();i++)	{
		arr[i]=arr[i-1]+arr[i];
	}
	int t;
	cin>>t;
	int l,r;
	while(t--)	{
		cin>>l>>r;
		l--;
		r--;
		cout<<arr[r-1]-arr[l-1]<<endl;
	}
	return 0;
}
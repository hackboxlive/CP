#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n;
	cin>>n;
	string s;
	cin>>s;
	if(n%2==0)	{
		string t="";
		for(int i=0;i<n;i+=2)	{
			t=s[i]+t;
			t=t+s[i+1];
		}
		cout<<t;
		return 0;
	}
	else	{
		string t="";
		t=t+s[0];
		for(int i=1;i<n;i+=2)	{
			t=s[i]+t;
			t=t+s[i+1];
		}
		cout<<t;
		return 0;
	}
}
#include <bits/stdc++.h>
using namespace std;
int arr[100100]
int main()	{
	string s;
	cin>>s;
	int numop=0;
	for(int i=0;i<s.length();i++)	{
		if(s[i]==')')	{
			numop++;
		}
	}
	return 0;
}
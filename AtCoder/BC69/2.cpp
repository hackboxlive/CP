#include <bits/stdc++.h>
using namespace std;
int main()	{
	string s;
	cin>>s;
	int len=s.length();
	len-=2;
	cout<<s[0]<<len<<s[len+1]<<endl;
	return 0;
}
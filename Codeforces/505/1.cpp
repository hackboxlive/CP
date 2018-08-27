#include <bits/stdc++.h>
using namespace std;
int ch[26];
int main()	{
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int i=0;i<n;i++)	{
		ch[s[i]-'a']++;
	}
	bool flag=false;
	for(int i=0;i<26;i++)	{
		if(ch[i]>=2 || n==1)	{
			flag=true;
		}
	}
	if(flag==false)	{
		cout<<"NO\n";
	}
	else	{
		cout<<"YES\n";
	}
	return 0;
}
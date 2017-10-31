#include <bits/stdc++.h>
using namespace std;
int main()	{
	string s;
	cin>>s;
	int ans=0,ctr=0;
	while(s.length()>1)	{
//		cout<<s<<endl;
		ans=0;
		for(int i=0;i<s.length();i++)	{
			ans+=(s[i]-'0');
		}
		ctr++;
		s=to_string(ans);
	}
	cout<<ctr<<endl;
	return 0;
}
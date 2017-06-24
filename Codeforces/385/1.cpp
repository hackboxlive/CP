#include <bits/stdc++.h>
using namespace std;
int main()	{
	set<string> st;
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)	{
		string t=s[s.length()-1]+(string)s.substr(0,s.length()-1);
//		cout<<t<<endl;;
		st.insert(t);
		s=t;
	}
	cout<<st.size();
	return 0;
}
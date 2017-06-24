#include <bits/stdc++.h>
using namespace std;
int main()	{
	string s;
	cin>>s;
	char prev='a';
	char nex;
	int ssum=0;
	for(int i=0;i<s.length();i++)	{
		nex=s[i];
		int check=abs(s[i]-prev);
		if(check>13)	{
			ssum+=26-check;
		}
		else	{
			ssum+=check;
		}
		prev=nex;
	}
	cout<<ssum;
	return 0;
}
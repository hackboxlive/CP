#include <bits/stdc++.h>
using namespace std;
int main()	{
	string s;
	cin>>s;
	s="A"+s+"A";
	int prev=0;
	int maxd=INT_MIN;
	int len=s.length();
	for(int i=1;i<len;i++)	{
		if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='Y')	{
			if(i-prev > maxd)	{
				maxd=i-prev;
			}
			prev=i;
		}
	}
	cout<<maxd<<endl;
	return 0;
}
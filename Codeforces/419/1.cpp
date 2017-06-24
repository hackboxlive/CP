#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	cin>>t;
	string s;
	while(t--)	{
		cin>>s;
		int u=0,d=0;
		if(s[0]=='U')	{
			u=1;
		}
		else	{
			d=1;
		}
		for(int i=1;i<s.length();i++)	{
			if(s[i]!=s[i-1])	{
				if(s[i]=='U')	{
					u++;
				}
				else	{
					d++;
				}
			}
		}
		cout<<min(u,d)<<endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()	{
	string s;
	string n;
	cin>>s;
	if(s.length()==1)	{
		if(s[0]>='A' && s[0]<='Z')	{
			n=n+(char)(s[0]+32);
		}
		else	{
			n=n+(char)(s[0]-32);
		}
		cout<<n;
	}
	else	{
		int flag=0;
		for(int i=1;i<s.length();i++)	{
			if(s[i]>='a' && s[i]<='z')	{
				flag=1;
			}
		}
		if(flag==0)	{
			if(s[0]>='A' && s[0]<='Z')	{
				cout<<(char)(s[0]+32);
			}
			else	{
				cout<<(char)(s[0]-32);
			}
			for(int i=1;i<s.length();i++)	{
				cout<<(char)(s[i]+32);
			}
		}
		else	{
			cout<<s;
		}
	}
	return 0;
}
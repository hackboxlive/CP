#include <bits/stdc++.h>
using namespace std;
bool palindrome(string s)	{
	for(int i=0;i<s.length()/2;i++)	{
		if(s[i]!=s[s.length()-1-i])	{
			return false;
		}
	}
	return true;
}
int main()	{
	string s;
	cin>>s;
	int flag=0;
	if(s.length()==1)	{
		printf("YES\n");
		return 0;
	}
	for(int i=0;i<s.length()/2;i++)	{
		string newstr;
		newstr=s;
		if(s[i]!=s[s.length()-1-i])	{
			flag=1;
			char ch=newstr[i];
			newstr[i]=newstr[s.length()-1-i];
//			cout<<newstr<<endl;
			if(palindrome(newstr))	{
				printf("YES\n");
				return 0;
			}
			newstr[i]=ch;
			newstr[s.length()-1-i]=newstr[i];
//			cout<<newstr<<endl;
			if(palindrome(newstr))	{
				printf("YES\n");
				return 0;
			}
		}
		else	{
			continue;
		}
	}
	if(s.length()%2==0 || (s.length()%2==1 && flag==1))	{
		printf("NO\n");		
	}
	else	{
		printf("YES\n");
	}
	return 0;
}
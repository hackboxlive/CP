#include <bits/stdc++.h>
using namespace std;
string s;
int find_next(int pos)	{
	for(int i=pos;i<s.length();i++)	{
		if(s[i]>='a' && s[i]<='z')	{
			return i;
		}
	}
	return (int)s.length();
}
int main()	{
	getline(cin,s);
	int wc;
	int f[26];
	int pos;
	while(true)	{
		for(int i=0;i<s.length();i++)	{
			if(s[i]>='A' && s[i]<='Z')	{
				s[i]+=32;
			}
		}
		cout<<s<<endl;
		wc=0;
		memset(f,0,sizeof(f));
		pos=0;
		while(pos!=s.length())	{
//			cout<<"true";
			pos=find_next(pos);
			if(pos==(int)s.length())	{
				break;
			}
			wc++;
			cout<<"pos="<<pos<<endl;
			while(s[pos]>='a' && s[pos]<='z')	{
	//			cout<<pos<<" "<<s[pos]<<endl;
				f[s[pos]-'a']++;
				pos++;
				if(pos==(int)s.length())	{
					break;
				}
			}
			if(pos==(int)s.length())	{
				break;
			}
		}
		cout<<wc;
		for(int i=0;i<26;i++)	{
			cout<<" "<<f[i];
		}
		cout<<endl;
		getline(cin,s);
		if(s.compare("-1")==0)	{
			break;
		}
	}
	return 0;
}
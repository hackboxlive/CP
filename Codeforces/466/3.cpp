#include <bits/stdc++.h>
using namespace std;
char ch[26];
int main()	{
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)	{
		ch[s[i]-'a']=1;
	}
	char last;
	for(int i=25;i>=0;i--)	{
		if(ch[i])	{
			last=i;
			break;
		}
	}
	char first;
	for(int i=0;i<26;i++)	{
		if(ch[i])	{
			first=i;
			break;
		}
	}
	if(k<=n)	{
		s=s.substr(0,k);
		for(int i=s.length()-1;i>=0;i--)	{
			if(s[i]-'a'!=last)	{
				for(int j=s[i]-'a'+1;j<26;j++)	{
					if(ch[j])	{
						s[i]=(char)(j+'a');
						break;
					}
				}
				break;
			}
			else	{
				s[i]=(char)(first+'a');
			}
		}
	}
	else	{
		for(int i=n;i<k;i++)	{
			s+=(char)(first+'a');
		}
	}
	cout<<s<<endl;
	return 0;
}
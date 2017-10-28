#include <bits/stdc++.h>
using namespace std;
string s;
int len;
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		cin>>s;
		len=s.length();
		int summ=0;
		for(int i=0;i<len;i++)	{
			summ+=(s[i]-'0');
		}
		int even=s[len-1]-'0';
		int aa=-1;
		int apos=-1;
		if(len>1)	{
			int last=s[len-1]-'0';
			int sl=s[len-2]-'0';
			if(sl%2==0 && (summ-last)%3==0)	{
				apos=len-1;
			}
		}
		int fff=-1,dig;
		if(even%2==0)	{
			for(int i=0;i<s.length()-1;i++)	{
				dig=s[i]-'0';
				if((summ-dig)%3==0)	{
					fff=i;
					if(s[i+1]>s[i])	{
						aa=i;
						break;
					}
				}
			}
		}
		if(aa!=-1)	{
			for(int i=0;i<len;i++)	{
				if(i==aa)	{
					continue;
				}
				cout<<s[i];
			}
			cout<<endl;
		}
		else	{
			if(apos!=-1)	{
				for(int i=0;i<len-1;i++)	{
					cout<<s[i];
				}
				cout<<endl;
			}
			else if(fff!=-1)	{
				for(int i=0;i<len;i++)	{
					if(i==fff)	{
						continue;
					}
					cout<<s[i];
				}
				cout<<endl;
			}
			else	{
				cout<<"-1\n";
			}
		}
	}
	return 0;
}
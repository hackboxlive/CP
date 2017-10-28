#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		int a,b;
		cin>>a>>b;
		string s1,s2;
		s1=to_string(a);
		s2=to_string(b);
		string ans="";
		if(s1.length()<s2.length())	{
			for(int i=s1.length();i<s2.length();i++)	{
				s1="0"+s1;
			}
		}
		else	{
			for(int i=s2.length();i<s1.length();i++)	{
				s2="0"+s2;
			}
		}
//		cout<<s1<<" "<<s2<<endl;
		for(int i=0;i<s1.length();i++)	{
			int p=s1[i]-'0';
			int q=s2[i]-'0';
			p=p+q;
			p%=10;
			ans+=(char)(p+'0');
		}
		int g=-1;
		for(int i=0;i<ans.length();i++)	{
			if(ans[i]!='0')	{
				g=i;
				break;
			}
		}
		if(g==0)	{
			cout<<ans<<endl;
		}
		else	{
			if(g==-1)	{
				cout<<"0\n";
			}
			else	{
				for(int i=g;i<ans.length();i++)	{
					cout<<ans[i];
				}
				cout<<endl;
			}
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
vector<string> inwords;
vector<string> outwords;
int main()	{
	int n;
	scanf("%d",&n);
	string s;
	int flag=0;
	cin>>s;
	s="_"+s+"_";
	string word="";
	for(int i=0;i<n+2;i++)	{
//		cout<<i<<endl;
		if(s[i]!='(' && s[i]!=')' && s[i]!='_')	{
//			cout<<"character "<<i<<endl;
			word=word+s[i];
		}
		else if(s[i]=='(')	{
			outwords.push_back(word);
			word="";
			flag=1;
		}
		else if(s[i]==')')	{
			inwords.push_back(word);
			word="";
			flag=0;
		}
		else	{
			if(flag==0)	{
				outwords.push_back(word);
				word="";
			}
			else	{
				inwords.push_back(word);
				word="";
			}
		}
	}
	int numin=0;
	for(int i=0;i<inwords.size();i++)	{
		if(inwords[i].compare("")==0)	{
			continue;
		}
		numin++;
	}
	int maxlen=0;
	for(int i=0;i<outwords.size();i++)	{
		if(outwords[i].compare("")==0)	{
			continue;
		}
		if(outwords[i].length()>maxlen)	{
			maxlen=outwords[i].length();
		}
	}
	cout<<maxlen<<" "<<numin<<endl;
	return 0;
}
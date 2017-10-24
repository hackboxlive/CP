#include <bits/stdc++.h>
using namespace std;
bool valid(string s)	{
	for(int i=0;i<s.length();i++)	{
		if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]=='_') || (s[i]>='0' && s[i]<='9'))	{
			continue;
		}
//		cout<<s<<" "<<i<<endl;
		return false;
	}
	return true;
}
int main()	{
	string s;
	cin>>s;
	int rate=0,pos;
	int slash=0,p;
	for(int i=0;i<s.length();i++)	{
		if(s[i]=='@')	{
			rate++;
			pos=i;
		}
		if(s[i]=='/')	{
			slash++;
			p=i;
		}
	}
	if(rate!=1)	{
		cout<<"NO\n";
		return 0;
	}
	string username="",hostname="",resource="";
	username=s.substr(0,pos);
	if(!valid(username) || !(username.length()<=16 && username.length()>=1))	{
		cout<<"NO\n";
		return 0;
	}
	if(slash==0)	{
		for(int i=pos+1;i<s.length();i++)	{
			hostname+=s[i];
		}
	}
	else if(slash==1)	{
//		cout<<"here\n";
		for(int i=pos+1;i<p;i++)	{
			hostname+=s[i];
		}
		for(int i=p+1;i<s.length();i++)	{
			resource+=s[i];
//			cout<<"YES\n";
		}
	}
	else	{
		cout<<"NO\n";
		return 0;
	}
//	cout<<username<<endl;
//	cout<<hostname<<endl;
//	cout<<resource<<endl;
	vector<string> brhn;
	vector<int> dot;
	for(int i=0;i<hostname.length();i++)	{
		if(hostname[i]=='.')	{
			dot.push_back(i);
		}
	}
	if(dot.size()==0)	{
		brhn.push_back(hostname);
	}
	else	{
		brhn.push_back(hostname.substr(0,dot[0]));
		for(int i=0;i<dot.size()-1;i++)	{
			brhn.push_back(hostname.substr(dot[i]+1,dot[i+1]-dot[i]-1));
		}
		brhn.push_back(hostname.substr(dot[dot.size()-1]+1));
	}
	for(int i=0;i<brhn.size();i++)	{
//		cout<<brhn[i]<<endl;
		if(!valid(brhn[i]) || !(brhn[i].length()<=32 && brhn[i].length()>=1))	{
			cout<<"NO\n";
			return 0;
		}
	}
	if(resource.compare("")!=0)	{
		if(!valid(resource) || !(resource.length()<=16 && resource.length()>=1))	{
			cout<<"NO\n";
			return 0;
		}
	}
	if(resource.compare("")==0 && slash>0)	{
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	return 0;
}
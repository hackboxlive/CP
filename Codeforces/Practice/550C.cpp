#include <bits/stdc++.h>
using namespace std;
vector<string> eights;
string s;
void form_array()	{
	eights.push_back("0");
	eights.push_back("8");
	int v=16;
	string str;
	while(v<100)	{
		str=to_string(v);
		eights.push_back(str);
		v=v+8;
	}
	while(v<=1000)	{
		str=to_string(v);
		eights.push_back(str);
		v=v+8;
	}
	return;
}
int find_in_string(char ch,int start)	{
	for(int i=start;i<s.length();i++)	{
		if(s[i]==ch)	{
			return i;
		}
	}
	return s.length();
}
int main()	{
	form_array();
	cin>>s;
	int n=s.length();
	int pos,pos3,pos2;
	int flag=eights.size();
	for(int i=0;i<eights.size();i++)	{
		pos=find_in_string(eights[i][0],0);
		if(pos!=n)	{
			if(i<2)	{
				flag=i;
				break;
			}
			pos2=find_in_string(eights[i][1],pos+1);
			if(pos2!=n)	{
				if(i<13)	{
					flag=i;
					break;
				}
				pos3=find_in_string(eights[i][2],pos2+1);
				if(pos3!=n)	{
					flag=i;
				}
			}
		}
	}
	if(flag==eights.size())	{
		cout<<"NO";
	}
	else	{
		cout<<"YES\n";
		cout<<eights[flag];
	}
	return 0;
}
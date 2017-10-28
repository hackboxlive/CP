#include <bits/stdc++.h>
using namespace std;
vector<string> sen;
int main()	{
	int n;
	cin>>n;
	string s;
	getline(cin,s);
	getline(cin,s);
//	cout<<s;
	int cnt=0;
	int lo=0;
	for(int i=0;i<s.length();i++)	{
		if(s[i]=='.' || s[i]=='?' || s[i]=='!')	{
			cnt++;
			sen.push_back(s.substr(lo,i-lo+1));
			lo=i+2;
		}
	}
	bool flag=true;
	for(int i=0;i<cnt;i++)	{
		if(sen[i].length()>n)	{
			flag=false;
			break;
		}
//		cout<<sen[i]<<endl;
	}
	if(!flag)	{
		cout<<"Impossible\n";
		return 0;
	}
	int ans=1;
	int cur=sen[0].length();
	for(int i=1;i<cnt;i++)	{
		if(cur+sen[i].length()+1<=n)	{
			cur+=sen[i].length()+1;
		}
		else	{
			ans++;
			cur=sen[i].length();
		}
	}
	cout<<ans<<endl;
	return 0;
}
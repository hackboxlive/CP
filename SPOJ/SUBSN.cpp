#include <bits/stdc++.h>
using namespace std;
string s;
string sub;
vector<vector<int> > v(26);
void precompute()	{
	for(int i=0;i<26;i++)	{
		v[i].clear();
	}
	for(int i=0;i<s.length();i++)	{
		v[s[i]-'a'].push_back(i);
	}
	for(int i=0;i<26;i++)	{
		v[i].push_back(s.length());
	}
	return;
}
void compute()	{
	int lastindex=-1;
	int flag=0;
	vector<int>::iterator it;
	for(int i=0;i<sub.length();i++)	{
		it=lower_bound(v[sub[i]-'a'].begin(),v[sub[i]-'a'].end(),lastindex+1);
//		cout<<*it<<endl;
		if(*it==s.length())	{
			flag=1;
			break;
		}
		lastindex=*it;
	}
	if(flag==0)	{
		cout<<"YES\n";
	}
	else	{
		cout<<"NO\n";
	}
	return;
}
int main()	{
	int t,tt=1;
//	scanf("%d",&t);
	cin>>t;
	getline(cin,sub);
	while(t--)	{
		getline(cin,s);
		cout<<"Case "<<tt++<<":\n";
		precompute();
		int n;
//		scanf("%d\n",&n);
		cin>>n;
		getline(cin,sub);
//		cout<<"n="<<n<<endl;
		for(int p=1;p<=n;p++)	{
			getline(cin,sub);
//			cout<<sub;
//			cout<<endl;
			if(sub.length()==0)	{
				cout<<"YES\n";
				continue;
			}
			compute();
		}
	}
	return 0;
}
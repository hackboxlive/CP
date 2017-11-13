#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	cin>>t;
	string s;
	while(t--)	{
		cin>>s;
		vector<pair<int,char> > ab;
		int a_ans=0,b_ans=0;
		for(int i=0;i<s.length();i++)	{
			if(s[i]=='A')	{
				a_ans++;
				ab.push_back(make_pair(i,'A'));
			}
			if(s[i]=='B')	{
				b_ans++;
				ab.push_back(make_pair(i,'B'));
			}
		}
		for(int i=1;i<ab.size();i++)	{
			if(ab[i].second==ab[i-1].second)	{
				if(ab[i].second=='A')	{
					a_ans+=(ab[i].first-ab[i-1].first-1);
				}
				else	{
					b_ans+=(ab[i].first-ab[i-1].first-1);
				}
			}
		}
		cout<<a_ans<<" "<<b_ans<<endl;
	}
	return 0;
}
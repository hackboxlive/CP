#include <bits/stdc++.h>
using namespace std;
int main()	{
	map<pair<int,int> , string> m;
	map<pair<int,int> , string>::iterator it;
	int n,t;
	int a,b;
	string s[100100];
	scanf("%d",&n);
	for(int i=0;i<n;i++)	{
		scanf("%d%d",&a,&b);
		cin>>s[i];
		it=m.find(make_pair(a,b));
		if(it!=m.end())	{
			m.erase(it);
		}
		m.insert(make_pair(make_pair(a,b),s[i]));
	}
	scanf("%d",&t);
	while(t--)	{
		scanf("%d%d",&a,&b);
//		pp.first=a;
//		pp.second=b;
		it=m.find(make_pair(a,b));
		cout<<it->second<<endl;
	}
	return 0;
}
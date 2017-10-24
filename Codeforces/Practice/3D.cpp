#include <bits/stdc++.h>
using namespace std;
struct comp	{
	bool operator()(const pair<int,int> &p1,const pair<int,int> &p2)	{
		return p1.first>p2.first;
	}
};
int main()	{
	string s;
	cin>>s;
	int len=s.length();
	int open=0;
	int a,b;
	long long ans=0;
	priority_queue<pair<int,int>, vector<pair<int,int> >, comp > pq;
	for(int i=0;i<len;i++)	{
		if(s[i]=='(')	{
			open++;
		}
		else if(s[i]==')')	{
			open--;
		}
		else	{
			cin>>a>>b;
			s[i]=')';
			ans+=b;
			pq.push(make_pair(a-b,i));
			open--;
		}
		if(open<0)	{
			// cout<<"here at "<<i<<endl;
			if(pq.empty())	{
				cout<<"-1\n";
				return 0;
			}
			ans+=pq.top().first;
			s[pq.top().second]='(';
			pq.pop();
			open++;
			open++;
		}
		// cout<<i<<" "<<open<<" "<<ans<<endl;
	}
	if(open!=0)	{
		cout<<"-1\n";
		return 0;
	}
	cout<<ans<<endl;
	cout<<s<<endl;
	return 0;
}
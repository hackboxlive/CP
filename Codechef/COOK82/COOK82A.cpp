#include <bits/stdc++.h>
using namespace std;
struct node	{
	string team;
	int goals;
}arr[4];
bool comp(const node &p1,const node &p2)	{
	return p1.team.compare(p2.team);
}
int main()	{
	int t;
	cin>>t;
	int m,r,b,e;
	string s;
	int temp;
	while(t--)	{
		for(int i=0;i<4;i++)	{
			cin>>s>>temp;
			if(s[0]=='B')	{
				b=temp;
			}
			if(s[0]=='R')	{
				r=temp;
			}
			if(s[0]=='M')	{
				m=temp;
			}
			if(s[0]=='E')	{
				e=temp;
			}
		}
		if(b>e && m>r)	{
			cout<<"Barcelona\n";
		}
		else	{
			cout<<"RealMadrid\n";
		}
	}
	return 0;
}
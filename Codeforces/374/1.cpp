#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n;
	scanf("%d",&n);
	string s;
	cin>>s;
	int ctr=0;
	vector<int> g;
	for(int i=0;i<n;i++)	{
		if(s[i]=='B')	{
			ctr++;
		}
		else	{
			g.push_back(ctr);
			ctr=0;
		}
	}
	g.push_back(ctr);
	ctr=0;
	for(int i=0;i<g.size();i++)	{
		if(g[i]!=0)	{
			ctr++;
		}
	}
	printf("%d\n",ctr);
	if(ctr==0)	{
		return 0;
	}
	for(int i=0;i<g.size();i++)	{
		if(g[i]!=0)	{
			printf("%d ",g[i]);
		}
	}
	printf("\n");
}
#include <bits/stdc++.h>
using namespace std;
vector<int> maxpos,minpos;
set<in> freqset[10];
int main()	{
	int t;
	string s;
	scanf("%d",&t);
	while(t--)	{
		maxpos.clear();
		minpos.clear();
		cin>>s;
		for(int i=0;i<s.length();i++)	{
			freqset[s[i]-'0'].insert(i);
		}
		char charmax=s[0];
		int intmax;
		int len=s.length();
		for(int i=1;i<len;i++)	{
			if(s[i]>charmax)	{
				charmax=s[i];
			}
		}
		intmax=charmax-'0';
		int cnt=0;
		set<int>::iterator it;
		while((int)freqset[intmax].size()!=len)	{
			for(int i=1;i<10;i++)	{
				for(int it=freqset[i].begin();it!=freqset[i].end();it++)	{
					for(int j=0;j<i;j++)	{
						int diff=i-j;
						
					}
				}
			}
		}


		for(int i=0;i<len;i++)	{
			if(s[i]==charmax)	{
				maxpos.push_back(i);
			}
			if(s[i]==charmin)	{
				minpos.push_back(i);
			}
		}
		int anstime=-1e9;
		int tt1,tt2;
		if(charmax=='0')	{
			printf("0\n");
			continue;
		}
		for(int i=0;i<maxpos.size();i++)	{
			int pos=maxpos[i];
			tt1=pos/(charmax-'0');
			tt2=(len-pos)/(charmax-'0');
		}
	}
	return 0;
}
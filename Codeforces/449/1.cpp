#include <bits/stdc++.h>
using namespace std;

int main()	{
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int l,r;
	string c1,c2;
	while(m--)	{
		cin>>l>>r;
		cin>>c1>>c2;
		for(int i=l-1;i<r;i++)	{
			if(s[i]==c1[0])	{
				s[i]=c2[0];
			}
		}
	}
	cout<<s<<endl;

	return 0;
}
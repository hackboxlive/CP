#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n;
	scanf("%d",&n);
	string s;
	cin>>s;
	string ogo[100];
	int ctr=0;
	ogo[ctr]="ogo";
	while(ogo[ctr].length()<110)	{
		ctr++;
		ogo[ctr]=ogo[ctr-1]+"go";
	}
	vector<pair<int,int> > w;
	for(int i=ctr;i>=0;i--)	{
		size_t pos=s.find(ogo[i]);
		if(pos != std::string::npos)	{
			w.push_back(make_pair(i,pos));
			string t="";
			t=s.substr(0,pos);
			t=t+"***"+s.substr(pos+ogo[i].length());
			s=t;
			i++;
		}
	}
	cout<<s;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()	{
	int h1,a1,c1,h2,a2;
	cin>>h1>>a1>>c1;
	cin>>h2>>a2;
	bool flag=true;
	int ctr=0;
	vector<string> v;
	while(flag)	{
		if(a1>=h2)	{
			ctr++;
			v.push_back("STRIKE");
//			cout<<"STRIKE\n";
			flag=false;
			break;
		}
		else	{
			if(h1<=a2)	{
				ctr++;
				v.push_back("HEAL");
//				cout<<"HEAL\n";
				h1+=c1;
			}
			else	{
				ctr++;
				v.push_back("STRIKE");
//				cout<<"STRIKE\n";
				h2-=a1;
			}
		}
		h1-=a2;
	}
	cout<<ctr<<endl;
	for(int i=0;i<ctr;i++)	{
		cout<<v[i]<<endl;
	}
	return 0;
}
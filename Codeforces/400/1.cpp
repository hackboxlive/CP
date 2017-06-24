#include <bits/stdc++.h>
using namespace std;
int main()	{
	string a,b,c,d;
	cin>>a;
	cin>>b;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cout<<a<<" "<<b<<endl;
		cin>>c>>d;
		if(c.compare(a)==0)	{
			a=d;
		}
		else	{
			b=d;
		}
	}
	cout<<a<<" "<<b<<endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool signe(int x)	{
	if(x >= 0)	{
		return true;
	}
	return false;
}
int main()	{
	int n,a1,b1,a2,b2,c1,c2;
	cin>>n;
	cin>>a1>>a2;
	cin>>b1>>b2;
	cin>>c1>>c2;
	b1=b1-a1;
	b2=b2-a2;
	c1=c1-a1;
	c2=c2-a2;
	if(signe(b1) == signe(c1) && signe(b2) == signe(c2))	{
		cout << "YES\n";
		return 0;
	}
	cout << "NO\n";
	return 0;
}
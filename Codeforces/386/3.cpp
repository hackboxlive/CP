#include <bits/stdc++.h>
using namespace std;
int main()	{
	int s,x1,x2;
	cin>>s>>x1>>x2;
	int t1,t2;
	cin>>t1>>t2;
	int p,d;
	cin>>p>>d;
	if(t1>=t2)	{
		int diff=(abs(x1-x2))*t2;
		cout<<diff;
		return 0;
	}
	int mantime=(abs(x1-x2))*t2;
	int tramtime;
	if((d==1 && p<x2) || (d==-1 && p>x2))	{
		tramtime=(x2-p)*t1*d;
	}
	else	{
		if(d==1)	{
			tramtime=(s-p)*t1;
			tramtime+=(s-x2)*t1;
		}
		else	{
			tramtime=p*t1;
			tramtime+=x2*t1;
		}
	}
	if(mantime<=tramtime)	{
		cout<<mantime;
		return 0;
	}
	int rtrip=2*s*t1;
	if((x1>x2 && d==-1) || (x1<x2 && d==1))	{
		if(rtrip+tramtime>=mantime)	{
			cout<<mantime;
		}
		else	{
			cout<<rtrip+tramtime;
		}
		return 0;
	}
	cout<<tramtime;
	return 0;
}
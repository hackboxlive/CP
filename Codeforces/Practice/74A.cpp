#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n;
	cin>>n;
	string winner;
	int p;
	int points=0;
	cin>>winner;
	cin>>p;
	points+=p*100;
	cin>>p;
	points-=p*50;
	cin>>p;
	points+=p;
	cin>>p;
	points+=p;
	cin>>p;
	points+=p;
	cin>>p;
	points+=p;
	cin>>p;
	points+=p;
	string name;
//	cout<<points<<endl;
	int pp=points;
	for(int i=1;i<n;i++)	{
		points=0;
		cin>>name;
		cin>>p;
		points+=p*100;
		cin>>p;
		points-=p*50;
		cin>>p;
		points+=p;
		cin>>p;
		points+=p;
		cin>>p;
		points+=p;
		cin>>p;
		points+=p;
		cin>>p;
		points+=p;
//		cout<<points<<endl;
		if(pp<points)	{
			winner=name;
			pp=points;
		}
	}
	cout<<winner<<endl;
	return 0;
}
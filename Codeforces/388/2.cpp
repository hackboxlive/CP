#include <bits/stdc++.h>
using namespace std;
int main()	{
	int x[3];
	int y[3];
	cin>>x[0]>>y[0];
	cin>>x[1]>>y[1];
	cin>>x[2]>>y[2];
	cout<<"3\n";
	int xx[3],yy[3];
	cout<<x[0]+x[1]-x[2]<<" "<<y[0]+y[1]-y[2]<<endl;
	cout<<x[0]+x[2]-x[1]<<" "<<y[0]+y[2]-y[1]<<endl;
	cout<<x[2]+x[1]-x[0]<<" "<<y[2]+y[1]-y[0]<<endl;
	return 0;
}
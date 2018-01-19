#include <bits/stdc++.h>
using namespace std;
bool check(int h,int m)	{
	if(h/10==7 || h%10==7 || m/10==7 || m%10==7)	{
		return true;
	}
	return false;
}
int main()	{
	int x;
	cin>>x;
	int h,m;
	cin>>h>>m;
	int y=0;
	while(check(h,m)==false)	{
		y++;
		m=m-x;
		if(m<0)	{
			m+=60;
			h--;
		}
		if(h<0)	{
			h+=24;
		}
	}
	cout<<y<<endl;
	return 0;
}
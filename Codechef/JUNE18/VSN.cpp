#include <bits/stdc++.h>
using namespace std;
struct point	{
	double x;
	double y;
	double z;
}p,q,s,d;
int main()	{
	int t;
	double r;
	cin>>t;
	while(t--)	{
		cin>>p.x>>p.y>>p.z;
		cin>>q.x>>q.y>>q.z;
		cin>>d.x>>d.y>>d.z;
		cin>>s.x>>s.y>>s.z;
		cin>>r;
		point temp;
		double lo=0,hi=(double)1e9,mid;
		while(hi-lo<0.000001)	{
			mid=lo+(hi-lo)/2;
			temp.x=q.x+
		}
	}
	return 0;
}
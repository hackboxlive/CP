#include <bits/stdc++.h>
using namespace std;
int main()	{
	double x1,y1,x2,y2,x3,y3;
	cin>>x1>>y1;
	cin>>x2>>y2;
	cin>>x3>>y3;
	double a=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	double b=(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);
	double c=(x3-x1)*(x3-x1)+(y3-y1)*(y3-y1);
	a=sqrt(a);
	b=sqrt(b);
	c=sqrt(c);
	double area=x1*(y2-y3)+y1*(x3-x2)+x2*y3-y2*x3;
	area/=2;
	double radius=a*b*c;
	radius=radius/4;
	radius=radius/area;
	
	return 0;
}
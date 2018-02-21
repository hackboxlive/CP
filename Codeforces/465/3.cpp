#include <bits/stdc++.h>
using namespace std;
struct point	{
	double x;
	double y;
};
double get_dist(point p1,point p2)	{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
int main()	{
	double r;
	point p0,p1,p2,p3;
	cin>>r>>p0.x>>p0.y>>p3.x>>p3.y;
	if((p3.x-p0.x)*(p3.x-p0.x)+(p3.y-p0.y)*(p3.y-p0.y)>r*r)	{
		cout<<p0.x<<" "<<p0.y<<" "<<r<<endl;
		return 0;
	}
	p1.x=2*p0.x-p3.x;
	p1.y=2*p0.y-p3.y;
	double theta=atan2(p1.y-p0.y,p1.x-p0.x);
	p2.x=p0.x+r*cos(theta);
	p2.y=p0.y+r*sin(theta);
	point ans;
	ans.x=(p2.x+p3.x)/2;
	ans.y=(p2.y+p3.y)/2;
	double rr=get_dist(ans,p3);
	//cout<<ans.x<<" "<<ans.y<<" "<<rr<<endl;
	printf("%.11lf %.11lf %.11lf\n",ans.x,ans.y,rr);
	return 0;
}
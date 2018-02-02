#include <bits/stdc++.h>
using namespace std;

int main()	{
	int n,m;
	cin>>n>>m;
	int a,b;
	double maxx=1000000;
	for(int i=0;i<n;i++)	{
		cin>>a>>b;
		maxx=min(maxx,a*m/(1.0*b));
	}
	//cout<<maxx<<endl;
	printf("%.11lf\n",maxx);
	return 0;
}
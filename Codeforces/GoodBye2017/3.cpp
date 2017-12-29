#include <bits/stdc++.h>
using namespace std;
int x[1010];
double y[1010];
int main()	{
	int n,r;
	cin>>n>>r;
	for(int i=0;i<n;i++)	{
		cin>>x[i];
	}
	y[0]=r;
	printf("%.11lf",y[0]);
	for(int i=1;i<n;i++)	{
		// bool flag=false;
		y[i]=r;
		int po=-1;
		for(int j=i-1;j>=0;j--)	{
			if(abs(x[j]-x[i])<=2*r)	{
				if(po==-1 || y[j]>y[po])	{
					po=j;
				}
				// flag=true;
			}
		}
		if(po!=-1)	{
				y[i]=4*r*r-((x[po]-x[i])*(x[po]-x[i]));
				y[i]=(double)sqrt(y[i]);
				y[i]=y[i]+y[po];
		}
		// if(flag==false)	{
		// 	y[i]=r;
		// }
		printf(" %.11lf",y[i]);
	}
	printf("\n");
	return 0;
}
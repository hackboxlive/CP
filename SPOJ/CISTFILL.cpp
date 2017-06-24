#include <bits/stdc++.h>
using namespace std;
struct node	{
	int b;
	int h;
	int w;
	int d;
}cisterns[50500];
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		int n;
		double hi=INT_MIN;
		double lo=0.0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)	{
			scanf("%d%d%d%d",&cisterns[i].b,&cisterns[i].h,&cisterns[i].w,&cisterns[i].d);
			if(cisterns[i].b+cisterns[i].h>hi)	{
				hi=cisterns[i].b+cisterns[i].h;
			}
		}
		int totcap;
		scanf("%d",&totcap);
		double mid;
		double vol;
		int ctr=0;
		while((hi-lo)>0.0001)	{
			mid=lo+(hi-lo)/2;
//			cout<<"lo= "<<lo<<" and hi= "<<hi<<endl;
//			cout<<"mid= "<<mid<<endl;
			vol=0;
			for(int i=0;i<n;i++)	{
				if(cisterns[i].b>=mid)	{
					continue;
				}
				else if(cisterns[i].b+cisterns[i].h<=mid)	{
					vol=vol+(cisterns[i].h*cisterns[i].w*cisterns[i].d);
				}
				else	{
					vol=vol+(cisterns[i].w*cisterns[i].d*(mid-cisterns[i].b));
				}
				cout<<"New volume= "<<vol<<endl;
			}
			if(vol>=totcap)	{
				hi=mid;
			}
			else	{
				lo=mid;
			}
		}
		if(vol<totcap)	{
			cout<<vol<<endl;
			printf("OVERFLOW\n");
			continue;
		}
		printf("%.2lf\n",lo);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
struct node	{
	double x;
	double y;
}arr[8000000];
void farey(int n)	{
	arr[1].x=0;
	arr[1].y=1;
	arr[2].x=1;
	arr[2].y=n;
	double ty=2;
	int ctr=3;
	while(ctr<=8000000 && ty!=1.0)	{
		arr[ctr].x=floor((double)(arr[ctr-2].y+n)/arr[ctr-1].y)*arr[ctr-1].x-arr[ctr-2].x;
		arr[ctr].y=floor((double)(arr[ctr-2].y+n)/arr[ctr-1].y)*arr[ctr-1].y-arr[ctr-2].y;
		ty=arr[ctr].y;
		ctr++;
	}
	return;
}
int main()	{
	int t,n,m;
	int jj;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d%d",&n,&m);
		farey(n);
		while(m--)	{
			scanf("%d",&jj);
			printf("%.0lf/%.0lf\n",arr[jj].x,arr[jj].y);
		}
	}
	return 0;
}
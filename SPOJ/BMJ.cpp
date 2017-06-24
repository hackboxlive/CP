#include <bits/stdc++.h>
using namespace std;
pair<int,int> arr[500100];
void precompute()	{
	arr[1].first=0;
	arr[1].second=0;
	arr[2].first=0;
	arr[2].second=1;
	arr[3].first=-1;
	arr[3].second=1;
	arr[4].first=-1;
	arr[4].second=0;
	arr[5].first=0;
	arr[5].second=-1;
	arr[6].first=1;
	arr[6].second=-1;
	int num=7;
	int steps=2;
	int x=1;
	int y=-1;
	while(num<=100100)	{
//		int x=steps-1;
//		int y=-1*x+1;
		for(int i=0;i<steps;i++)	{
			arr[num].first=x;
			y++;
			arr[num].second=y;
			num++;
		}
		for(int i=0;i<steps-1;i++)	{
			x--;
			y++;
			arr[num].first=x;
			arr[num].second=y;
			num++;
		}
		for(int i=0;i<steps;i++)	{
			x--;
			arr[num].first=x;
			arr[num].second=y;
			num++;
		}
		for(int i=0;i<steps;i++)	{
			y--;
			arr[num].first=x;
			arr[num].second=y;
			num++;
		}
		for(int i=0;i<steps;i++)	{
			x++;
			y--;
			arr[num].first=x;
			arr[num].second=y;
			num++;
		}
		for(int i=0;i<steps;i++)	{
			x++;
			arr[num].first=x;
			arr[num].second=y;
			num++;
		}
		steps++;
	}
//	for(int i=1;i<=49;i++)	{
//		cout<<i<<" "<<arr[i].first<<" "<<arr[i].second<<endl;
//	}
	return;
}
int main()	{
	int n;
	precompute();
	while(scanf("%d",&n)==1)	{
		printf("%d %d\n",arr[n].first,arr[n].second);
	}
	return 0;
}
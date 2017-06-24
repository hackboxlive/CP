#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n;
	double slopes[40100];
	vector<pair<int,int> > points;
	scanf("%d",&n);
	int x,y;
	while(n!=0)	{
		points.clear();
		for(int i=0;i<n;i++)	{
			scanf("%d%d",&x,&y);
			points.push_back(make_pair(x,y));
		}
		int ctr=0;
		for(int i=0;i<n;i++)	{
			for(int j=i+1;j<n;j++)	{
				if(points[i].first!=points[j].first)
					slopes[ctr]=(double)(points[i].second-points[j].second)/(double)(points[i].first-points[j].first);
				else
					slopes[ctr]=INT_MAX;
				ctr++;
			}
		}
		sort(slopes,slopes+ctr);
		int count=1;
		for(int i=1;i<ctr;i++)	{
			if(slopes[i]!=slopes[i-1])	{
				count++;
			}
		}
		printf("%d\n",count);
		scanf("%d",&n);
	}
	return 0;
}
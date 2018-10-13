#include <bits/stdc++.h>
using namespace std;

bool comp(const pair<int,int> &a, const pair<int,int> &b)
{
	if(a.first==b.first)
	{
		return a.second<b.second;
	}
	return a.first<b.first;
}
int main()
{
	int t;
	cin>>t;
	pair<int,int> points[5], rev[5];
	while(t--)
	{
		for(int i=0;i<5;i++)
		{
			cin>>points[i].first>>points[i].second;
			rev[i].first=points[i].second;
			rev[i].second=points[i].first;
		}
		sort(points, points+5, comp);
		sort(rev, rev+5, comp);
		if(points[0].first==points[1].first && points[1].first==points[2].first)
		{
			if(points[0].second+1==points[1].second && points[1].second+1==points[2].second)
			{
				if(points[1].first+1==points[3].first && points[3].first+1==points[4].first)
				{
					if(points[1].second==points[3].second && points[3].second==points[4].second)
					{
						cout<<"Yes\n";
						continue;
					}
				}
			}
		}
		if(points[2].first==points[3].first && points[3].first==points[4].first)
		{
			if(points[2].second+1==points[3].second && points[3].second+1==points[4].second)
			{
				if(points[0].first+1==points[1].first && points[1].first+1==points[3].first)
				{
					if(points[0].second==points[1].second && points[1].second==points[3].second)
					{
						cout<<"Yes\n";
						continue;
					}
				}
			}
		}
		if(rev[0].first==rev[1].first && rev[1].first==rev[2].first)
		{
			if(rev[0].second+1==rev[1].second && rev[1].second+1==rev[2].second)
			{
				if(rev[1].first+1==rev[3].first && rev[3].first+1==rev[4].first)
				{
					if(rev[1].second==rev[3].second && rev[3].second==rev[4].second)
					{
						cout<<"Yes\n";
						continue;
					}
				}
			}
		}
		if(rev[2].first==rev[3].first && rev[3].first==rev[4].first)
		{
			if(rev[2].second+1==rev[3].second && rev[3].second+1==rev[4].second)
			{
				if(rev[0].first+1==rev[1].first && rev[1].first+1==rev[3].first)
				{
					if(rev[0].second==rev[1].second && rev[1].second==rev[3].second)
					{
						cout<<"Yes\n";
						continue;
					}
				}
			}
		}
		cout<<"No\n";
	}
	return 0;
}
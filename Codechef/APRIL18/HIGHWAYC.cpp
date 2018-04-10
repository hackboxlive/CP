#include <bits/stdc++.h>
using namespace std;
int velocity[11],direction[11],position[11],length[11];
pair<double,double> danger[11];
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		int n,chef_speed,lane_width;
		cin>>n>>chef_speed>>lane_width;
		for(int i=0;i<n;i++)	{
			cin>>velocity[i];
		}
		for(int i=0;i<n;i++)	{
			cin>>direction[i];
		}
		for(int i=0;i<n;i++)	{
			cin>>position[i];
		}
		for(int i=0;i<n;i++)	{
			cin>>length[i];
		}
		for(int i=0;i<n;i++)	{
			if(direction[i]==1)	{
				if(position[i]>length[i])	{
					danger[i].first=-1.0;
					danger[i].second=-1.0;
				}
				else	{
					if(position[i]>=0)	{
						danger[i].first=0.0;
						danger[i].second=(double)(abs(position[i]-length[i]))/velocity[i];
					}
					else	{
						danger[i].first=(double)abs(position[i])/velocity[i];
						danger[i].second=(double)(abs(abs(position[i])+length[i]))/velocity[i];
					}
				}
			}
			else	{
				if(position[i]<(-1)*length[i])	{
					danger[i].first=-1.0;
					danger[i].second=-1.0;
				}
				else	{
					if(position[i]<=0)	{
						danger[i].first=0.0;
						danger[i].second=(double)(abs(position[i]+length[i]))/velocity[i];
					}
					else	{
						danger[i].first=(double)abs(position[i])/velocity[i];
						danger[i].second=(double)(abs(abs(position[i])+length[i]))/velocity[i];
					}
				}
			}
		}
		double time_for_chef=(double)lane_width/chef_speed;
		// for(int i=0;i<n;i++)	{
		// 	cout<<danger[i].first<<" "<<danger[i].second<<endl;
		// }
		//cout<<time_for_chef<<endl;
		double cur=0.0;
		for(int i=0;i<n;i++)	{
			if(danger[i].first==-1.0)	{
				cur+=time_for_chef;
			}
			else	{
				if(cur+time_for_chef>=danger[i].first && cur+time_for_chef<=danger[i].second)	{
					cur=danger[i].second+time_for_chef;
				}
				else	{
					cur+=time_for_chef;
				}
			}
			//cout<<cur<<endl;
		}
		//cout<<cur<<endl;
		printf("%.11lf\n",cur);
	}
	return 0;
}
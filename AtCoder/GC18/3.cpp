#include <bits/stdc++.h>
using namespace std;
struct node	{
	pair<int,int> coin[3];
	int cur;
}arr[100100];
bool comp1(const pair<int,int> &a,const pair<int,int> &b)	{
	return a.first>b.first;
}
bool comp2(const node &c,const node &d)	{
	if(c.coin[0].first==d.coin[0].first && c.coin[1].first==d.coin[1].first)	{
		return c.coin[2].first>d.coin[2].first;
	}
	if(c.coin[0].first==d.coin[0].first)	{
		return c.coin[1].first>d.coin[1].first;
	}
	return c.coin[0].first>d.coin[0].first;
}
int main()	{
	long long x,y,z;
	cin>>x>>y>>z;
	long long tot=x+y+z;
	int dpx=x,dpy=y,dpz=z;
	for(int i=0;i<tot;i++)	{
		cin>>arr[i].coin[0].first>>arr[i].coin[1].first>>arr[i].coin[2].first;
		arr[i].cur=0;
		arr[i].coin[0].second=0;
		arr[i].coin[1].second=1;
		arr[i].coin[2].second=2;
		sort(arr[i].coin,arr[i].coin+3,comp1);
	}
	long long ans=0;int u;
	sort(arr,arr+tot,comp2);
	for(int i=0;i<tot;i++)	{
		for(int j=0;j<3;j++)	{
			cout<<arr[i].coin[j].first<<" "<<arr[i].coin[j].second<<" new ";
		}
		cout<<endl;
	}
	for(int l=0;l<3;l++)	{
		for(int i=0;i<tot;i++)	{
			if(arr[i].cur==1)	{
				continue;
			}
			u=arr[i].coin[0].second;
			if(u==0)	{
				if(dpx>0)	{
					dpx--;
					arr[i].cur=1;
					ans+=arr[i].coin[0].first;
					arr[i].coin[0].first=-1;
				}
				else	{
					for(int i=0;i<tot;i++)	{
						for(int j=0;j<3;j++)	{
							if(arr[i].coin[j].second==0)	{
								arr[i].coin[j].first=-1;
							}
						}
					}
					break;
				}
			}
			if(u==1)	{
				if(dpy>0)	{
					dpy--;
					arr[i].cur=1;
					ans+=arr[i].coin[0].first;
					arr[i].coin[0].first=-1;
				}
				else	{
					for(int i=0;i<tot;i++)	{
						for(int j=0;j<3;j++)	{
							if(arr[i].coin[j].second==1)	{
								arr[i].coin[j].first=-1;
							}
						}
					}
					break;
				}
			}
			if(u==2)	{
				if(dpz>0)	{
					dpz--;
					arr[i].cur=1;
					ans+=arr[i].coin[0].first;
					arr[i].coin[0].first=-1;
				}
				else	{
					for(int i=0;i<tot;i++)	{
						for(int j=0;j<3;j++)	{
							if(arr[i].coin[j].second==2)	{
								arr[i].coin[j].first=-1;
							}
						}
					}
					break;
				}
			}
		}
		for(int i=0;i<tot;i++)	{
			sort(arr[i].coin,arr[i].coin+3,comp1);
		}
		sort(arr,arr+tot,comp2);
		for(int i=0;i<tot;i++)	{
		for(int j=0;j<3;j++)	{
			cout<<arr[i].coin[j].first<<" "<<arr[i].coin[j].second<<" new ";
		}
		cout<<endl;
	}

	}
	cout<<ans<<endl;
	return 0;
}
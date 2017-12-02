#include <bits/stdc++.h>
using namespace std;
int n,m,c,p;
int arr[1001];
pair<int,int> bucket[1001];

void fit_in(int k)	{
	if(p>arr[k])	{
		bool flag=false;
		for(int i=k+1;i<=n;i++)	{
			if(arr[i]==-1 || arr[i]>p)	{
				arr[i]=p;
				flag=true;
				fflush(stdout);
				return;
			}
		}
		if(flag==false)	{
			arr[n]=p;
			fflush(stdout);
			return;
		}
	}
	else if(p<arr[k])	{
		
	}
}
int main()	{
	cin>>n>>m>>c;
	int v=c/n;
	for(int i=1;i<=n;i++)	{
		bucket[i].first=(i-1)*v+1;
		bucket[i].second=i*v;
	}
	bucket[n].second=c;
	for(int i=1;i<=n;i++)	{
		arr[i]=-1;
	}
	while(m--)	{
		cin>>p;
		for(int i=1;i<=n;i++)	{
			if(p>=bucket[i].first && p<=bucket[i].second)	{
				if(arr[i]==-1)	{
					arr[i]=p;
					cout<<i;
					fflush(stdout);
					continue;
				}
				else	{
					fit_in(i);
				}
			}
		}
	}
	return 0;
}
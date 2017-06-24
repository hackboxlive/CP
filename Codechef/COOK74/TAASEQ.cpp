#include <bits/stdc++.h>
using namespace std;
int arr[100100];
vector<int> v;	
int main()	{
	int t,n;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)	{
			scanf("%d",&arr[i]);
		}
		if(n==2)	{
			printf("%d\n",min(arr[0],arr[1]));
			continue;
		}
		if(n==3)	{
			printf("%d\n",min(arr[0],min(arr[1],arr[2])));
			continue;
		}
		for(int i=1;i<n;i++)	{
			v.push_back(arr[i]-arr[i-1]);
		}
		sort(v.begin(),v.end());
		int cd=1;
		for(int i=1;i<v.size();i++)	{
			if(v[i]!=v[i-1])	{
				cd++;
			}
		}
		if(cd>2)	{
			printf("-1\n");
		}
		else if(cd==0)	{
			printf("%d\n",min(arr[0],arr[n-1]));
		}
		else if(cd==1)	{
			if(arr[1]-arr[0]==arr[2]-arr[1])	{
				if(arr[n-1]-arr[n-2]==arr[n-2]-arr[n-3])	{
					printf("-1\n");
				}
				else	{
					printf("%d\n",arr[n-1]);
				}
			}
			else	{
				printf("%d\n",arr[0]);
			}
		}
		else	{
			for(int i=1;i<n;i++)	{
				if(arr[i]-arr[i-1]!=arr[i+1]-arr[i])	{
					if(arr[i+1]-arr[i-1]==arr[i+1]-arr[i-2])	{
						printf("%d\n",arr[i]);
					}
				}
			}
		}
		v.clear();
	}
}
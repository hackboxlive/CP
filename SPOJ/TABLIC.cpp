#include <bits/stdc++.h>
using namespace std;
struct node	{
	int x,r,c;
	int px,py;
}arr[1100];
int main()	{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<k;i++)	{
		cin>>arr[i].x>>arr[i].r>>arr[i].c;
		arr[i].px=(arr[i].x-1)/n;
		arr[i].py=(arr[i].x-1)%n;
		arr[i].r--;
		arr[i].c--;
	}
	int cnt;
	for(int i=0;i<k;i++)	{
		if(arr[i].r<arr[i].px)	{
			cnt=n+(arr[i].r-arr[i].px);
		}
		else	{
			cnt=arr[i].r-arr[i].px;
		}
		if(arr[i].c<arr[i].py)	{
			cnt+=n;
			cnt+=arr[i].c-arr[i].py;
		}
		else	{
			cnt+=arr[i].c-arr[i].py;
		}
		for(int j=i+1;j<k;j++)	{
			if(arr[j].px!=arr[i].px)	{
				continue;
			}
			arr[j].py+=(arr[i].c-arr[i].py);
			if(arr[j].py<0)	{
				arr[j].py+=n;
			}
			if(arr[j].py>=n)	{
				arr[j].py-=n;
			}
		}
		arr[i].py=arr[i].c;
		for(int j=i+1;j<k;j++)	{
			if(arr[j].py!=arr[i].py)	{
				continue;
			}
			arr[j].px+=(arr[i].r-arr[i].px);
			if(arr[j].px<0)	{
				arr[j].px+=n;
			}
			if(arr[j].px>=n)	{
				arr[j].px-=n;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
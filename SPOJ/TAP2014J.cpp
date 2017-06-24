#include <bits/stdc++.h>
using namespace std;
struct node	{
	int val;
	bool sat;
}arr[100100];
int main()	{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)	{
		scanf("%d",&arr[i].val);
	}
	arr[n].sat=true;
	for(int i=n-1;i>=0;i--)	{
		if(i+1+arr[i].val<=n && arr[i+1+arr[i].val].sat==true)	{
			arr[i].sat=true;
		}
		else	{
			arr[i].sat=false;
		}
	}
	for(int i=1;i<=n;i++)	{
		if(arr[i].sat==true)	{
			printf("%d\n",i);
		}
	}
	return 0;
}
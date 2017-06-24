#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int main()	{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)	{
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n);
//	int flag=0;
	int ctr=1;
	vector<int> diff;
	diff.push_back(arr[0]);
	for(int i=1;i<n;i++)	{
		if(arr[i]!=arr[i-1])	{
			ctr++;
			diff.push_back(arr[i]);
		}
	}
	if(ctr==1 || ctr==2)	{
		printf("YES\n");
	}
	else if(ctr==3 && diff[1]-diff[0]==diff[2]-diff[1])	{
		printf("YES\n");
	}
	else	{
		printf("NO\n");
	}
	return 0;
}
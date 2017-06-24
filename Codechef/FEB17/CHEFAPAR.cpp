#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int main()	{
	int t,n;
	int firstzero,flag;
	long long int fine;
	scanf("%d",&t);
	while(t--)	{
		fine=0;
		firstzero=-1;
		flag=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)	{
			scanf("%d",&arr[i]);
			if(arr[i]==0)	{
				fine++;
				if(flag==0)	{
					flag=1;
					firstzero=i;
				}
			}
		}
		if(firstzero==-1)	{
			cout<<"0"<<endl;
		}
		else	{
			fine=fine*1000;
			fine+=(n-firstzero)*100;
			cout<<fine<<endl;
		}
	}
	return 0;
}
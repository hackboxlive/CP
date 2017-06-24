#include <bits/stdc++.h>
using namespace std;
int arr[110];
long double bit[40];
int main()	{
	double prob;
	int n;
	scanf("%lf",&prob);
	scanf("%d",&n);
	for(int i=0;i<n;i++)	{
		scanf("%d",&arr[i]);
	}
	int num=arr[0];
	for(int i=0;i<40;i++)	{
		int r=num%2;
		if(r==1)	{
			bit[i]=1;
		}
		else	{
			bit[i]=0;
		}
		num=num/2;
	}
	for(int i=1;i<n;i++)	{
		num=arr[i];
		for(int j=0;j<40;j++)	{
			int r=num%2;
			if(r==0)	{
				bit[j]=(long double)bit[j]*(1-prob);
			}
			else	{
				bit[j]=(long double)bit[j]+(1-(bit[j]))*(1-prob);
			}
			num=num/2;
		}
	}
	long double ans=0.0;
	long long int two=1;
	for(int i=0;i<40;i++)	{
		ans=ans+(two*bit[i]);
		two=two*2;
	}
	printf("%.2Lf\n",ans);
	return 0;
}
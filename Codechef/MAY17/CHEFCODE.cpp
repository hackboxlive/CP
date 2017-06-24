#include <bits/stdc++.h>
using namespace std;
int n;
long long k;
long long arr[31];
double logarr[31];
double first[40000],second[40000];
int fsz,ssz;
void store()	{
	int firstnum=n/2;
	int secondnum=n-firstnum;
	int j,p;
	double summ;
	fsz=0;
	for(int i=0;i<(1<<firstnum);i++)	{
		j=i;
		p=0;
		summ=0;
		while(j!=0)	{
			if(j%2)	{
				summ+=logarr[p];
			}
			p++;
			j/=2;
		}
		first[i]=summ;
		fsz++;
	}
	ssz=0;
	for(int i=0;i<(1<<secondnum);i++)	{
		j=i;
		p=n/2;
		summ=0;
		while(j!=0)	{
			if(j%2)	{
				summ+=logarr[p];
			}
			p++;
			j/=2;
		}
		second[i]=summ;
		ssz++;
	}
	sort(second,second+ssz);
}
int main()	{
	scanf("%d %lld",&n,&k);
	for(int i=0;i<n;i++)	{
		scanf("%lld",&arr[i]);
		logarr[i]=log(arr[i]);
	}
	int mid=n/2;
	store();
	double klog=log(k);
	double val;
	int ans=0;
	for(int i=0;i<fsz;i++)	{
		val=klog-first[i];
		ans+=(upper_bound(second,second+ssz,val)-second);
	}
	printf("%d\n",ans-1);
	return 0;
}
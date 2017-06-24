#include <bits/stdc++.h>
using namespace std;
struct node	{
	int st;
	int en;
	int cnt;
}activities[100100];
bool comp(const node &p1,const node &p2)	{
	if(p1.en!=p2.en)	{
		return p1.en<p2.en;
	}
	return p1.st<p2.st;
}
int main()	{
	int n;
	int elem;
	scanf("%d",&n);
	int lo,mid,hi,prevlo,prevhi;
	while(n!=-1)	{
		for(int i=0;i<n;i++)	{
			scanf("%d %d",&activities[i].st,&activities[i].en);
		}
		sort(activities,activities+n,comp);
		activities[0].cnt=1;
		for(int i=1;i<n;i++)	{
			prevhi=prevlo=-1;
			lo=0;
			hi=i;
			while(lo<hi)	{
				mid=lo+(hi-lo)/2;
				if(prevlo==lo && prevhi==hi)	{
					break;
				}
				prevhi=hi;
				prevlo=lo;
				if(activities[mid].en>activities[i].st)	{
					hi=mid;
				}
				else	{
					lo=mid+1;
				}
			}
			lo--;
			if(lo==-1)	{
				activities[i].cnt=(1+activities[i-1].cnt)%100000000;
			}
			else	{
				activities[i].cnt=(1+activities[i-1].cnt+activities[lo].cnt)%100000000;
			}
		}
		cout<<setfill('0')<<setw(8)<<activities[n-1].cnt<<endl;
		scanf("%d",&n);
	}
	return 0;
}
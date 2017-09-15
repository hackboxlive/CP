#include <bits/stdc++.h>
using namespace std;
struct node	{
	int day;
	int start;
	int finish;
	int cost;
}travel[100100];
struct nn{
	int pre;
	long long summ;
	int l;
	int r;
}ftree[1000100],btree[1000100];
int sf[100100];
int sb[100100];
bool comp(const node &a,const node &b)	{
	return a.day<b.day;
}
void update_ftree(int id,int st,int en,int pos,int v)	{
	if(st>pos || en<pos)	{
		return;
	}
	if(st==pos && en==pos)	{
		ftree[id].pre=1;
		ftree[id].summ=v;
		return;
	}
	if(pos>(st+en)/2)	{
		ftree[id].l=
	}
}
int main()	{
	ios_basse::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)	{
		cin>>travel[i].day>>travel[i].start>>travel[i].finish>>travel[i].cost;
	}
	sort(travel,travel+m,comp);
	int l=0,r;
	int ans=-1;
	for(int i=1;i<m;i++)	{
		if(travel[i].day - travel[l].day >= k)	{
			r=i;
			break;
		}
	}
	//forward segment trees
	int start=1;
	for(int i=0;i<m;i++)	{
		if(travel[i].finish==0)	{
			sf=start;
			start++;
			build_ftree(start,0,n-1,travel[i].start,travel[i].cost);
		}
	}
	return 0;
}
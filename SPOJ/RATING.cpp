#include <bits/stdc++.h>
using namespace std;
int n;
struct node
{
	int id;
	int x;
	int y;
	int val;
}arr[300100];
int BIT[100100];
//vector<pair<int,pair<int,int> > > g;
bool comp1(const struct node &p1,const struct node &p2)	{
	if(p1.x!=p2.x)	{
		return p1.x<p2.x;
	}
	else	{
		return p1.y<p2.y;
	}
}
bool comp2(const struct node &p1,const struct node &p2)	{
	return p1.id<p2.id;
}
int query(int x)	{
	int sum=0;
	for(;x>0;x=x-(x&-x))	{
		sum=sum+BIT[x];
	}
	return sum;
}
void update(int x)	{
	for(;x<=100000;x=x+(x&-x))	{
		BIT[x]++;
	}
}
int main()	{
	int l,r;
	scanf("%d",&n);
	memset(BIT,0,sizeof(BIT));
	for(int i=0;i<n;i++)	{
		scanf("%d%d",&l,&r);
		arr[i].id=i+1;
		arr[i].x=l;
		arr[i].y=r;
	}
//	for(int i=0;i<n;i++)	{
//		printf("%d %d %d\n",arr[i].id,arr[i].x,arr[i].y);
//	}
	sort(arr,arr+n,comp1);
//	for(int i=0;i<n;i++)	{
//		printf("%d %d %d\n",arr[i].id,arr[i].x,arr[i].y);
//	}
	update(arr[0].y);
	arr[0].val=0;
	for(int i=1;i<n;)	{
		int e=i;
        while(e<n && arr[e].x==arr[i].x && arr[e].y==arr[i].y)	{
        	++e;
        }
        for(int j=i;j<e;++j)	{
			arr[j].val=query(arr[j].y);
        }
		for(int j=i;j<e;++j)	{
			update(arr[j].y);
		}
		i = e;
	}
//	for(int i=0;i<n;i++)	{
//		printf("%d %d\n",arr[i].id,BIT[arr[i].y]);
//	}
	sort(arr,arr+n,comp2);
	for(int i=0;i<n;i++)	{
		printf("%d\n",arr[i].val);
	}
	return 0;
}
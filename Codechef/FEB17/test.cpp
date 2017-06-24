#include <bits/stdc++.h>
using namespace std;
int arr[100100];
struct node	{
	int val;
	int pos;
	int init;
	int newpos;
}cparr[200200];
int que[100100][3];
int c[100100];
bool comp1(const node &p1,const node &p2)	{
	return p1.val<p2.val;
}
bool comp2(const node &p1,const node &p2)	{
	return p1.pos<p2.pos;
}
vector<int> vv;
int main()	{
	int n,q,m;
	int cctr=1;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)	{
		scanf("%d",&arr[i]);
		cparr[cctr].val=arr[i];
		cparr[cctr].pos=i;
		cparr[cctr].init=1;
		cctr++;
	}

	//input and add tree
	for(int i=1;i<=q;i++)	{
		scanf("%d%d%d",&que[i][0],&que[i][1],&que[i][2]);
		if(que[i][0]==2)	{
			cparr[cctr].val=que[i][2];
			cparr[cctr].pos=cctr;
			cparr[cctr].init=0;
			cctr++;
		}
	}
//	for(int i=1;i<cctr;i++)	{
//		cout<<cparr[i].pos<<" "<<cparr[i].val<<endl;
//	}
	sort(cparr+1,cparr+cctr,comp1);
	vv.push_back(cparr[1].val);
	cparr[1].newpos=1;
	for(int i=2;i<=cctr;i++)	{
		if(cparr[i].val != cparr[i-1].val)	{
			vv.push_back(cparr[i].val);
			cparr[i].newpos=(int)(vv.size());
		}
		else	{
			cparr[i].newpos=(int)(vv.size());
		}
	}
//	for(int i=1;i<cctr;i++)	{
//		cout<<cparr[i].pos<<" "<<cparr[i].val<<" "<<cparr[i].newpos<<endl;
//	}
	m=(int)(vv.size());
	sort(cparr+1,cparr+cctr,comp2);
	for(int i=1;i<=n;i++)	{
		c[i]=cparr[i].newpos;
	}
	for(int i=1;i<=q;i++)	{
		if(que[i][0]==2)	{
			que[i][2]=cparr[n+i].newpos;
		}
	}
//	for(int i=1;i<=n;i++)	{
//		cout<<c[i]<<endl;
//	}
//	for(int i=1;i<=q;i++)	{
//		if(que[i][0]==2)	{
//			cout<<que[i][2];
//		}
//	}
	return 0;
}
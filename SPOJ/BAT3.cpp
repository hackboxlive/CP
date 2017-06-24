#include <bits/stdc++.h>
using namespace std;
int arr[100100];
vector<int> lds;
int bsearch(int l,int r,int val)	{
	int mid;
	while(l<r)	{
		mid=(l+r)/2;
		if(lds[mid]>val)	{
			l=mid+1;
		}
		else	{
			r=mid;
		}
	}
	return l;
}
int main()	{
	int t;
	int n,k,pos;
	int sz;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++)	{
			scanf("%d",&arr[i]);
		}
		//calculate Longest Decreasing Subsequence in array
		lds.clear();
		lds.push_back(arr[0]);
		sz=1;
		int kval=1;
		for(int i=1;i<n;i++)	{
			pos=bsearch(0,sz-1,arr[i]);
			if(pos==sz-1 && lds[pos]>arr[i])	{
				lds.push_back(arr[i]);
				sz++;
				if(i==k)	{
					kval=sz;
				}
				continue;
			}
			if(i==k)	{
				kval=pos+1;
			}
			lds[pos]=arr[i];
		}
//		printf("%d %d\n",lds.size(),kval);
		int maxl=lds.size();
		lds.clear();
		if(k==n-1)	{
			printf("%d\n",maxl);
			continue;
		}
		lds.push_back(arr[k+1]);
		sz=1;
		for(int i=k+2;i<n;i++)	{
			pos=bsearch(0,sz-1,arr[i]);
			if(pos==sz-1 && lds[pos]>arr[i])	{
				lds.push_back(arr[i]);
				sz++;
				continue;
			}
			lds[pos]=arr[i];
		}
		int newl=lds.size();
		if(newl+kval>maxl)	{
			printf("%d\n",newl+kval);
		}
		else	{
			printf("%d\n",maxl);
		}
	}
	return 0;
}
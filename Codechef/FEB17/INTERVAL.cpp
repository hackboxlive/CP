#include <bits/stdc++.h>
using namespace std;
long long int arr[300300];
long long int segments[220];
long long int chefsum[300300];
long long int brosum[300300];
deque<int> Qi(300300);

void findKMaxMin(long long int arr[],long long int barr[],int n,int k,int mxmn)
{
	int i;
	long long int val;
	int ctr=0;
	for(i=0;i<k;++i)	{
		while((!Qi.empty()) && arr[i]>=arr[Qi.back()] && mxmn==1)	{
			Qi.pop_back();
		}
		while((!Qi.empty()) && arr[i]<=arr[Qi.back()] && mxmn==0)	{
			Qi.pop_back();
		}
		Qi.push_back(i);
	}
	for(;i<n;++i)
	{
		val=arr[Qi.front()];
		barr[ctr]+=val;
		ctr++;
		while((!Qi.empty()) && Qi.front()<=i-k)	{
			Qi.pop_front();
		}
		while((!Qi.empty()) && arr[i]>=arr[Qi.back()] && mxmn==1)	{
			Qi.pop_back();
		}
		while((!Qi.empty()) && arr[i]<=arr[Qi.back()] && mxmn==0)	{
			Qi.pop_back();
		}
		Qi.push_back(i);
	}
	val=arr[Qi.front()];
	barr[ctr]+=val;
	ctr++;
	while(!(Qi.empty()))	{
		Qi.pop_front();
	}
	return;
}
int main()	{
	int t;
	int n,m;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)	{
			scanf("%lld",&arr[i]);
		}
		for(int i=0;i<m;i++)	{
			scanf("%lld",&segments[i]);
		}
		int segsize=segments[m-1];
		int shift=m-1;
		int chefsize=n-2*shift-segsize+1;
		int brosize;
		chefsum[0]=0;
		for(int i=0;i<segsize;i++)	{
			chefsum[0]+=arr[i+shift];
		}
		for(int i=1;i<chefsize;i++)	{
			chefsum[i]=chefsum[i-1]+arr[i+shift+segsize-1]-arr[i+shift-1];
		}
		if(m%2==0)	{
			for(int i=0;i<n-2*shift;i++)	{
				chefsum[i]*=-1;
			}
		}
		for(int i=m-2;i>=0;i--)	{
			segsize=segments[i];
			shift=i;
			brosum[0]=0;
			for(int j=0;j<segsize;j++)	{
				brosum[0]+=arr[j+shift];
			}
			for(int j=1;j<n-2*shift-segsize+1;j++)	{
				brosum[j]=brosum[j-1]+arr[j+shift+segsize-1]-arr[j+shift-1];
			}
			brosize=n-2*shift-segsize+1;
			if(i%2==1)	{
				for(int j=0;j<n-2*shift-segsize+1;j++)	{
					brosum[j]*=-1;
				}
				findKMaxMin(chefsum,brosum,chefsize,chefsize-brosize+1,1);
			}
			else	{
				findKMaxMin(chefsum,brosum,chefsize,chefsize-brosize+1,0);
			}
			for(int j=0;j<brosize;j++)	{
				chefsum[j]=brosum[j];
			}
			chefsize=brosize;
		}
		long long int gmax=-1;
		for(int i=0;i<chefsize;i++)	{
			if(chefsum[i]>=gmax)	{
				gmax=chefsum[i];
			}
		}
		cout<<gmax<<endl;
	}
	return 0;
}
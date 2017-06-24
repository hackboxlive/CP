#include <bits/stdc++.h>
using namespace std;
long long int arr[21000];
long long int answer[21000];
long long int tree[100100];
long long int powermax=(long long int)1<<60;
void build_tree(int id,int l,int r)	{
//	cout<<l<<" "<<r<<endl;
	if(l==r)	{
		tree[id]=arr[l];
		return;
	}
	build_tree(2*id,l,(l+r)/2);
	build_tree(2*id+1,(l+r)/2+1,r);
	tree[id]=tree[2*id]&tree[2*id+1];
	return;
}
long long int query_tree(int id,int start,int end,int l,int r)	{
	if(start>r || end<l)	{
		return powermax; 
	}
	if(start>=l && end<=r)	{
		return tree[id];
	}
	long long int p=query_tree(2*id,start,(start+end)/2,l,r);
	long long int q=query_tree(2*id+1,(start+end)/2+1,end,l,r);
//	cout<<start<<"\t"<<end<<"\t"<<p<<"\t"<<q<<endl;
	return (long long int)p&q;
}
int main()	{
	int t;
	powermax--;
	scanf("%d",&t);
	while(t--)	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++)	{
			scanf("%lld",&arr[i]);
		}
		build_tree(1,0,n-1);
		if(k>(n-1)/2)	{
			answer[0]=query_tree(1,0,n-1,0,n-1);
			for(int i=0;i<n;i++)	{
				answer[i]=answer[0];
			}
		}
		else	{
			for(int i=0;i<n;i++)	{
				int ll=i-k;
				int rl=i+k;
//				printf("%d %d\n",ll,rl);
				if(ll<0 && rl<n)	{
					ll=ll+n;
//					cout<<query_tree(1,0,n-1,0,rl)<<endl;
//					cout<<query_tree(1,0,n-1,ll,n-1)<<endl;
					answer[i]=(long long int)query_tree(1,0,n-1,0,rl)&query_tree(1,0,n-1,ll,n-1);
				}
				else if(ll>=0 && rl>=n)	{
					rl=rl-n;
					answer[i]=query_tree(1,0,n-1,0,rl)&query_tree(1,0,n-1,ll,n-1);
				}
				else if(ll>=0 && rl<n)	{
					answer[i]=query_tree(1,0,n-1,ll,rl);
				}
//				cout<<i<<"herhe"<<endl;
			}
		}
		for(int i=0;i<n;i++)	{
			printf("%lld ",answer[i]);
		}
		printf("\n");
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
string s;
int n,k,p;
int arr[200200];
int numones[100100];
int tree[6*100100];
void precompute()	{
	for(int i=0;i<n;i++)	{
		arr[i+n]=arr[i];
	}
	int cnt=0;
	for(int i=0;i<k;i++)	{
		if(arr[2*n-1-i]==1)	{
			cnt++;
		}
	}
	numones[n-1]=cnt;
	int r=2*n-1;
	int l=2*n-k-1;
	for(int i=n-2;i>=0;i--)	{
		if(arr[r]==1)	{
			cnt--;
		}
		if(arr[l]==1)	{
			cnt++;
		}
		r--;
		l--;
		numones[i]=cnt;
	}
}
void build(int id=1,int l=0,int r=n-1)	{
	if(l==r)	{
		tree[id]=numones[l];
		return;
	}
	build(2*id,l,(l+r)/2);
	build(2*id+1,(l+r)/2+1,r);
	tree[id]=max(tree[2*id],tree[2*id+1]);
}
int query(int id,int start,int end,int l,int r)	{
	if(start>r || end<l)	{
		return -1e9;
	}
	if(start>=l && end<=r)	{
		return tree[id];
	}
	return max(query(2*id,start,(start+end)/2,l,r),query(2*id+1,(start+end)/2+1,end,l,r));
}
int main()	{
	scanf("%d %d %d",&n,&k,&p);
	for(int i=0;i<n;i++)	{
		scanf("%d",&arr[i]);
	}
	cin>>s;
	if(k>=n)	{
		int ones=0;
		for(int i=0;i<n;i++)	{
			if(arr[i]==1)	{
				ones++;
			}
		}
		for(int i=0;i<p;i++)	{
			if(s[i]=='?')	{
				printf("%d\n",ones);
			}
		}
		return 0;
	}
	precompute();
	build();
	int l,r;
	int mod=0;
	int ans;
	for(int i=0;i<p;i++)	{
		if(s[i]=='!')	{
			mod++;
			mod%=n;
		}
		else	{
			r=n-1-mod;
			l=k-1-mod;
			if(l>=0)	{
				ans=query(1,0,n-1,l,r);
			}
			else	{
				ans=max(query(1,0,n-1,0,r),query(1,0,n-1,n+l,n-1));
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
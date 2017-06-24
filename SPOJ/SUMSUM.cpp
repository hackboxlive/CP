#include <bits/stdc++.h>
using namespace std;
int arr[100100][32];
int tree[400400][32];
void build_tree(int id,int l,int r,int i)	{
	if(l==r)	{
		tree[id][i]=arr[l][i];
		return;
	}
	build_tree(2*id,l,(l+r)/2,i);
	build_tree(2*id+1,(l+r)/2+1,r,i);
	tree[id][i]=tree[2*id][i]+tree[2*id+1][i];
	return;
}
void update_tree(int id,int l,int r,int pos,int val,int i)	{
	if(l>pos || r<pos)	{
		return;
	}
	if(l==pos && r==pos)	{
		tree[id][i]=val;
		return;
	}
	update_tree(2*id,l,(l+r)/2,pos,val,i);
	update_tree(2*id+1,(l+r)/2+1,r,pos,val,i);
	tree[id][i]=tree[2*id][i]+tree[2*id+1][i];
	return;
}
int query_tree(int id,int start,int end,int l,int r,int i)	{
	if(start>r || end <l)	{
		return 0;
	}
	if(start>=l && end<=r)	{
		return tree[id][i];
	}
	return query_tree(2*id,start,(start+end)/2,l,r,i)+query_tree(2*id+1,(start+end)/2+1,end,l,r,i);
}
int main()	{
	int n,m;
	int num;
	int l,r;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)	{
		l=31;
		scanf("%d",&num);
		while(num>0)	{
			arr[i][l]=num%2;
			num=num/2;
			l--;
		}
	}
	for(int i=0;i<32;i++)	{
		build_tree(1,0,n-1,i);
	}
	int ch,b;
	string s;
	long long int sum_array[32];
	long long int value;
	while(m--)	{
		scanf("%d",&ch);
		if(ch==1)	{
			scanf("%d%d",&l,&r);
			for(int i=31;i>=0;i--)	{
				b=l%2;
				update_tree(1,0,n-1,r-1,b,i);
				l=l/2;
			}
		}
		else	{
			memset(sum_array,0,sizeof(sum_array));
			cin>>s;
			scanf("%d%d",&l,&r);
			for(int i=31;i>=0;i--)	{
				sum_array[i]=query_tree(1,0,n-1,l-1,r-1,i);
			}
			if(s[0]=='O')	{
				for(int i=31;i>=0;i--)	{
					sum_array[i]=(r-l+1)*sum_array[i]-sum_array[i]*(sum_array[i]+1)/2;
				}
			}
			if(s[0]=='A')	{
				for(int i=31;i>=0;i--)	{
					sum_array[i]=sum_array[i]*(sum_array[i]-1)/2;
				}
			}
			if(s[0]=='X')	{
				for(int i=31;i>=0;i--)	{
					sum_array[i]=((r-l+1)-sum_array[i])*sum_array[i];
				}
			}
			value=0;
			long long int two=1;
			for(int i=31;i>0;i--)	{
				sum_array[i-1]+=sum_array[i]/2;
				value=value+two*(sum_array[i]%2);
				two=two*2;
			}
			while(sum_array[0]!=0)	{
				value=value+two*(sum_array[0]%2);
				sum_array[0]/=2;
				two=two*2;
			}
			printf("%lld\n",value);
		}
	}
	return 0;
}

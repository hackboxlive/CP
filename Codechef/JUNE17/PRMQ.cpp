#include <bits/stdc++.h>
using namespace std;
int pc[1001000];
int head[100100];
int arr[100100];
int ctr=0;
vector<int> primes;
struct node	{
	int val;
	int left;
	int right;
}tree[20001000];
vector<vector<int> > factors(100100);
void sieve()	{
	for(int i=2;i<1001000;i++)	{
		if(pc[i]==0)	{
			primes.push_back(i);
			for(int j=i;j<1001000;j+=i)	{
				if(pc[j]==0)	{
					pc[j]=i;
				}
			}
		}
	}
}
void cfactors(int i)	{
	int temp=arr[i];
	while(temp>1)	{
		factors[i].push_back(pc[temp]);
		temp=temp/pc[temp];
	}
}
int searchid(int val)	{
	int lo=0;
	int mid;
	int hi=(int)primes.size()-1;
	while(lo<=hi)	{
		mid=(lo+hi)/2;
		if(primes[mid]==val)	{
			return mid;
		}
		else if(primes[mid]>val)	{
			hi=mid-1;
		}
		else	{
			lo=mid+1;
		}
	}
}
int searchid2(int val)	{
	int pos=upper_bound(primes.begin(),primes.end(),val)-primes.begin();
	pos--;
	return pos;
}
int searchid3(int val)	{
	int pos=lower_bound(primes.begin(),primes.end(),val)-primes.begin();
	return pos;
}
void build(int id,int l,int r)	{
	if(l==r)	{
		tree[id].val=0;
		return;
	}
	tree[id].left=ctr;
	ctr++;
	build(tree[id].left,l,(l+r)/2);
	tree[id].right=ctr;
	ctr++;
	build(tree[id].right,(l+r)/2+1,r);
	tree[id].val=0;
}
void persistent(int id,int l,int r,int pos,int par)	{
	if(l==pos && r==pos)	{
		tree[id].val=tree[par].val+1;
		return;
	}
	if(pos<=(l+r)/2)	{
		tree[id].right=tree[par].right;
		tree[id].left=ctr;
		ctr++;
		persistent(tree[id].left,l,(l+r)/2,pos,tree[par].left);
	}
	else	{
		tree[id].left=tree[par].left;
		tree[id].right=ctr;
		ctr++;
		persistent(tree[id].right,(l+r)/2+1,r,pos,tree[par].right);
	}
	tree[id].val=tree[tree[id].left].val+tree[tree[id].right].val;
}
int query(int id,int start,int end,int l,int r)	{
	if(start>r || end<l)	{
		return 0;
	}
	if(start>=l && end<=r)	{
		return tree[id].val;
	}
	return query(tree[id].left,start,(start+end)/2,l,r)+query(tree[id].right,(start+end)/2+1,end,l,r);
}
int main()	{
	sieve();
	int n,q;
	cin>>n;
	for(int i=1;i<=n;i++)	{
		cin>>arr[i];
		cfactors(i);
	}
	int pos;
	int ps=(int)primes.size();
	head[0]=ctr;
	ctr++;
	int prev=0;
	build(head[0],0,ps-1);
	for(int i=1;i<=n;i++)	{
		for(int j=0;j<factors[i].size();j++)	{	
			head[i]=ctr;
			ctr++;
			pos=searchid(factors[i][j]);
			persistent(head[i],0,ps-1,pos,prev);
			prev=head[i];
		}
	}
	int pos1,pos2;
	int l,r,x,y,ans;
	cin>>q;
	while(q--)	{
		cin>>l>>r>>x>>y;
		pos1=searchid3(x);
		pos2=searchid2(y);
		ans=query(head[r],0,ps-1,pos1,pos2)-query(head[l-1],0,ps-1,pos1,pos2);
		cout<<ans<<endl;
	}
	return 0;
}
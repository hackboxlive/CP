#include <stdio.h>
using namespace std;
struct node	{
	int l,r,lid,rid;
	node()	{
		l=0;
		r=0;
		lid=-1;
		rid=-1;
	}
};
int id;
void insert(node * trie,int val,int index,int depth)	{
	for(int i=depth-1;i>=0;i--)	{
		int bit=(val>>i) & 1;
		if(bit==1)	{
			trie[index].r++;
			if(trie[index].rid==-1)	{
				trie[index].rid=++id;
				index=id;
			}
			else	{
				index=trie[index].rid;
			}
		}
		else	{
			trie[index].l++;
			if(trie[index].lid==-1)	{
				trie[index].lid=++id;
				index=id;
			}
			else	{
				index=trie[index].lid;
			}
		}
	}
}
int query(node * trie,int val,int k,int index,int depth)	{
	int ans=0;
	for(int i=depth-1;i>=0;i--)	{
		int valbit=(val>>i) & 1;
		int compbit=(k>>i) & 1;
		if(compbit==1)	{
			if(valbit==1)	{
				ans=ans+trie[index].r;
				index=trie[index].lid;
			}
			else	{
				ans=ans+trie[index].l;
				index=trie[index].rid;
			}
		}
		else	{
			if(valbit==1)	{
				index=trie[index].rid;
			}
			else	{
				index=trie[index].lid;
			}
		}
		if(index==-1)	{
			break;
		}
	}
	return ans;
}
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		id=0;
		node trie[200000];
		int n,k;
		scanf("%d%d",&n,&k);
		int present_xor=0;
		long long int ans=0;
		int num;
		insert(trie,0,0,20);
		while(n--)	{
			scanf("%d",&num);
			present_xor=present_xor^num;
			ans=ans+query(trie,present_xor,k,0,20);
			insert(trie,present_xor,0,20);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
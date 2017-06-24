#include <bits/stdc++.h>
using namespace std;
const int maxv=1e5;
struct hash_function	{
	long long summation;
	long long squares;
	int xor_value;
};
struct node	{
	int count;
	hash_function hash_value;
	int left;
	int right;
}tree_prefix[2000000],trees_suffix[2000000];
int headp_prefix[100100],headp_suffix[100100];
int ctr_prefix,ctr_suffix;
int arr[100100];
void build_p(int id,int l,int r)	{
	if(l==r)	{
		tree_prefix[id].count=0;
		tree_prefix[id].hash_value.summation=0;
		tree_prefix[id].hash_value.squares=0;
		tree_prefix[id].hash_value.xor_value=0;
		return;
	}
	tree_prefix[id].left=ctr_prefix;
	ctr_prefix++;
	build_p(tree_prefix[id].left,l,(l+r)/2);
	tree_prefix[id].right=ctr_prefix;
	ctr_prefix++;
	build_p(tree_prefix[id].right,(l+r)/2+1,r);
	tree_prefix[id].count=0;
	tree_prefix[id].hash_value.summation=0;
	tree_prefix[id].hash_value.squares=0;
	tree_prefix[id].hash_value.xor_value=0;
}
void persistent_p(int id,int l,int r,int pos,int par)	{
	if(l==pos && r==pos)	{
		tree_prefix[id].count=tree_prefix[par].count+1;
		tree_prefix[id].hash_value.summation=tree_prefix[par].hash_value.summation+l;
		tree_prefix[id].hash_value.squares=tree_prefix[par].hash_value.squares+(long long)l*l;
		tree_prefix[id].hash_value.xor_value=tree_prefix[par].hash_value.xor_value^l;
		return;
	}
	if(pos<=(l+r)/2)	{
		tree_prefix[id].right=tree_prefix[par].right;
		tree_prefix[id].left=ctr_prefix;
		ctr_prefix++;
		persistent_p(tree_prefix[id].left,l,(l+r)/2,pos,tree_prefix[par].left);
	}
	else	{
		tree_prefix[id].left=tree_prefix[par].left;
		tree_prefix[id].right=ctr_prefix;
		ctr_prefix++;
		persistent_p(tree_prefix[id].right,(l+r)/2+1,r,pos,tree_prefix[par].right);
	}
	tree_prefix[id].count=tree_prefix[tree_prefix[id].left].count+tree_prefix[tree_prefix[id].right].count;
	tree_prefix[id].hash_value.summation=tree_prefix[tree_prefix[id].left].hash_value.summation+tree_prefix[tree_prefix[id].right].hash_value.summation;
	tree_prefix[id].hash_value.squares=tree_prefix[tree_prefix[id].left].hash_value.squares+tree_prefix[tree_prefix[id].right].hash_value.squares;
	tree_prefix[id].hash_value.xor_value=tree_prefix[tree_prefix[id].left].hash_value.xor_value^tree_prefix[tree_prefix[id].right].hash_value.xor_value;
}
hash_function hashp(int id,int l,int r,int pos,int par)	{
	if(l==r)	{
		hash_function h;
		h.summation=pos*l;
		h.squares=pos*(long long)l*l;
		if(pos%2==0)	{
			h.xor_value=0;
		}
		else	{
			h.xor_value=l;
		}
		return h;
	}
	if(tree_prefix[tree_prefix[id].left].count-tree_prefix[tree_prefix[par].left].count>=pos)	{
		return hashp(tree_prefix[id].left,l,(l+r)/2,pos,tree_prefix[par].left);
	}
	hash_function h;
	h.summation=tree_prefix[tree_prefix[id].left].hash_value.summation-tree_prefix[tree_prefix[par].left].hash_value.summation;
	h.squares=tree_prefix[tree_prefix[id].left].hash_value.squares-tree_prefix[tree_prefix[par].left].hash_value.squares;
	h.xor_value=tree_prefix[tree_prefix[id].left].hash_value.xor_value^tree_prefix[tree_prefix[par].left].hash_value.xor_value;
	hash_function oh=hashp(tree_prefix[id].right,(l+r)/2+1,r,pos-(tree_prefix[tree_prefix[id].left].count-tree_prefix[tree_prefix[par].left].count),tree_prefix[par].right);
	h.summation+=oh.summation;
	h.squares+=oh.squares;
	h.xor_value^=oh.xor_value;
	return h;
}
void build_s(int id,int l,int r)	{
	if(l==r)	{
		trees_suffix[id].count=0;
		trees_suffix[id].hash_value.summation=0;
		trees_suffix[id].hash_value.squares=0;
		trees_suffix[id].hash_value.xor_value=0;
		return;
	}
	trees_suffix[id].left=ctr_suffix;
	ctr_suffix++;
	build_s(trees_suffix[id].left,l,(l+r)/2);
	trees_suffix[id].right=ctr_suffix;
	ctr_suffix++;
	build_s(trees_suffix[id].right,(l+r)/2+1,r);
	trees_suffix[id].count=0;
	trees_suffix[id].hash_value.summation=0;
	trees_suffix[id].hash_value.squares=0;
	trees_suffix[id].hash_value.xor_value=0;
}
void persistent_s(int id,int l,int r,int pos,int par)	{
	if(l==pos && r==pos)	{
		trees_suffix[id].count=trees_suffix[par].count+1;
		trees_suffix[id].hash_value.summation=trees_suffix[par].hash_value.summation+l;
		trees_suffix[id].hash_value.squares=trees_suffix[par].hash_value.squares+(long long)l*l;
		trees_suffix[id].hash_value.xor_value=trees_suffix[par].hash_value.xor_value^l;
		return;
	}
	if(pos<=(l+r)/2)	{
		trees_suffix[id].right=trees_suffix[par].right;
		trees_suffix[id].left=ctr_suffix;
		ctr_suffix++;
		persistent_s(trees_suffix[id].left,l,(l+r)/2,pos,trees_suffix[par].left);
	}
	else	{
		trees_suffix[id].left=trees_suffix[par].left;
		trees_suffix[id].right=ctr_suffix;
		ctr_suffix++;
		persistent_s(trees_suffix[id].right,(l+r)/2+1,r,pos,trees_suffix[par].right);
	}
	trees_suffix[id].count=trees_suffix[trees_suffix[id].left].count+trees_suffix[trees_suffix[id].right].count;
	trees_suffix[id].hash_value.summation=trees_suffix[trees_suffix[id].left].hash_value.summation+trees_suffix[trees_suffix[id].right].hash_value.summation;
	trees_suffix[id].hash_value.squares=trees_suffix[trees_suffix[id].left].hash_value.squares+trees_suffix[trees_suffix[id].right].hash_value.squares;
	trees_suffix[id].hash_value.xor_value=trees_suffix[trees_suffix[id].left].hash_value.xor_value^trees_suffix[trees_suffix[id].right].hash_value.xor_value;
}
hash_function hashs(int id,int l,int r,int pos,int par)	{
	if(l==r)	{
		hash_function h;
		h.summation=pos*l;
		h.squares=pos*(long long)l*l;
		if(pos%2==0)	{
			h.xor_value=0;
		}
		else	{
			h.xor_value=l;
		}
		return h;
	}
	if(trees_suffix[trees_suffix[id].right].count-trees_suffix[trees_suffix[par].right].count>=pos)	{
		return hashs(trees_suffix[id].right,(l+r)/2+1,r,pos,trees_suffix[par].right);
	}
	hash_function h;
	h.summation=trees_suffix[trees_suffix[id].right].hash_value.summation-trees_suffix[trees_suffix[par].right].hash_value.summation;
	h.squares=trees_suffix[trees_suffix[id].right].hash_value.squares-trees_suffix[trees_suffix[par].right].hash_value.squares;
	h.xor_value=trees_suffix[trees_suffix[id].right].hash_value.xor_value^trees_suffix[trees_suffix[par].right].hash_value.xor_value;
	hash_function oh=hashs(trees_suffix[id].left,l,(l+r)/2,pos-(trees_suffix[trees_suffix[id].right].count-trees_suffix[trees_suffix[par].right].count),trees_suffix[par].left);
	h.summation+=oh.summation;
	h.squares+=oh.squares;
	h.xor_value^=oh.xor_value;
	return h;
}
int main()	{
	int n,q,t,flag;
	cin>>t;
	int l1,r1,l2,r2;
	int lo,hi,mid;
	hash_function p1,p2,s1,s2;
	while(t--)	{
		cin>>n>>q;
		for(int i=1;i<=n;i++)	{
			cin>>arr[i];
		}
		ctr_prefix=0;
		headp_prefix[0]=ctr_prefix;
		ctr_prefix++;
		build_p(headp_prefix[0],1,maxv);
		for(int i=1;i<=n;i++)	{
			headp_prefix[i]=ctr_prefix;
			ctr_prefix++;
			persistent_p(headp_prefix[i],1,maxv,arr[i],headp_prefix[i-1]);
		}
		ctr_suffix=0;
		headp_suffix[n+1]=ctr_suffix;
		ctr_suffix++;
		build_s(headp_suffix[n+1],1,maxv);
		for(int i=n;i>=1;i--)	{
			headp_suffix[i]=ctr_suffix;
			ctr_suffix++;
			persistent_s(headp_suffix[i],1,maxv,arr[i],headp_suffix[i+1]);
		}
		while(q--)	{
			flag=0;
			cin>>l1>>r1>>l2>>r2;
			lo=1;
			hi=r1-l1+1;
			while(lo<=hi)	{
				mid=(lo+hi)/2;
				p1=hashp(headp_prefix[r1],1,maxv,mid-1,headp_prefix[l1-1]);
				p2=hashp(headp_prefix[r2],1,maxv,mid-1,headp_prefix[l2-1]);
				s1=hashs(headp_suffix[l1],1,maxv,(r1-l1+1)-mid,headp_suffix[r1+1]);
				s2=hashs(headp_suffix[l2],1,maxv,(r1-l1+1)-mid,headp_suffix[r2+1]);
				if(p1.summation==p2.summation && p1.squares==p2.squares && p1.xor_value==p2.xor_value)	{
					if(s1.summation==s2.summation && s1.squares==s2.squares && s1.xor_value==s2.xor_value)	{
						flag=1;
						break;
					}
					else	{
						lo=mid+1;
					}
				}
				else	{
					if(s1.summation==s2.summation && s1.squares==s2.squares && s1.xor_value==s2.xor_value)	{
						hi=mid-1;
					}
					else	{
						flag=0;
						break;
					}
				}
			}
			if(flag==1)	{
				cout<<"YES\n";
			}
			else	{
				cout<<"NO\n";
			}
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int hb[200200];
int shb[200200];
int arr[200200];
int que[200200];
int ranks[200200];
struct node	{
	int rank;
	int pp;
}tree[2002000];
void merge_node(int id)	{
	if(tree[2*id].rank==-1)	{
		if(tree[2*id+1].rank==-1)	{
			tree[id].rank=-1;
			tree[id].pp=-1;
		}
		else	{
			tree[id].rank=tree[2*id+1].rank;
			tree[id].pp=tree[2*id+1].pp;
		}
	}
	else	{
		if(tree[2*id+1].rank==-1)	{
			tree[id].rank=tree[2*id].rank;
			tree[id].pp=tree[2*id].pp;			
		}
		else	{
			if(tree[2*id].rank<tree[2*id+1].rank)	{
				tree[id].rank=tree[2*id].rank;
				tree[id].pp=tree[2*id].pp;
			}
			else	{
				tree[id].rank=tree[2*id+1].rank;
				tree[id].pp=tree[2*id+1].pp;
			}
		}
	}
}
void build_tree(int id,int l,int r)	{
	if(l==r)	{
		tree[id].rank=ranks[l];
		tree[id].pp=l;
		return;
	}
	build_tree(2*id,l,(l+r)/2);
	build_tree(2*id+1,(l+r)/2+1,r);
	merge_node(id);
	return;
}
void update_tree(int id,int l,int r,int pos)	{
	if(l>pos || r<pos)	{
		return;
	}
	if(l==pos && r==pos)	{
		tree[id].rank=-1;
		return;
	}
	update_tree(2*id,l,(l+r)/2,pos);
	update_tree(2*id+1,(l+r)/2+1,r,pos);
	merge_node(id);
	return;
}
void back_update(int id,int l,int r,int pos,int val)	{
	if(l>pos || r<pos)	{
		return;
	}
	if(l==pos && r==pos)	{
		tree[id].rank=val;
		return;
	}
	back_update(2*id,l,(l+r)/2,pos,val);
	back_update(2*id+1,(l+r)/2+1,r,pos,val);
	merge_node(id);
	return;
}
int main()	{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	{
		hb[i]=-1;
		shb[i]=-1;
		ranks[i]=-1;
	}
	int pos,bid;
	for(int i=0;i<n;i++)	{
		scanf("%d%d",&pos,&bid);
		shb[pos]=hb[pos];
		hb[pos]=bid;
		arr[i]=pos;
	}
	for(int i=n-1;i>=0;i--)	{
		if(ranks[arr[i]]==-1)	{
			ranks[arr[i]]=n-i;
		}
	}
	int q,hr,hrf,srf;
	set<int> st;
	build_tree(1,1,n);
	scanf("%d",&q);
	while(q--)	{
		scanf("%d",&bid);
		for(int i=0;i<bid;i++)	{
			scanf("%d",&que[i]);
		}
		for(int i=0;i<bid;i++)	{
			update_tree(1,1,n,que[i]);
		}
				for(int i=1;i<=15;i++)	{
					cout<<tree[i].pp<<" "<<tree[i].rank<<"\n";
				}
				cout<<endl;
		hr=tree[1].pp;
		if(hr==-1 || hb[hr]==-1)	{
			cout<<"0 0\n";
		}
		else	{
			hrf=hb[hr];
			srf=shb[hr];
			if(srf==-1)	{
				cout<<hr<<" "<<hrf<<endl;
			}
			else	{
				for(int i=0;i<bid;i++)	{
					if(hb[que[i]]>hrf && hb[que[i]]<srf)	{
						st.insert(hb[que[i]]);
					}
				}
				if(st.size()==srf-hrf-1)	{
					cout<<hr<<" "<<srf<<endl;
				}
				else	{
					cout<<hr<<" "<<hrf<<endl;
				}
				st.clear();
			}
		}
		for(int i=0;i<bid;i++)	{
			back_update(1,1,n,que[i],ranks[que[i]]);
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
struct node	{
	int type;
	int l;
	int r;
}query[100100];
long long tree[600600];
long long qtree[600600];
const long long modd=1e9+7;
void build_qtree(int id,int l,int r)	{
	if(l==r)	{
		qtree[id]=1;
		return;
	}
	build_qtree(2*id,l,(l+r)/2);
	build_qtree(2*id+1,(l+r)/2+1,r);
	qtree[id]=0;
}
void build_tree(int id,int l,int r)	{
	if(l==r)	{
		tree[id]=0;
//		cout<<"putting at "<<l<<" = 0\n";
		return;
	}
	build_tree(2*id,l,(l+r)/2);
	build_tree(2*id+1,(l+r)/2+1,r);
	tree[id]=0;
}
void update_tlazy(int id,int l,int r)	{
	if(tree[id]!=0)	{
		if(l!=r)	{
			tree[2*id]+=tree[id];
			tree[2*id+1]+=tree[id];
			tree[2*id]%=modd;
			tree[2*id+1]%=modd;
			tree[id]=0;
		}
	}
}
void update_qlazy(int id,int l,int r)	{
	if(qtree[id]!=0)	{
		if(l!=r)	{
			qtree[2*id]+=qtree[id];
			qtree[2*id]%=modd;
			qtree[2*id+1]+=qtree[id];
			qtree[2*id+1]%=modd;
			qtree[id]=0;
		}
	}
}
void update_q(int id,int st,int en,int l,int r,long long loop)	{
	update_qlazy(id,st,en);
	if(st>r || en<l)	{
		return;
	}
	if(st>=l && en<=r)	{
		qtree[id]+=loop;
		qtree[id]%=modd;
		return;
	}
	update_q(2*id,st,(st+en)/2,l,r,loop);
	update_q(2*id+1,(st+en)/2+1,en,l,r,loop);
}
void update_t(int id,int st,int en,int l,int r,long long loop)	{
	update_tlazy(id,st,en);
	if(st>r || en<l)	{
		return;
	}
	if(st>=l && en<=r)	{
		tree[id]+=loop;
		tree[id]%=modd;
		return;
	}
	update_t(2*id,st,(st+en)/2,l,r,loop);
	update_t(2*id+1,(st+en)/2+1,en,l,r,loop);
}
long long query_q(int id,int l,int r,int pos)	{
	update_qlazy(id,l,r);
	if(pos==l && pos==r)	{
		return qtree[id];
	}
	if((l+r)/2<pos)	{
		return query_q(2*id+1,(l+r)/2+1,r,pos);
	}
	else	{
		return query_q(2*id,l,(l+r)/2,pos);
	}
}
long long query_t(int id,int l,int r,int pos)	{
	update_tlazy(id,l,r);
	if(pos==l && pos==r)	{
		return tree[id];
	}
	if((l+r)/2<pos)	{
		return query_t(2*id+1,(l+r)/2+1,r,pos);
	}
	else	{
		return query_t(2*id,l,(l+r)/2,pos);
	}
}
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		int n,m,x,y,z;
		scanf("%d %d",&n,&m);
		for(int i=0;i<m;i++)	{
			scanf("%d %d %d",&x,&y,&z);
			y--;z--;
			query[i].type=x;
			query[i].l=y;
			query[i].r=z;
		}
		long long loop;
//		cout<<"HERE";
		build_qtree(1,0,m-1);
		build_tree(1,0,n-1);
	// 		for(int i=0;i<n;i++)	{
	// 			printf("%lld ",query_t(1,0,n-1,i));
	// //			cout<<query_t(1,0,n-1,i)<<" ";
	// 		}
	// 		printf("\n");
		for(int i=m-1;i>=0;i--)	{
			if(query[i].type==1)	{
				loop=query_q(1,0,m-1,i);
//				cout<<loop<<" df"<<endl;
				update_t(1,0,n-1,query[i].l,query[i].r,loop);
			}
			else	{
				loop=query_q(1,0,m-1,i);
//				cout<<loop<<endl;
				update_q(1,0,m-1,query[i].l,query[i].r,loop);
			}
			// for(int j=0;j<m;j++)	{
			// 	cout<<query_q(1,0,m-1,j)<<" ";
			// }
			// cout<<endl;
	// 		for(int i=0;i<n;i++)	{
	// 			printf("%lld ",query_t(1,0,n-1,i));
	// //			cout<<query_t(1,0,n-1,i)<<" ";
	// 		}
	// 		printf("\n");
		}
		for(int i=0;i<n;i++)	{
			printf("%lld ",query_t(1,0,n-1,i));
//			cout<<query_t(1,0,n-1,i)<<" ";
		}
		printf("\n");
	}
	return 0;
}
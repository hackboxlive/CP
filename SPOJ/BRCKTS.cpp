#include <bits/stdc++.h>
using namespace std;
string s;
struct node	{
	int op;
	int cl;
}tree[120000];
void build_tree(int id,int l,int r)	{
	if(l==r)	{
		if(s[l]=='(')	{
			tree[id].op=1;
			tree[id].cl=0;
		}
		else	{
			tree[id].op=0;
			tree[id].cl=1;
		}
		return;
	}
	build_tree(2*id,l,(l+r)/2);
	build_tree(2*id+1,(l+r)/2+1,r);
	int matches=min(tree[2*id].op,tree[2*id+1].cl);
	tree[id].op=tree[2*id].op+tree[2*id+1].op-matches;
	tree[id].cl=tree[2*id].cl+tree[2*id+1].cl-matches;
	return;
}
void update(int id,int l,int r,int pos)	{
	if(l>pos || r<pos)	{
		return;
	}
	if(l==pos && r==pos)	{
		if(tree[id].op==1)	{
			tree[id].cl=1;
			tree[id].op=0;
		}
		else	{
			tree[id].op=1;
			tree[id].cl=0;
		}
		return;
	}
	update(2*id,l,(l+r)/2,pos);
	update(2*id+1,(l+r)/2+1,r,pos);
	int matches=min(tree[2*id].op,tree[2*id+1].cl);
	tree[id].op=tree[2*id].op+tree[2*id+1].op-matches;
	tree[id].cl=tree[2*id].cl+tree[2*id+1].cl-matches;
	return;
}
int main()	{
	for(int tc=1;tc<=10;tc++)	{
		int n;
		scanf("%d",&n);
		cin>>s;
		printf("Test %d:\n",tc);
		build_tree(1,0,n-1);
//		for(int i=1;i<=7;i++)	{
//			cout<<tree[i].op<<" "<<tree[i].cl<<endl;
//		}
		int m,ch;
		scanf("%d",&m);
		int t=m;
		while(m--)	{
			scanf("%d",&ch);
			if(ch==0)	{
				if(tree[1].op==0 && tree[1].cl==0)	{
					printf("YES\n");
				}
				else	{
					printf("NO\n");
				}
			}
			else	{
				update(1,0,n-1,ch-1);
//		for(int i=1;i<=7;i++)	{
//			cout<<tree[i].op<<" "<<tree[i].cl<<endl;
//		}
			}
		}
	}
	return 0;
}
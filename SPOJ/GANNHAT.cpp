#include <bits/stdc++.h>
#define MOD 2
using namespace std;
int n;
vector<pair<int,int> > arr;
vector<int> min_dist;
struct node	{
	int x;
	int y;
	node * left;
	node * right;
} *start,*temp,*p;
void build_tree()	{
	start=new node();
	start->x=arr[0].first;
	start->y=arr[0].second;
	start->left=NULL;
	start->right=NULL;
	for(int i=1;i<n;i++)	{
		temp=new node();
		temp->x=arr[i].first;
		temp->y=arr[i].second;
		int depth=0;
		p=start;
		while(true)	{
			if(depth==0)	{
				if(temp->x < p->x)	{
					if(p->left == NULL)	{
						p->left=temp;
						break;
					}
					p=p->left;
				}
				else	{
					if(p->right == NULL)	{
						p->right=temp;
						break;
					}
					p=p->right;
				}
			}
			else	{
				if(temp->y < p->y)	{
					if(p->left == NULL)	{
						p->left=temp;
						break;
					}
					p=p->left;
				}
				else	{
					if(p->right == NULL)	{
						p->right=temp;
						break;
					}
					p=p->right;
				}
			}
			depth++;
			depth=depth%MOD;
		}
	}
	return;
}
void query_tree(node * q)	{
	if(q==NULL)	{
		return;
	}

}
int main()	{
	scanf("%d",&n);
	int x,y;
	for(int i=0;i<n;i++)	{
		scanf("%d%d",&x,&y);
		arr.push_back(make_pair(x,y));
	}
	build_tree();
	for(int i=0;i<n;i++)	{
		query_tree()
	}
//	print_tree(start);
}
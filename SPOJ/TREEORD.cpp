#include <bits/stdc++.h>
using namespace std;
struct arr	{
	int val;
	int pos;
}inorder[10000],preorder[10000],postorder[10000];
int n;
vector<int> new_post;
bool comp(const arr &p1,const arr &p2)	{
	return p1.val<p2.val;
}
struct node	{
	int val;
	int id;
	node * left;
	node * right;
} *start,*temp;
void create_tree()	{
	start=new node();
	start->val=preorder[0].val;
	start->id=inorder[start->val-1].pos;
	start->left=NULL;
	start->right=NULL;
	for(int i=1;i<n;i++)	{
		int value=preorder[i].val;
//		cout<<value<<endl;
		int position=inorder[value-1].pos;
//		cout<<position<<endl;
		temp=new node();
		temp->val=value;
		temp->id=position;
		node * p=start;
		while(true)	{
//			cout<<p->val<<" ";
			if(temp->id < p->id)	{
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
//		cout<<endl;
	}
	return;
}
void print_postorder(node * p)	{
	if(p==NULL)	{
		return;
	}
	print_postorder(p->left);
	print_postorder(p->right);
	new_post.push_back(p->val);
//	printf("%d ",p->val);
	return;
}
int main()	{
	scanf("%d",&n);
	int num;
	for(int i=0;i<n;i++)	{
		scanf("%d",&num);
		preorder[i].val=num;
		preorder[i].pos=i+1;
	}
	for(int i=0;i<n;i++)	{
		scanf("%d",&num);
		postorder[i].val=num;
		postorder[i].pos=i+1;
	}
	for(int i=0;i<n;i++)	{
		scanf("%d",&num);
		inorder[i].val=num;
		inorder[i].pos=i+1;
	}
	sort(inorder,inorder+n,comp);
//	for(int i=0;i<n;i++)	{
//		cout<<inorder[i].val<<" "<<inorder[i].pos<<endl;
//	}
	start=NULL;
	create_tree();
	print_postorder(start);
	int flag=0;
	for(int i=0;i<n;i++)	{
		if(new_post[i]!=postorder[i].val)	{
			flag=1;
			break;
		}
	}
	if(flag==0)	{
		printf("yes\n");
	}
	else	{
		printf("no\n");
	}
	return 0;
}
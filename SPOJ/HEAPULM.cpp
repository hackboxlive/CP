#include <bits/stdc++.h>
using namespace std;
vector<pair<int,string> > nodes;
bool comp(const pair<int,string> &p1,const pair<int,string> &p2)	{
	return p1.first>p2.first;
}
struct treenode	{
	int priority;
	string label;
	treenode * left;
	treenode * right;
}*root;
void dfs_printing(treenode * p)	{
	if(p!=NULL)	{
		printf("(");
		dfs_printing(p->left);
		printf("%s/%d",(p->label).c_str(),p->priority);
		dfs_printing(p->right);
		printf(")");
	}
	return;
}
int main()	{
	int n;
	int k;
	char str[100];
	int s;
	scanf("%d",&n);
	while(n!=0)	{
		nodes.clear();
		for(int i=0;i<n;i++)	{
			scanf("%s",str);
			s=0;
			nodes.push_back(make_pair(0,""));
			for(k=0;k<strlen(str);k++)	{
				if(str[k]=='/')	{
					break;
				}
				else	{
					nodes[i].second+=str[k];
				}
			}
			for(k=k+1;k<strlen(str);k++)	{
				s=s*10+(str[k]-'0');
			}
			nodes[i].first=s;
		}
		sort(nodes.begin(),nodes.end(),comp);
		treenode * q=new treenode();
		q->priority=nodes[0].first;
		q->label=nodes[0].second;
		q->left=NULL;
		q->right=NULL;
		root=q;
		for(int i=1;i<n;i++)	{
			treenode * p=new treenode();
			p->priority=nodes[i].first;
			p->label=nodes[i].second;
			p->left=NULL;
			p->right=NULL;
			treenode * temp=root;
			treenode * prev;
			while(temp!=NULL)	{
				if(((temp->label).compare(p->label))>0)	{
					prev=temp;
					temp=temp->left;
				}
				else	{
					prev=temp;
					temp=temp->right;
				}
			}
			if(((prev->label).compare(p->label))>0)	{
				prev->left=p;
			}
			else	{
				prev->right=p;
			}
		}
		dfs_printing(root);
		printf("\n");
		scanf("%d",&n);
	}
	return 0;
}
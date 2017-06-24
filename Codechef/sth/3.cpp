#include <bits/stdc++.h>
using namespace std;
int arr[1001000];
struct node	{
	int color[11];
}tree[17][600000];
void build_tree(int id,int l,int r,int num)	{
	if(l==r)	{
		tree[num][id].color[arr[l]]=1;
		return;
	}
	build_tree(2*id,l,(l+r)/2,num);
	build_tree(2*id+1,(l+r)/2+1,r,num);
	for(int i=1;i<=10;i++)	{
		if(tree[num][2*id].color[i]==1 || tree[num][2*id+1].color[i]==1)	{
			tree[num][id].color[i]=1;
		}
	}
	return;
}
node query_tree(int id,int start,int end,int l,int r,int level)	{
	if(start>r || end<l)	{
		node nullnode;
		for(int i=0;i<11;i++)	{
			nullnode.color[i]=0;
		}
		return nullnode;
	}
	if(start>=l && end<=r)	{
		return tree[level][id];
	}
	node p=query_tree(2*id,start,(start+end)/2,l,r,level);
	node q=query_tree(2*id+1,(start+end)/2+1,end,l,r,level);
	node rr;
	for(int i=0;i<11;i++)	{
		if(p.color[i]==1 || q.color[i]==1)	{
			rr.color[i]=1;
		}
	}
	return rr;
}
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)	{
			scanf("%d",&arr[i]);
		}
		for(int i=0;i<17;i++)	{
			int lowval=pow(2,i);
			int upval=pow(2,i+1)-1;
			if(upval>=n)	{
				upval=n;
				build_tree(1,lowval,upval,i);
				break;
			}
			build_tree(1,lowval,upval,i);
		}
		int q,nodekk,k;
		scanf("%d",&q);
		while(q--)	{
			scanf("%d %d",&nodekk,&k);
			int numlevel=(int)log2(nodekk);
			int anscol[11];
			anscol[arr[nodekk]]=1;
			int answer=1;
			int levelrn=numlevel;
			int node1=nodekk;
			int node2=nodekk;
			if(answer==k)	{
				printf("0\n");
				continue;
			}
			while(answer<k)	{
				levelrn++;
				int lnode=2*node1;
				int rnode=2*node2+1;
				if(rnode>n&&lnode>n)	{
					printf("-1\n");
					break;
				}
//				cout<<lnode<<" "<<rnode<<endl;
				node ass=query_tree(1,pow(2,levelrn),pow(2,levelrn+1)-1,lnode,rnode,levelrn);
				for(int i=1;i<11;i++)	{
					if(ass.color[i]==1)	{
						answer++;
						anscol[i]=1;
					}
				}
				if(answer>=k)	{
					printf("%d\n",levelrn-numlevel);
					break;
				}
				else if(rnode==n)	{
					break;
				}
				else	{
					node1=node1*2;
					node2=node2*2+1;
					continue;
				}
			}
		}
		for(int i=0;i<17;i++)	{
			for(int j=1;j<600000;j++)	{
				for(int k=1;k<=10;k++)	{
					tree[i][j].color[k]=0;
				}
			}
		}
	}
	return 0;
}
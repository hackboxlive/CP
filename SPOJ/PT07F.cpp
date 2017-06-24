#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > tree(10100);
int dp[10100][2];
struct node	{
	int nnode;
	int vnode1;
	int vnode2;
}nodes[10100];
void dfs(int src,int par)	{
	if(tree[src].size()==1 && par==tree[src][0])	{	//leaf node base case
		dp[src][0]=1;
		dp[src][1]=1;
		nodes[src].vnode2=nodes[src].vnode1=nodes[src].nnode=src;
		return;
	}
	for(int i=0;i<tree[src].size();i++)	{				//apply dfs to the children
		if(tree[src][i]!=par)	{
			dfs(tree[src][i],src);
		}
	}
	if(tree[src].size()<=2)	{							//calculate dp when numberof children is 1
		if(tree[src][0]==par)	{
			if(dp[tree[src][1]][1]==-1)	{
				dp[src][0]=dp[tree[src][1]][0];
			}
			else	{
				dp[src][0]=min(dp[tree[src][1]][0],dp[tree[src][1]][1]+1);
			}
			dp[src][1]=-1;
		}
		else	{
			if(dp[tree[src][0]][1]==-1)	{
				dp[src][0]=dp[tree[src][0]][0];
			}
			else	{
				dp[src][0]=min(dp[tree[src][0]][0],dp[tree[src][0]][1]+1);
			}
			dp[src][1]=-1;
		}
		return;
	}
	bool vexist=true;
	for(int i=0;i<tree[src].size();i++)	{		//knowing if v exist for all children or not
		if(dp[tree[src][i]][1]==-1 && tree[src][i]!=par)	{
			vexist=false;
			break;
		}
	}
	int val=0;
	if(vexist==false)	{
		for(int i=0;i<tree[src].size();i++)	{
			if(tree[src][i]!=par)	{
				if(dp[tree[src][i]][1]==-1)	{
					val+=dp[tree[src][i]][0];
				}
				else	{
					val+=min(dp[tree[src][i]][0],dp[tree[src][i]][1]);
				}
			}
		}
		dp[src][0]=val;
	}
	else	{
		bool flag=true;
		for(int i=0;i<tree[src].size();i++)	{
			if(dp[tree[src][i]][0]<=dp[tree[src][i]][1] && tree[src][i]!=par)	{
				flag=false;
				break;
			}
		}
		if(flag==false)	{
			val=0;
			for(int i=0;i<tree[src].size();i++)	{
				if(tree[src][i]!=par)	{
					val+=min(dp[tree[src][i]][0],dp[tree[src][i]][1]);
				}
			}
			dp[src][0]=val;
		}
		else	{
			val=1;
			for(int i=0;i<tree[src].size();i++)	{
				if(tree[src][i]!=par)	{
					val+=dp[tree[src][i]][1];
				}
			}
			dp[src][0]=val;
		}
	}		//This was all for normal subtree
	int cngv=0;
	val=0;
	for(int i=0;i<tree[src].size();i++)	{
		if(tree[src][i]!=par && dp[tree[src][i]][1]!=-1 && dp[tree[src][i]][0]<=dp[tree[src][i]][1])	{
			cngv++;
		}
		if(tree[src][i]!=par && dp[tree[src][i]][1]==-1)	{
			cngv++;
		}
	}
	if(cngv>=2)	{
		for(int i=0;i<tree[src].size();i++)	{
			if(tree[src][i]!=par)	{
				if(dp[tree[src][i]][1]==-1)	{
					val+=dp[tree[src][i]][0];
				}
				else	{
					val+=min(dp[tree[src][i]][0],dp[tree[src][i]][1]);
				}
			}
		}
		dp[src][1]=val-1;
	}
	else if(cngv==1)	{
		int fmax;
		for(int i=0;i<tree[src].size();i++)	{
			if(tree[src][i]!=par && dp[tree[src][i]][1]!=-1 && dp[tree[src][i]][0]>dp[tree[src][i]][1])	{
				fmax=tree[src][i];
				break;
			}
		}
		for(int i=0;i<tree[src].size();i++)	{
			if(tree[src][i]!=par && dp[tree[src][i]][1]!=-1)	{
				if(dp[fmax][0]-dp[fmax][1]>dp[tree[src][i]][0]-dp[tree[src][i]][1] && dp[tree[src][i]][0]-dp[tree[src][i]][1]>0)	{
					fmax=tree[src][i];
				}
			}
		}
		for(int i=0;i<tree[src].size();i++)	{
			if(tree[src][i]!=par)	{
				if(dp[tree[src][i]][1]==-1 || fmax==tree[src][i])	{
					val+=dp[tree[src][i]][0];
				}
				else	{
					val+=min(dp[tree[src][i]][0],dp[tree[src][i]][1]);
				}
			}
		}
		dp[src][1]=val-1;
	}
	else	{
		int fmax,smax;
		for(int i=0;i<tree[src].size();i++)	{
			if(tree[src][i]!=par)	{
				fmax=tree[src][i];
				break;
			}
		}
		for(int i=0;i<tree[src].size();i++)	{
			if(tree[src][i]!=par)	{
				if(dp[fmax][0]-dp[fmax][1]>dp[tree[src][i]][0]-dp[tree[src][i]][1])	{
					fmax=tree[src][i];
				}
			}
		}
		for(int i=0;i<tree[src].size();i++)	{
			if(tree[src][i]!=par && tree[src][i]!=fmax)	{
				smax=tree[src][i];
				break;
			}
		}
		for(int i=0;i<tree[src].size();i++)	{
			if(tree[src][i]!=par && tree[src][i]!=fmax)	{
				if(dp[smax][0]-dp[smax][1]>dp[tree[src][i]][0]-dp[tree[src][i]][1])	{
					smax=tree[src][i];
				}
			}
		}
		for(int i=0;i<tree[src].size();i++)	{
			if(tree[src][i]!=par)	{
				if(tree[src][i]==fmax || tree[src][i]==smax)	{
					val+=dp[tree[src][i]][0];
				}
				else	{
					val+=dp[tree[src][i]][1];
				}
			}
		}
		dp[src][1]=val-1;
	}
}
//void generatepath(int src)	{

//}
int main()	{
	int t,n,u,v;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d",&n);
		for(int i=0;i<n-1;i++)	{
			scanf("%d%d",&u,&v);
			tree[u].push_back(v);
			tree[v].push_back(u);
			dp[i+1][0]=0;
			dp[i+1][1]=0;
		}
		dp[n][0]=dp[n][1]=0;
		dfs(1,0);
		for(int i=1;i<=n;i++)	{
			printf("%d\t%d\t%d\n",i,dp[i][0],dp[i][1]);
		}
		if(dp[1][1]==-1)	{
			printf("%d\n",dp[1][0]);
		}
		else	{
			printf("%d\n",min(dp[1][0],dp[1][1]));			
		}
		for(int i=1;i<=n;i++)	{
			tree[i].clear();
		}
	}
	return 0;
}
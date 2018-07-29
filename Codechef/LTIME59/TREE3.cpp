#include <bits/stdc++.h>
using namespace std;

vector<int> tree[100100];
bool vis[100100], flag;

struct node	{
	int a,b,c,d;
}temp;
vector<node> ans;

bool dfs(int src,int par)	{
	if(flag==false)	{
		return false;
	}
	vis[src]=true;
	vector<int> child;
	for(int i=0;i<tree[src].size();i++)	{
		if(!vis[tree[src][i]] && dfs(tree[src][i],src) && child.size()<3)	{
			child.push_back(tree[src][i]);
			if(child.size()==3)	{
				temp.a=src;
				temp.b=child[0];
				temp.c=child[1];
				temp.d=child[2];
				ans.push_back(temp);
				child.clear();
			}
		}
		if(flag==false)	{
			return false;
		}
	}
	if(child.size()==2 && par!=src)	{
		temp.a=src;
		temp.b=child[0];
		temp.c=child[1];
		temp.d=par;
		ans.push_back(temp);
		return false;
	}
	if(child.size()==0)	{
		return true;
	}
	flag=false;
	return false;
}
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		int n;
		cin>>n;
		flag=true;
		for(int i=1;i<=n;i++)	{
			tree[i].clear();
			vis[i]=false;
		}
		ans.clear();
		int u,v;
		for(int i=1;i<n;i++)	{
			cin>>u>>v;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		if((n-1)%3!=0)	{
			cout<<"NO\n";
		}
		else	{
			dfs(1,1);
			if(flag==true)	{
				cout<<"YES\n";
				for(int i=0;i<ans.size();i++)	{
					cout<<ans[i].a<<" "<<ans[i].b<<" "<<ans[i].c<<" "<<ans[i].d<<endl;
				}
			}
			else	{
				cout<<"NO\n";
			}
		}
	}
	return 0;
}
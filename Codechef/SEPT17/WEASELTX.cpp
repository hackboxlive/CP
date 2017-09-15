#include <bits/stdc++.h>
using namespace std;
vector<int> tree[300300];
long long vertex[200200];
long long arr[300300];
int vis[200200];
void bfs(int src)	{
	queue<pair<int,int> > q;
	q.push(make_pair(0,0));
	int u,v;
	vis[0]=true;
	while(!q.empty())	{
		u=q.front().first;
		v=q.front().second;
		q.pop();
		arr[v]^=vertex[u];
		for(int i=0;i<tree[u].size();i++)	{
			if(vis[tree[u][i]]==false)	{
				q.push(make_pair(tree[u][i],v+1));
				vis[tree[u][i]]=true;
			}
		}
	}
}
int main()	{
	int n,q,u,v;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n-1;i++)	{
		scanf("%d %d",&u,&v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	for(int i=0;i<n;i++)	{
		scanf("%lld",&vertex[i]);
	}
	bfs(0);
	int block=1<<18;
	int half,start,times;
	for(int i=2;i<=block;i*=2)	{
		half=i/2;
		times=block/i;
		for(int j=0;j<times;j++)	{
			start=j*i;
			for(int k=0;k<half;k++)	{
				arr[k+start+half]^=arr[k+start];
			}
		}
	}
	long long tt,modd=1<<18;
	while(q--)	{
		scanf("%lld",&tt);
		tt%=modd;
		if(tt==0)	{
			cout<<arr[0]<<endl;
		}
		else	{
			cout<<arr[(1<<18)-tt]<<endl;
		}
	}
	return 0;
}
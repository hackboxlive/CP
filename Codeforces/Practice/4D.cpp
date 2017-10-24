#include <bits/stdc++.h>
using namespace std;
struct node	{
	int h;
	int w;
	int i;
};
bool comp(const node &p1,const node &p2)	{
	return p1.w<p2.w;
}
int dp[5050];
int pre[5050];
int main()	{
	int n,w,h;
	cin>>n>>w>>h;
	vector<node> env;
	node temp;
	for(int i=0;i<n;i++)	{
		cin>>temp.w>>temp.h;
		temp.i=i+1;
		if(temp.h>h && temp.w>w)	{
//			cout<<"true";
			env.push_back(temp);
		}
	}
	if(env.size()==0)	{
		cout<<"0\n";
		return 0;
	}
	sort(env.begin(),env.end(),comp);
	// for(int i=0;i<env.size();i++)	{
	// 	cout<<env[i].h<<" "<<env[i].w<<" "<<env[i].i<<endl;
	// }
	dp[0]=1;
	pre[0]=-1;
	int mx=0;
	for(int i=1;i<env.size();i++)	{
//		cout<<env[i].h<<" "<<env[i].w<<endl;
		int mp=-1;
		for(int j=0;j<i;j++)	{
			if(env[i].h>env[j].h && env[i].w>env[j].w)	{
				if(mp==-1)	{
					mp=j;
				}
				else {
					if(dp[mp]<dp[j])	{
//						cout<<"True\n";
						mp=j;
					}
				}
			}
		}
		if(mp==-1)	{
//			cout<<"Also\n";
			dp[i]=1;
			pre[i]=-1;
		}
		else	{
			dp[i]=dp[mp]+1;
			pre[i]=mp;
			if(dp[i]>dp[mx])	{
				mx=i;
			}
		}
	}
	// for(int i=0;i<env.size();i++)	{
	// 	cout<<env[i].w<<" "<<env[i].h<<" "<<env[i].i<<" "<<dp[i]<<" "<<pre[i]<<endl;
	// }
	cout<<dp[mx]<<endl;
	stack<int> s;
	s.push(env[mx].i);
	while(pre[mx]!=-1)	{
		mx=pre[mx];
		s.push(env[mx].i);
	}
	while(!s.empty())	{
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
	return 0;
}
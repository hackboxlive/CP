#include <bits/stdc++.h>
using namespace std;
int dp[110];
vector<int> graph[110];
string s;
vector<string> dfs(int pos)	{
	vector<string> ans;
	if(dp[pos]==1)	{
		string temp(1,s[pos]);
		ans.push_back(temp);
		return ans;
	}
	for(int i=0;i<graph[pos].size();i++)	{
		vector<string> temp=dfs(graph[pos][i]);
		for(int j=0;j<temp.size();j++)	{
			temp[j]=temp[j]+s[pos];
		}
//		ans.push_back(temp);
		ans.insert(ans.end(),temp.begin(),temp.end());
	}
	return ans;
}
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		memset(dp,-1,sizeof(dp));
		cin>>s;
		for(int i=0;i<s.length();i++)	{
			graph[i].clear();
		}
		dp[0]=1;
		int maxe;
		for(int i=1;i<s.length();i++)	{
			maxe=1;
			for(int j=0;j<i;j++)	{
				if(s[j]<=s[i] && maxe<dp[j]+1)	{
					maxe=dp[j]+1;
				}
			}
			dp[i]=maxe;
			for(int j=0;j<i;j++)	{
				if(s[j]<=s[i] && maxe==dp[j]+1)	{
					graph[i].push_back(j);
				}
			}
		}
		int ans=-1;
		for(int i=0;i<s.length();i++)	{
//			cout<<dp[i]<<endl;
			if(ans<=dp[i])	{
				ans=dp[i];
//				cout<<ans<<endl;
			}
		}
//		cout<<ans<<endl;
		vector<string> answer;
		for(int i=0;i<s.length();i++)	{
			if(ans==dp[i])	{
//				cout<<"Calling dfs at "<<i<<endl;
				vector<string> temp=dfs(i);
				answer.insert(answer.end(),temp.begin(),temp.end());
			}
		}
		sort(answer.begin(),answer.end());
		for(int i=0;i<answer.size();i++)	{
			cout<<answer[i]<<endl;
		}
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > inp(100100);
int complete[100100];
int main()	{
	int n,k;
	scanf("%d%d",&n,&k);
	int val;
	for(int i=1;i<=n;i++)	{
		scanf("%d",&val);
		inp[val].push_back(i);
	}
	int tot=0;
	for(int i=1;i<=k;i++)	{
		scanf("%d",&complete[i]);
		tot+=complete[i];
	}
	if(k+tot>n)	{
		cout<<"-1\n";
		return 0;
	}
//	cout<<"HERE";
	vector<int>::iterator lower;
	int lo=1;
	int hi=n;
	int mid;
//	for(int i=1;i<=k;i++)	{
//		for(int j=0;j<inp[i].size();j++)	{
//			cout<<inp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	int flag=0;
	while(lo<hi)	{
		mid=lo+(hi-lo)/2;
//		cout<<"mid="<<mid<<endl;
		int maxxi=INT_MIN;
		for(int i=1;i<=k;i++)	{
			lower=upper_bound(inp[i].begin(),inp[i].end(),mid);
			lower--;
//			cout<<*lower<<endl;
			if(maxxi < *lower)	{
				maxxi = *lower;
			}
		}
		if(tot+k<=maxxi)	{
			hi=mid;
			flag=1;
		}
		else	{
			lo=mid+1;
		}
	}
//	if(flag==1)	{
		cout<<lo<<endl;
//	}
//	else	{
//		cout<<"-1\n";
//	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int arr1[200100];
//int arr2[200100];
int visited[200100];
int start[200100];
vector<int> v(200100);
int rr;
int ctr;
void dfs(int src,int i)	{
	if(visited[src]==visited[arr1[src]] && visited[src]!=0)	{
		return;
	}
	start[src]=ctr;
	ctr++;
	visited[src]=i;
	if(visited[arr1[src]]!=i)	{
		dfs(arr1[src],i);
	}
	else	{
		v[rr++]=start[src]-start[arr1[src]]+1;
	}
	return;
}
long long int fast_exp(int base, int exp)
{
	if(exp==1)
		return base;
	else
	{
		if(exp%2 == 0)
		{
			long long int base1 = pow(fast_exp(base, exp/2),2);
			if(base1 >= 1000000007)
				return base1%1000000007;
			else
				return base1;
		}
		else
		{
			long long int ans = (base*  pow(fast_exp(base,(exp-1)/2),2));
			if(ans >= 1000000007)
				return ans%1000000007;
			else
				return ans;
		}
	}
}
int main()	{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	{
		scanf("%d",&arr1[i]);
	}
	rr=0;
	int hh=1;
	for(int i=1;i<=n;i++)	{
		if(visited[i]==0)	{
			ctr=1;
			dfs(i,hh);
			hh++;
		}
	}
	long long int ans=0;
	for(int i=0;i<rr;i++)	{
		if(v[i]==n)	{
			ans=ans+2;
		}
		else	{
			ans=(ans+(2*fast_exp(2,(n-v[i])))%1000000007)%1000000007;
		}
	}
	long long int powertwo=1;
	powertwo=fast_exp(2,n);
	long long int wer=powertwo-ans;
	if(wer<0)	{
		wer=wer+1000000007;
	}
	cout<<wer<<endl;
	return 0;
}
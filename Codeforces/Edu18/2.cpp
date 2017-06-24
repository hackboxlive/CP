#include <bits/stdc++.h>
using namespace std;
bool child[110];
int main()	{
	int n,k;
	memset(child,false,sizeof(child));
	cin>>n>>k;
	int val;
	int left=n;
	int leader=1;
	for(int i=0;i<k;i++)	{
		cin>>val;
		val%=left;
//		cout<<"val="<<val<<endl;
		while(val)	{
			if(leader==n+1)	{
				leader=1;
			}
//			cout<<leader<<endl;
			if(child[leader]==false)	{
				val--;
				leader++;
			}
			else	{
				leader++;
			}
		}
		if(leader==n+1)	{
			leader=1;
		}
		while(child[leader])	{
			leader++;
			if(leader==n+1)	{
				leader=1;
			}
		}
		cout<<leader<<" ";
		left--;
		child[leader]=true;
		while(child[leader])	{
			leader++;
			if(leader==n+1)	{
				leader=1;
			}
		}
//		cout<<"new leader "<<leader<<endl;
		for(int i=1;i<=n;i++)	{
//			cout<<child[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
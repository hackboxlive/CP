#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > eugeny;
set<int> evenset,oddset;
int main()	{
	int n,k;
	cin>>n>>k;
	int ess=0;
	int oss=0;
	int val;
	for(int i=0;i<n;i++)	{
		scanf("%d",&val);
		eugeny.push_back(make_pair(val,0));
		if(val%2==0)	{
			evenset.insert(val);
			if(ess==evenset.size())	{
				eugeny[i].second=1;
			}
			ess=evenset.size();
		}
		else	{
			oddset.insert(val);
			if(oss==oddset.size())	{
				eugeny[i].second=1;
			}
			oss=oddset.size();
		}
	}
	int oddval=1;
	int evenval=2;
	if(evenset<=n/2 && oddset<=n/2)	{
		for(int i=0;i<n && oddset.size()<(n/2);i++)	{
			if(eugeny[i].second==1)	{
				while(oddval<k)	{
					oddset.insert(oddval);
					if(oss!=oddset.size())	{
						oss=oddset.size();
						break;
					}
				}
			}
		}
		
	}

}
#include <bits/stdc++.h>
using namespace std;
bool comp(const pair<pair<int,int> , pair<int,int> > &p1,const pair<pair<int,int> , pair<int,int> > &p2)	{
	return p1.first.first<p2.first.first;
}
set<pair<pair<int,int> , pair<int,int> > > s;
vector<int> counter;
int main()	{
	int n;
	scanf("%d",&n);
	pair<pair<int,int> , pair<int,int> > zero,lastt,arrr;
	zero.first.first=0;
	zero.second.first=-1;
	zero.second.second=-1;
	zero.first.second=-1;
	lastt.first.first=n+1;
	lastt.second.first=-1;
	lastt.second.second=-1;
	lastt.first.second=-1;
	s.insert(zero);
	s.insert(lastt);
	int ctr=0;
	for(int i=0;i<n;++i)	{
		scanf("%d",&arrr.first.first);
		arrr.second.first=-1;
		arrr.second.second=-1;
		set<pair<pair<int,int> , pair<int,int> > >::iterator it1;
		set<pair<pair<int,int> , pair<int,int> > >::iterator it2=s.upper_bound(arrr);
		it1=it2;
		it1--;
		if(it1->second.first == -1)	{
			it1->second.first=1;
			arrr.first.second=1+it1->first->second;
			s.insert(arrr);
		}
//		else	{
//			it2->left=1;
//			arr[i].depth=1+it2->depth;
//			s.insert(arr[i]);
//		}
		ctr=ctr+arrr.first.second;
		counter.push_back(ctr);
	}
	for(int i=0;i<counter.size();i++)	{
		cout<<ctr<<endl;
	}
	return 0;
}
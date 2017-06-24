#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int main()	{
	int t;
	set<int> s;
	int n,p;
	scanf("%d",&t);
	while(t--)	{
		s.clear();
		scanf("%d %d",&n,&p);
		for(int i=0;i<n;i++)	{
			scanf("%d",&arr[i]);
		}
		int x,pre=0,maxx=0;
		s.insert(0);
		int cnt=0;
		for(int i=0;i<n;i++)	{
			pre+=arr[i];
			pre%=p;
			maxx=max(maxx,pre);
			auto it=s.lower_bound(pre+1);
			auto it2=s.upper_bound(pre+1);
			if(it!=s.end())	{
				if(maxx<pre-(*it)+p)	{
					maxx=pre-(*it)+p;
					cnt=distance(it,it2);
				}
				else if(maxx==pre-*(it)+p)	{
					cnt+=distance(it,it2);
				}
			}
			s.insert(pre);
			cout<<maxx<<" "<<cnt<<endl;
		}
		printf("%d %d\n",maxx,cnt);
	}
	return 0;
}
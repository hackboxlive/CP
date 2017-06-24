#include <bits/stdc++.h>
using namespace std;
vector<int> tt;
int main()	{
	int n,x,y;
	cin>>n>>x>>y;
	long long ctrx=0,ctry=0;
	long long v1,v2;
	while(ctrx<x || ctry<y)	{
		v1=((long long)(1+ctrx))*y;
		v2=((long long)(1+ctry))*x;
		if(v1<v2)	{
			ctrx++;
			tt.push_back(1);
		}
		else if(v1>v2)	{
			ctry++;
			tt.push_back(2);
		}
		else{
			ctry++;
			ctrx++;
			tt.push_back(3);
			tt.push_back(3);
		}
	}
	int t,ans;
	for(int i=0;i<n;i++)	{
		cin>>t;
		t--;
		ans=tt[t%(x+y)];
		if(ans==1)	{
			cout<<"Vanya\n";
		}
		if(ans==2)	{
			cout<<"Vova\n";
		}
		if(ans==3)	{
			cout<<"Both\n";
		}
	}
	return 0;
}
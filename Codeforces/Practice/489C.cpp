#include <bits/stdc++.h>
using namespace std;
int main()	{
	int m,k;
	cin>>m>>k;
	if(k==0 && m==1)	{
		cout<<"0 0";
		return 0;
	}
	if(k==0 || k>9*m)	{
		cout<<"-1 -1";
		return 0;
	}
	//for minimum possible number
	int summ=k;
	summ--;
	string ss="";
	for(int i=1;i<m;i++)	{
		if(summ>9)	{
			ss=ss+"9";
			summ=summ-9;
		}
		else if(summ>0 && summ<10)	{
			ss=ss+ to_string(summ);
			summ=0;
		}
		else	{
			ss=ss+"0";
		}
	}
	reverse(ss.begin(),ss.end());
	if(summ==0)	{
		cout<<"1";
	}
	else	{
		cout<<summ+1;
	}
	cout<<ss;
	cout<<" ";
	//for maximum possible number
	summ=k;
	for(int i=0;i<m;i++)	{
		if(summ>9)	{
			cout<<"9";
			summ=summ-9;
		}
		else if(summ>0 && summ<10)	{
			cout<<summ;
			summ=0;
		}
		else	{
			cout<<"0";
		}
	}
	return 0;
}
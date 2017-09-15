#include <bits/stdc++.h>
using namespace std;
int main()	{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,start,x;
	cin>>n>>start>>x;
	cout<<"HERR";
//	fflush(stdout);
	srand(time(NULL));
	int seed=500;
	int id;
	int val,pos;
	int av=-1,ap=start;
	for(int i=0;i<seed;i++)	{
		id=rand()*n;
		cout<<"? "<<id;
		fflush(stdout);
		cin>>val>>pos;
		fflush(stdout);
		if(val<x)	{
			if(val>av)	{
				av=val;
				ap=pos;
			}
		}
	}
	int loop=501;
	int flag=0;
	while(loop<=2000 && ap!=-1)	{
		cout<<"? "<<ap;
		fflush(stdout);
		cin>>val>>pos;
		fflush(stdout);
		if(val>=x)	{
			cout<<"! "<<val;
			fflush(stdout);
			exit(0);
		}
		ap=pos;
	}
	cout<<"! -1"<<endl;
	return 0;
}
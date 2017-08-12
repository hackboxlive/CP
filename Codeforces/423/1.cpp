#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n,a,b,c;
	cin>>n>>a>>b;
	c=0;
	int temp;
	int ctr=0;
	for(int i=0;i<n;i++)	{
		cin>>temp;
		if(temp==1)	{
			if(a>0)	{
				a--;
			}
			else if(b>0)	{
				b--;
				c++;
			}
			else if(c>0)	{
				c--;
			}
			else	{
				ctr++;
			}
		}
		else	{
			if(b>0)	{
				b--;
			}
			else	{
				ctr+=2;
			}
		}
	}
	cout<<ctr<<endl;
	return 0;
}
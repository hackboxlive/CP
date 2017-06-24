#include <bits/stdc++.h>
using namespace std;
int main()	{
	int a,b;
	cin>>a>>b;
	int ctr=0;
	if(a>b)	{
		swap(a,b);
	}
	while(true)	{
		if(b%2 == 0)	{
			ctr=ctr+(b-2)/2;
			a=a+(b-2)/2;
			b=2;
		}
		else	{
			ctr=ctr+(b-1)/2;
			a=a+(b-1)/2;
			b=1;
		}
		if((a==2 || a==1) && (b==2 || b==1))	{
			if(a==1 && b==1)	{
				break;
			}
			ctr++;
			break;
		}
		swap(a,b);
	}
	cout<<ctr;
	return 0;
}
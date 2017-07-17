#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n,a,b;
	cin>>n>>a>>b;
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
				a++;
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
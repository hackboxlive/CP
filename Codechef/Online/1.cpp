#include <bits/stdc++.h>
using namespace std;
int comp(int a[3],int b[3])	{
	if(a[0]>=b[0] && a[1]>=b[1] && a[2]>=b[2])	{
		if(a[0]>b[0] || a[1]>b[1] || a[2]>b[2])	{
			return 1;
		}
		return -1;
	}
	if(a[0]<=b[0] && a[1]<=b[1] && a[2]<=b[2])	{
		if(a[0]<b[0] || a[1]<b[1] || a[2]<b[2])	{
			return 2;
		}
		return -1;
	}
	return -1;
}
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		int a[3];
		int b[3];
		int c[3];
		int flag=false;
		for(int i=0;i<3;i++)	{
			cin>>a[i];
		}
		for(int i=0;i<3;i++)	{
			cin>>b[i];
		}
		for(int i=0;i<3;i++)	{
			cin>>c[i];
		}
		if(comp(a,b)==1)	{
			if(comp(c,a)==1)	{
				flag=true;
			}
			else if(comp(c,a)==2)	{
				if(comp(c,b)==1 || comp(c,b)==2)	{
					flag=true;
				}
				else	{
					flag=false;
				}
			}
			else	{
				flag=false;
			}
		}
		else if(comp(a,b)==2)	{
			if(comp(c,b)==1)	{
				flag=true;
			}
			else if(comp(c,b)==2)	{
				if(comp(c,a)==1 || comp(c,a)==2)	{
					flag=true;
				}
				else	{
					flag=false;
				}
			}
			else	{
				flag=false;
			}
		}
		else	{
			flag=false;
		}
		if(flag)	{
			cout<<"yes\n";
		}
		else	{
			cout<<"no\n";
		}
	}
	return 0;
}
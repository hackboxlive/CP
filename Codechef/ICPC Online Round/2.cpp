#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int main()	{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)	{
		int n;
		cin>>n;
		int ctr=0;
		if(n==1)	{
			int num;
			cin>>num;
			cout<<"yes\n";
			continue;
		}
		int m1=0;
		int zero=0;
		int one=0;
		for(int i=0;i<n;i++)	{
			cin>>arr[i];
			if(arr[i]!=0 && arr[i]!=1 && arr[i]!=-1)	{
				ctr++;
			}
			if(arr[i]==-1)	{
				m1++;
			}
			if(arr[i]==1)	{
				one++;
			}
			if(arr[i]==0)	{
				zero++;
			}
		}
/*		if(m1==0)	{
			if(ctr>=2)	{
				cout<<"no\n";
			}
			else	{
				cout<<"yes\n";
			}
		}
		else	{
			if(ctr>0)	{
				cout<<"no\n";
			}
			else	{
				if(m1==1)	{
					cout<<"yes\n";
				}
				else	{
					if(one>0)	{
						cout<<"yes\n";
					}
					else	{
						cout<<"no\n";
					}
				}
			}
		}
*/
		if(ctr>1)	{
			cout<<"no\n";
		}
		else if(ctr==1)	{
			if(m1>0)	{
				cout<<"no\n";
			}
			else	{
				cout<<"yes\n";
			}
		}
		else	{
			if(m1<=1)	{
				cout<<"yes\n";
			}
			else	{
				if(one>0)	{
					cout<<"yes\n";
				}
				else	{
					cout<<"no\n";
				}
			}
		}
	}
	return 0;
}
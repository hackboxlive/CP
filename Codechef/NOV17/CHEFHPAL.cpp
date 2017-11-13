#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		int n,a;
		cin>>n>>a;
		if(a>2)	{
			string ans="";
			for(int i=0;i<n;i++)	{
				ans+=(char)(i%a+'a');
			}
			cout<<"1 "<<ans<<endl;
		}
		else	{
			if(a==1)	{
				cout<<n<<" ";
				for(int i=0;i<n;i++)	{
					cout<<"a";
				}
				cout<<endl;
			}
			else	{
				if(n==1)	{
					cout<<"1 a\n";
				}
				else if(n==2)	{
					cout<<"1 ab\n";
				}
				else if(n==3)	{
					cout<<"2 abb\n";
				}
				else if(n==4)	{
					cout<<"2 aabb\n";
				}
				else if(n==5)	{
					cout<<"3 aabbb\n";
				}
				else if(n==6)	{
					cout<<"3 aaabbb\n";
				}
				else if(n==7)	{
					cout<<"3 aaababb\n";
				}
				else if(n==8)	{
					cout<<"3 aaababbb\n";
				}
				else	{
					cout<<"4 aaaa";
					for(int i=4;i<n;i++)	{
						if(i%6==4)	{
							cout<<"b";
						}
						if(i%6==5)	{
							cout<<"a";
						}
						if(i%6==0)	{
							cout<<"b";
						}
						if(i%6==1)	{
							cout<<"b";
						}
						if(i%6==2)	{
							cout<<"a";
						}
						if(i%6==3)	{
							cout<<"a";
						}
					}
					cout<<endl;
				}
			}
		}
	}
	return 0;
}
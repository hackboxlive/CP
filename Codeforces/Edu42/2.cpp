#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n,a,b;
	cin>>n>>a>>b;
	string s;
	cin>>s;
	s+="*";
	vector<int> gaps;
	int temp=0;
	for(int i=0;i<n+1;i++)	{
		if(s[i]=='*')	{
			gaps.push_back(temp);
			temp=0;
		}
		else	{
			temp++;
		}
	}
	sort(gaps.begin(),gaps.end());
	reverse(gaps.begin(),gaps.end());
	int ans=0;
	for(int i=0;i<gaps.size();i++)	{
		temp=gaps[i];
		if(gaps[i]%2==0)	{
			if(gaps[i]/2<=a)	{
				ans+=gaps[i]/2;
				a-=gaps[i]/2;
			}
			else	{
				ans+=a;
				a=0;
			}
			if(gaps[i]/2<=b)	{
				ans+=gaps[i]/2;
				b-=gaps[i]/2;
			}
			else	{
				ans+=b;
				b=0;
			}		
		}
		else	{
			if(a>b)	{
				if(gaps[i]/2+1<=a)	{
					ans+=gaps[i]/2+1;
					a-=(gaps[i]/2+1);
				}
				else	{
					ans+=a;
					a=0;
				}
				if(gaps[i]/2<=b)	{
					ans+=gaps[i]/2;
					b-=gaps[i]/2;
				}
				else	{
					ans+=b;
					b=0;
				}		
			}
			else	{
				if(gaps[i]/2+1<=b)	{
					ans+=gaps[i]/2+1;
					b-=(gaps[i]/2+1);
				}
				else	{
					ans+=b;
					b=0;
				}
				if(gaps[i]/2<=a)	{
					ans+=gaps[i]/2;
					a-=gaps[i]/2;
				}
				else	{
					ans+=a;
					a=0;
				}	
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
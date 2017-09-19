#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int main()	{
	int n;
	cin>>n;
	string s="";
	for(int i=0;i<n;i++)	{
		s+='0';
	}
	fflush(stdout);
	cout<<"? "<<s<<endl;
	fflush(stdout);
	int ones,v;
	cin>>ones;
	s[n-1]='1';
	fflush(stdout);
	cout<<"? "<<s<<endl;
	fflush(stdout);
	cin>>v;
	int lastdig;
	if(v>ones)	{
		lastdig=0;
	}
	else	{
		lastdig=1;
	}
	if(lastdig==0)	{
		int diff=0;
		int ones1=ones;
		s[n-1]='0';
		int l=0,r=n-2;
		int p,mid,xx;
		while(l<r)	{
			mid=(l+r)/2;
			p=r-mid;
			for(int i=mid+1;i<=r;i++)	{
				s[i]='1';
			}
			fflush(stdout);
			cout<<"? "<<s<<endl;
			fflush(stdout);
			cin>>v;
			xx=(v-diff+ones1-p)/2;
//			cout<<xx<<" "<<diff<<" "<<p<<endl;
			cout<<l<<" "<<r<<" "<<xx<<" "<<diff<<" "<<p<<endl;
			if(xx>0)	{
				//left
				r=mid;
				ones1=xx;
				diff+=(v-diff-xx);
			}
			else	{
				//right
				l=mid+1;
				ones1=v-diff-xx;
				diff+=xx;
				for(int i=l;i<=mid;i++)	{
					s[i]='1';
				}
				for(int i=mid+1;i<=r;i++)	{
					s[i]='0';
				}
			}
		}
		fflush(stdout);
		cout<<"! "<<n<<" "<<l+1<<endl;
		fflush(stdout);
	}
	else	{
//		cout<<"HERR";
		int diff=0;
		int zeros=n-ones;
		int l=0,r=n-2;
		int p,mid,xx;
		for(int i=0;i<n;i++)	{
			s[i]='1';
		}
		while(l<r)	{
			mid=(l+r)/2;
			p=r-mid;
			for(int i=mid+1;i<=r;i++)	{
				s[i]='0';
			}
			fflush(stdout);
			cout<<"? "<<s<<endl;
			fflush(stdout);
			cin>>v;
			xx=(v-diff+zeros-p)/2;
			cout<<l<<" "<<r<<" "<<xx<<" "<<diff<<" "<<p<<endl;
			if(xx>0)	{
				//left
				r=mid;
				zeros=xx;
				diff+=(v-diff-xx);
			}
			else	{
				//right
				l=mid+1;
				zeros=v-diff-xx;
				diff+=xx;
				for(int i=l;i<=mid;i++)	{
					s[i]='0';
				}
				for(int i=mid+1;i<=r;i++)	{
					s[i]='1';
				}
			}
		}
		fflush(stdout);
		cout<<"! "<<l+1<<" "<<n<<endl;
		fflush(stdout);
	}
	return 0;
}
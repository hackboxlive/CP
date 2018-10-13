#include <bits/stdc++.h>
using namespace std;

int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		int x, l, r;
		cin>>x>>l>>r;
		bool hi=false;
		bool lo=false;
		int ans=0;
		int a,b,c;
		for(int i=31;i>=0;i--)
		{
			a=(r>>i)&1;
			b=(l>>i)&1;
			c=(x>>i)&1;
			if(c==0)
			{
				if(hi)
				{
					ans+=(1<<i);
					if(b==0)
					{
						lo=true;
					}
				}
				else
				{
					ans+=(a<<i);
					if(b==0 && a==1)
					{
						lo=true;
					}
				}
			}
			else
			{
				if(lo)
				{
					if(a==1)
					{
						hi=true;
					}
				}
				else
				{
					ans+=(b<<i);
					if(b==0 && a==1)
					{
						hi=true;
					}
				}
			}
		}
		cout<<(x^ans)<<endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int nearest_prime(int n)	{
	int k=max(n+1,25);
	bool ff;
	while(true)	{
		ff=false;
		for(int i=2;i<=sqrt(k);i++)	{
			if(k%i==0)	{
				ff=true;
			}
		}
		if(ff==false)	{
			return k;
		}
		k++;
	}
}
int main()	{
	long long n,m;
	cin>>n>>m;
	if(n==2)	{
		cout<<"2 2\n";
		cout<<"1 2 2\n";
		return 0;
	}
	int pp=nearest_prime(m+5);
	cout<<"2 "<<pp<<"\n";
	cout<<"1 "<<n<<" 2\n";
//	cout<<pp<<endl;
	for(int i=2;i<n-1;i++)	{
		cout<<"1 "<<i<<" 1\n";
	}
	int ed=n-1;
	cout<<"1 "<<n-1<<" "<<pp-n+1<<"\n";
	if(ed<m)	{
		for(int i=2;i<=n;i++)	{
			for(int j=i+1;j<=n;j++)	{
				cout<<i<<" "<<j<<" 100000000\n";
				ed++;
				if(ed==m)	{
					return 0;
				}
			}
		}
	}

	return 0;
}
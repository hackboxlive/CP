#include <bits/stdc++.h>
using namespace  std;
long long arr[1001000];
long long b[1000100];
long long n,p,q,b_size,num_block;
long long pre[1001000];
long long suf[1000100];
long long dp[1010][1010];
void precompute()	{
	for(long long i=0;i<num_block-1;i++)	{
		for(long long j=0;j<b_size;j++)	{
			if(j==0)	{
				pre[i*b_size+j]=arr[i*b_size+j];
				suf[i*b_size+(b_size-1-j)]=arr[i*b_size+(b_size-1-j)];
			}
			else	{
				pre[i*b_size+j]=(pre[i*b_size+j-1] * arr[i*b_size+j])%p;
				suf[i*b_size+(b_size-1-j)]=(suf[i*b_size+(b_size-1-j)+1] * arr[i*b_size+(b_size-1-j)])%p;
			}
		}
	}
	for(long long i=(num_block-1)*b_size,j=n-1;i<n;i++,j--)	{
		if(i==(num_block-1)*b_size)	{
			pre[i]=arr[i];
			suf[j]=arr[n-1];
		}
		else	{
			pre[i]=(pre[i-1]*arr[i])%p;
			suf[j]=(suf[j+1]*arr[j])%p;
		}
	}
	long long c;
	for(long long i=0;i<num_block;++i)	{
		if(i==num_block-1)	{
			dp[i][i]=pre[n-1];
		}
		else	{
			dp[i][i]=pre[i*b_size+b_size-1];
		}
	}
	for(long long i=1;i<num_block;i++)	{
		c=0;
		for(long long j=i;j<num_block;++j)	{
			dp[c][j]=(dp[c][j-1]*dp[c+1][j])%p; 
			++c;
		}
	}
	// for(long long i=0;i<num_block;++i)	{
	// 	for(long long j=0;j<num_block;j++)	{
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
}
long long query(long long l,long long r)	{
	long long x,y;
	long long ans=1;
	x = l/b_size;
	y = r/b_size;
//	cout<<"x = "<<x<<" and y = "<<y<<endl;
	if(x == y)	{
		for(long long i=l;i<=r;i++)	{
			ans=(ans*arr[i])%p;
		}
		return ans;
	}
	if(x+1 <= y-1)	{
		ans = dp[x+1][y-1];
	}
//	cout<<"ans="<<ans<<endl;
	ans = (ans * suf[l]) % p;
	ans = (ans * pre[r]) % p;
	return ans;
}
int main()	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long t;
	cin>>t;
	while(t--)	{
		cin>>n>>p>>q;
		b_size = sqrt(n);
		num_block = n / b_size;
		if(n % b_size != 0)	{
			++num_block;
		}
		for(long long i=0;i<n;++i)	{
			cin>>arr[i];
		}
		long long bs=q/64+2;
		for(long long i=0;i<bs;++i)	{
			cin>>b[i];
		}
		precompute();
		long long l,r;long long x=0;
		for(long long k=0;k<q;k++)	{
			if(k%64==0)	{
				l=(b[k/64]+x)%n;
				r=(b[k/64+1]+x)%n;
			}
			else	{
				l=(l+x)%n;
				r=(r+x)%n;
			}
			if(l>r)	{
				swap(l,r);
			}
//			cout<<l<<" "<<r<<endl;
			x=query(l,r);
//			cout<<x<<endl;
			++x;
			x%=p;
		}
		cout<<x<<endl;
	}
	return 0;
}
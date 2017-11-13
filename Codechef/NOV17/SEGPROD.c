#include <stdio.h>
int n,p,bucket_size,num_bucket;
int arr[1001000];
int b[500500];
long long tree[6006000],prefix[1010][1010],suffix[1010][1010],whole[1010],dp[1010][1010];
void build(int id,int l,int r)	{
	if(l==r)	{
		tree[id]=arr[l];
		return;
	}
	build(2*id,l,(l+r)/2);
	build(2*id+1,(l+r)/2+1,r);
	tree[id]=(tree[2*id]*tree[2*id+1])%p;
}
long long query(int id,int st,int en,int l,int r)	{
	if(st>r || en<l)	{
		return 1;
	}
	if(st>=l && en<=r)	{
		return tree[id];
	}
	return (query(2*id,st,(st+en)/2,l,r)*query(2*id+1,(st+en)/2+1,en,l,r))%p;
}
void precompute()	{
	int i,j,f=1;
	for(i=0;i<=num_bucket;++i)	{
		for(j=bucket_size-1;j>=0;--j)	{
			if(i*bucket_size+j>=n)	{
				continue;
			}
			if(j==bucket_size-1 || j==n-1)	{
				suffix[i][j]=arr[i*bucket_size+j];
			}
			else	{
				suffix[i][j]=(suffix[i][j+1]*arr[i*bucket_size+j])%p;
			}
		}
	}
	for(i=0;i<=num_bucket;++i)	{
		for(j=0;j<bucket_size;++j)	{
			if(i*bucket_size+j>=n)	{
				f=0;
				break;
			}
			if(j==0)	{
				prefix[i][j]=arr[i*bucket_size+j];
			}
			else	{
				prefix[i][j]=(prefix[i][j-1]*arr[i*bucket_size+j])%p;
			}
		}
		if(f==0)	{
			break;
		}
	}
	f=1;
	for(i=0;i<=num_bucket;++i)	{
		whole[i]=1;
		for(j=0;j<bucket_size;++j)	{
			if(i*bucket_size+j>=n)	{
				f=0;
				break;
			}
			whole[i]*=arr[i*bucket_size+j];
			whole[i]%=p;
		}
		if(f==0)	{
			break;
		}
	}
	for(i=0;i<=num_bucket;++i)	{
		for(j=i;j<=num_bucket;++j)	{
			if(i==j)	{
				dp[i][j]=whole[i];
			}
			else	{
				dp[i][j]=(dp[i][j-1]*whole[j])%p;
			}
		}
	}
}
int main()	{
	int i,t,q,l,r,temp,l_block,r_block;
	long long x;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d %d %d",&n,&p,&q);
		bucket_size=1000;
		num_bucket=(n-1)/bucket_size;
		int blen=q/64+2;
		for(i=0;i<n;++i)	{
			scanf("%d",&arr[i]);
			arr[i]%=p;
		}
		precompute();
		build(1,0,n-1);
		for(i=0;i<blen;++i)	{
			scanf("%d",&b[i]);
		}
		x=0;
		for(i=0;i<q;++i)	{
			if(i%64==0)	{
				l=(b[i/64]+x)%n;
				r=(b[i/64+1]+x)%n;
			}
			else	{
				l=(l+x)%n;
				r=(r+x)%n;
			}
			if(l>r)	{
				temp=l;
				l=r;
				r=temp;
			}
			l_block=l/bucket_size;
			r_block=r/bucket_size;
			if(l_block!=r_block)	{
				x=1;
				if(r_block-l_block>1)	{
					x=dp[l_block+1][r_block-1];
				}
				x=(x*suffix[l_block][l%bucket_size])%p;
				x=(x*prefix[r_block][r%bucket_size])%p;
			}
			else	{
				x=query(1,0,n-1,l,r);
			}
			x=(x+1)%p;
		}
		printf("%lld\n",x);
	}
	return 0;
}

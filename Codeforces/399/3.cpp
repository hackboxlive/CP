#include <bits/stdc++.h>
using namespace std;
int odd[1100];
int even[1100];
int main()	{
	int n,k,x,num,newval;
	cin>>n>>k>>x;
	for(int i=0;i<n;i++)	{
		cin>>num;
		even[num]++;
	}
	int cnt;
	for(int i=1;i<=k;i++)	{
		if(i%2==1)	{
			//even to odd
			cnt=0;
			for(int j=0;j<=1100;j++)	{
				if(even[j])	{
					if(even[j]%2==0)	{
						cnt+=even[j];
						newval=j^x;
						odd[newval]+=even[j]/2;
						odd[j]+=even[j]/2;
						even[j]=0;
					}
					else	{
						if(cnt%2==0)	{
							cnt+=even[j];
							newval=j^x;
							odd[newval]+=even[j]/2;
							odd[newval]++;
							odd[j]+=even[j]/2;
							even[j]=0;
						}
						else	{
							cnt+=even[j];
							newval=j^x;
							odd[newval]+=even[j]/2;
							odd[j]+=even[j]/2;
							odd[j]++;
							even[j]=0;
						}
					}
				}
			}
		}
		else	{
			//odd to even
			cnt=0;
			for(int j=0;j<=1100;j++)	{
				if(odd[j])	{
					if(odd[j]%2==0)	{
						cnt+=odd[j];
						newval=j^x;
						even[newval]+=odd[j]/2;
						even[j]+=odd[j]/2;
						odd[j]=0;
					}
					else	{
						if(cnt%2==0)	{
							cnt+=odd[j];
							newval=j^x;
							even[newval]+=odd[j]/2;
							even[newval]++;
							even[j]+=odd[j]/2;
							odd[j]=0;
						}
						else	{
							cnt+=odd[j];
							newval=j^x;
							even[newval]+=odd[j]/2;
							even[j]+=odd[j]/2;
							even[j]++;
							odd[j]=0;
						}
					}
				}
			}
		}
	}
	int minn=1101,maxx=-1;
	if(k%2==1)	{
		//odd me
		for(int i=0;i<=1100;i++)	{
			if(odd[i])	{
				if(i<minn)	{
					minn=i;
				}
				if(i>maxx)	{
					maxx=i;
				}
			}
		}
	}
	else	{
		//even me
		for(int i=0;i<=1100;i++)	{
			if(even[i])	{
				if(i<minn)	{
					minn=i;
				}
				if(i>maxx)	{
					maxx=i;
				}
			}
		}
	}
	cout<<maxx<<" "<<minn<<endl;
	return 0;
}
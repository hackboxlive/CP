#include <bits/stdc++.h>
using namespace std;
long long len[100100];
int main()	{
	string f0="What are you doing at the end of the world? Are you busy? Will you save us?";
	string first="What are you doing while sending \"";
	string second="\"? Are you busy? Will you send \"";
	string third="\"?";
	len[0]=f0.length();
	bool flag=true;
	for(int i=1;i<=100000;i++)	{
		len[i]=-1;
		if(flag)	{
			len[i]=first.length()+len[i-1]+second.length()+len[i-1]+third.length();
			if(len[i]>=(1LL<<62))	{
				flag=false;
			}
		}
	}
	long long q,n,k;
	cin>>q;
	while(q--)	{
		cin>>n>>k;
		k--;
		if(len[n]!=-1)	{
			if(k>=len[n])	{
				cout<<".";
				continue;
			}
		}
		flag=false;
		for(long long i=n;i>0;i--)	{
			if(k<first.length())	{
				cout<<first[k];
				flag=true;
				break;
			}
			k=k-(int)first.length();
			if(len[i-1]==-1)	{
				continue;
			}
			if(k>=len[i-1])	{
				k-=len[i-1];
				if(k<second.length())	{
					flag=true;
					cout<<second[k];
					break;
				}
				k=k-(int)second.length();
				if(len[i-1]==-1)	{
					continue;
				}
				if(k>=len[i-1])	{
					//bakar
					k-=len[i-1];
					if(k<third.length())	{
						flag=true;
						cout<<third[k];
						break;
					}
				}
				else	{
					continue;
				}
			}
			else	{
				continue;
			}
		}
		if(flag==false)	{
			cout<<f0[k];
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n,k;
	cin>>n>>k;
	if((n-1)%k==0)	{
		int ctr=2;
		int prev,next;
		int chain=(n-1)/k;
		cout<<2*chain<<endl;
		for(int i=0;i<k;i++)	{
			prev=1;
			next=ctr;
			for(int j=0;j<chain;j++)	{
				cout<<prev<<" "<<next<<endl;
				ctr++;
				prev=next;
				next=ctr;
			}
		}
	}
	else	{
		int ctr=2;
		int prev,next;
		int chain1=k;
		int rem=(n-1)%k;
		int chain2=rem;
		chain1=chain1-rem;
		int elem1=(n-1)/k;
		int elem2=elem1+1;
		if(rem==1)	{
			cout<<elem2*2-1<<endl;
		}
		else	{
			cout<<elem2*2<<endl;
		}
		for(int i=0;i<chain1;i++)	{
			prev=1;
			next=ctr;
			for(int j=0;j<elem1;j++)	{
				cout<<prev<<" "<<next<<endl;
				ctr++;
				prev=next;
				next=ctr;
			}
		}
		for(int i=0;i<chain2;i++)	{
			prev=1;
			next=ctr;
			for(int j=0;j<elem2;j++)	{
				cout<<prev<<" "<<next<<endl;
				ctr++;
				prev=next;
				next=ctr;
			}
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int main()	{
	int n;
	cin>>n;
	int p=0,q=0,r=0;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	for(int i=0;i<n;i++)	{
		if(arr[i]==arr[0])	{
			p++;
		}
		if(arr[i]==arr[0]+1)	{
			q++;
		}
		if(arr[i]==arr[0]+2)	{
			r++;
		}
	}
	if(arr[n-1]-arr[0]==2)	{
		int extra=r*2+q;
		//cout<<extra<<endl;
		int ans=1e9;
		int start;
		if(extra%2==0)	{
			start=0;
		}
		else	{
			start=1;
		}
		int temp;
		int ans_i;
		int c_p,c_q,c_r;
		for(int i=start;i<=min(extra,n);i+=2)	{
			c_q=i;
			c_r=(extra-c_q)/2;
			if(c_q+c_r>n)	{
				continue;
			}
			temp=min(q,i);
			temp+=min(r,(extra-i)/2);
			temp+=min(p,n-i-((extra-i)/2));
			if(ans>=temp)	{
				ans=temp;
				ans_i=i;
			}
		}
		cout<<ans<<endl;
		q=ans_i;
		r=(extra-ans_i)/2;
		p=n-q-r;
		//cout<<p<<" "<<q<<" "<<r<<endl;
		for(int i=0;i<p;i++)	{
			cout<<arr[0]<<" ";
		}
		for(int i=0;i<q;i++)	{
			cout<<arr[0]+1<<" ";
		}
		for(int i=0;i<r;i++)	{
			cout<<arr[0]+2<<" ";
		}
		cout<<endl;
	}
	else	{
		cout<<n<<endl;
		for(int i=0;i<n;i++)	{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
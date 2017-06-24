#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n;
	scanf("%d",&n);
	int zero[100100];
	int one[100100];
	int temp[100100];
	memset(zero,0,sizeof(zero));
	memset(one,0,sizeof(one));
	zero[0]=1;
	one[0]=1;
	for(int i=2;i<=n;i++)	{
		int j=0;
		int carry=0;
		while(zero[j]!=0 || one[j]!=0 || carry!=0)	{
			temp[j]=one[j];
			one[j]=zero[j]+one[j]+carry;
			carry=one[j]/10;
			one[j]=one[j]%10;
			zero[j]=temp[j];
			j++;
		}
	}
	int carry=0;
	stack<int> st;
	int j=0;
	while(zero[j]!=0 || one[j]!=0 || carry!=0)	{
		int v=zero[j]+one[j]+carry;
		carry=v/10;
		v=v%10;
		st.push(v);
		j++;
	}
	while(!st.empty())	{
		cout<<st.top();
		st.pop();
	}
	return 0;	
}
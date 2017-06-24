#include <bits/stdc++.h>
using namespace std;
int main()	{
	int k;
	int r;
	scanf("%d%d",&k,&r);
	for(int i=1;i<=10;i++)	{
		int val=k*i;
		if(val%10==r || val%10==0)	{
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}
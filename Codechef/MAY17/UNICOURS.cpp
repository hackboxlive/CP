#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t,n;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d",&n);
		int val;
		int offset=0;
		for(int i=0;i<n;i++)	{
			scanf("%d",&val);
			if(val>offset)	{
				offset=val;
			}
		}
		printf("%d\n",n-offset);
	}
	return 0;
}
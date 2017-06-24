#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		int n;
		scanf("%d",&n);
		double ans=(double)log2((double)n);
		if(ans-(int)ans==0.0)	{
			printf("No\n");
		}
		else	{
			printf("Yes\n");
		}
	}
	return 0;
}
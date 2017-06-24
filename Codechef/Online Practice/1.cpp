#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n;
	scanf("%d",&n);
	int val;
	int even=0;
	int odd=0;
	for(int i=0;i<n;i++)	{
		scanf("%d",&val);
		if(val%2==0)	{
			even++;
		}
		else	{
			odd++;
		}
	}
	if(even>odd)	{
		printf("READY FOR BATTLE\n");
	}
	else	{
		printf("NOT READY\n");
	}
}
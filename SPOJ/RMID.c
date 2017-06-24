#include <stdio.h>
int main()
{
	int i,l1=0,l2=0,r1=0,r2=0,n;
	int low[100001],high[100001];
	while(scanf("%d",&n)!= EOF)
	{
		if(n==0)
		{
			l1=l2=r1=r2=0;
			printf("\n");
		}
		else if(n == -1)
		{
			printf("%d\n",low[r1-1]);
			if(r1-l1 > r2-l2)
				r1--;
			else
			{
				low[r1-1] = high[l2];
				l2++;
			}
		}
		else
		{
			if(r1-l1 > r2-l2)
			{
				high[r2] = n;
				r2++;
			}
			else
			{
				if(r1 == 0)
				{
					low[r1] = n;
					r1++;
				}
				else
				{
					low[r1] = high[l2];
					r1++;
					l2++;
					high[r2] = n;
					r2++;
				}
			}
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()	{
	int q;
	int a,b;
	scanf("%d",&q);
	while(q--)	{
		scanf("%d %d",&a,&b);
		if(a>b)	{
			swap(a,b);
		}
		if(a==1)	{
			if(b==2 || b==3)	{
				printf("YES\n");
			}
			else	{
				printf("NO\n");
			}
		}
		else if(a==2)	{
			if(b==4)	{
				printf("YES\n");
			}
			else	{
				printf("NO\n");
			}
		}
		else	{
			if(a&1)	{
				if(b==a+1 || b==a+2)	{
					printf("YES\n");
				}
				else	{
					printf("NO\n");
				}
			}
			else	{
				if(b==a+2)	{
					printf("YES\n");
				}
				else	{
					printf("NO\n");
				}
			}
		}
	}
	return 0;
}
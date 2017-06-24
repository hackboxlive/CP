#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t,a,b;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d %d",&a,&b);
		int st=1;
		while(true)	{
			if(st%2==1)	{
				if(st>a)	{
					printf("Bob\n");
					break;
				}
				else	{
					a=a-st;
					st++;
				}
			}
			else	{
				if(st>b)	{
					printf("Limak\n");
					break;
				}
				else	{
					b=b-st;
					st++;
				}
			}
		}
	}
	return 0;
}
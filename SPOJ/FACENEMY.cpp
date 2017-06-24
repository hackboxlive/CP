#include <bit/stdc++.h>
using namespace std;
int main()	{
	int t;
	int v1,v2,v3,v4,v5;
	scanf("%d",&t);
	while(t--)	{
		scanf("%d %d %d %d %d %d %d %d",&x1,&y1,&u1,&v1,&x2,&y2,&u2,&v2);
		//hero view is at 90 degree to heroine and vice versa
		if(((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(x2-u2)*(x2-u2)+(y2-v2)*(y2-v2) == (x1-u2)*(x1-u2)) && ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(x1-u1)*(x1-u1)+(y1-v1)*(y1-v1) == (x2-u1)*(x2-u1)))	{
			printf("0\n");
			continue;
		}
		//only hero is at 90 degree to heroine
		if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(x2-u2)*(x2-u2)+(y2-v2)*(y2-v2) == (x1-u2)*(x1-u2))	{
			if(())
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
struct node	{
	int x,int y;
	int closestx,int closesty;
	int dist;
};
set<node> points;
set<node>::iterator it;

int main()	{
	int q;
	node temp;
	int numpoint=0;
	char ch[10];
	int td;
	int globd=1e9;
	scanf("%d",&q);
	while(q--)	{
		scanf("%s",ch);
		if(ch[0]=='+')	{
			scanf("%d %d",&x,&y);
			temp.x=x;
			temp.y=y;
			temp.dist=10000000;
			for(it=points.begin();it!=points.end();it++)	{
				td=pow(x-(*it).x,2)+pow(y-(*it).y,2);
				if(td<temp.dist)	{
					temp.dist=td;
					temp.closestx=(*it).x;
					temp.closesty=(*it).y;
				}
			}
			points.insert(temp);
			if(points.size()==1)	{
				printf("0\n");
				continue;
			}
			if(temp.dist>globd)	{
				globd=temp.dist;
			}
			printf("%d\n",globd);
		}
	}
}
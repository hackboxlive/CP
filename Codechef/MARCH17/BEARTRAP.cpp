#include <bits/stdc++.h>
using namespace std;
int hr,hc;
void first_catmove(int r,int c)	{
	if(r == 1 && c == -1)	{
		printf("BLOCK 2 -2\n");
	}
	if(r == 1 && c == 0)	{
		printf("BLOCK 2 0\n");
	}
	if(r == 0 && c == 1)	{
		printf("BLOCK 0 2\n");
	}
	if(r == -1 && c == 1)	{
		printf("BLOCK -2 2\n");
	}
	if(r == -1 && c == 0)	{
		printf("BLOCK -2 0\n");
	}
	if(r == 0 && c == -1)	{
		printf("BLOCK 0 -2\n");
	}
	return;
}
void move(int r,int c)	{

}
int main()	{
	int t,m;
	char ch[6];
	scanf("%d",&t);
	while(t--)	{
		scanf("%d",&m);
		int r,c;
		//do it in less than 20 moves
		scanf("%s",ch);
		scanf("%d %d",&r,&c);
		first_catmove(r,c);
		scanf("%s",ch);
		scanf("%d %d",&r,&c);
		hr = r;
		hc = c;
		while(ch[0] == 'C')	{
//			convert(r,c);
			move(r,c);
			scanf("%s",ch);
			scanf("%d %d",&r,&c);
		}
	}
	return 0;
}
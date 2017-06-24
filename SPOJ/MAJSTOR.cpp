#include <bits/stdc++.h>
using namespace std;
int main()	{
	int r,n;
	scanf("%d",&r);
	char sven[100];
	char player[100][100];
	scanf("%s",sven);
	scanf("%d",&n);
	for(int i=0;i<n;i++)	{
		scanf("%s",player[i]);
	}
	int paper,rock,scissor,actualsum=0,maxsum=0;
	for(int i=0;i<r;i++)	{
		paper=0;
		rock=0;
		scissor=0;
		for(int j=0;j<n;j++)	{
			if(player[j][i]=='P')	{
				scissor=scissor+2;
				paper=paper+1;
			}
			if(player[j][i]=='R')	{
				paper=paper+2;
				rock=rock+1;
			}
			if(player[j][i]=='S')	{
				rock=rock+2;
				scissor=scissor+1;
			}
		}
		if(sven[i]=='P')	{
			actualsum=actualsum+paper;
		}
		if(sven[i]=='R')	{
			actualsum=actualsum+rock;
		}
		if(sven[i]=='S')	{
			actualsum=actualsum+scissor;
		}
		maxsum=maxsum+max(paper,max(rock,scissor));
	}
	printf("%d\n%d\n",actualsum,maxsum);
	return 0;
}
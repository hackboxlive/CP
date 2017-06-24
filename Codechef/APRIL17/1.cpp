#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	string first[4];
	string second[4];
	scanf("%d",&t);
	while(t--)	{
		for(int i=0;i<4;i++)	{
			cin>>first[i];
		}
		for(int i=0;i<4;i++)	{
			cin>>second[i];
		}
		int ctr=0;
		for(int i=0;i<4;i++)	{
			for(int j=0;j<4;j++)	{
				if(first[i].compare(second[j])==0)	{
					ctr++;
					break;
				}
			}
		}
		if(ctr>=2)	{
			printf("similar\n");
		}
		else	{
			printf("dissimilar\n");
		}
	}
	return 0;
}
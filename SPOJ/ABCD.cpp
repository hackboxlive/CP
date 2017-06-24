#include <bits/stdc++.h>
using namespace std;
char arr[100100];
char newarr[100100];
int main()	{
	int n;
	scanf("%d",&n);
	scanf("%s",arr);
	int len=strlen(arr);
	len = len/2;
	int ff,ss;
	int flag[]={0,0,0,0};
	flag[arr[0]-'A']=1;
	flag[arr[1]-'A']=1;
	int ctr=0;
	for(int i=0;i<4;i++)	{
		if(flag[i]==0)	{
			newarr[ctr++]=(char)(i+'A');
			flag[i]=1;
		}
	}
//	printf("%s\n",newarr);
	memset(flag,0,sizeof(flag));
	for(int i=1;i<len;i++)	{
		memset(flag,0,sizeof(flag));
//		printf("%c %c\n",arr[2*i],arr[2*i+1]);
		flag[arr[2*i]-'A']=1;
		flag[arr[2*i+1]-'A']=1;
		for(int j=0;j<4;j++)	{
//			printf("%d\n",flag[j]);
			if(flag[j]==0)	{
//				printf("j=%d\n",j);
				ff=j;
				flag[j]=1;
				break;
			}
		}
		for(int j=0;j<4;j++)	{
			if(flag[j]==0)	{
				ss=j;
				flag[j]=1;
				break;
			}
		}
//		printf("%d %d\n",ff,ss);
		if(newarr[ctr-1]==(char)(ff+'A'))	{
			newarr[ctr++]=(char)(ss+'A');
			newarr[ctr++]=(char)(ff+'A');
		}
		else	{
			newarr[ctr++]=(char)(ff+'A');
			newarr[ctr++]=(char)(ss+'A');
		}
	}
	printf("%s\n",newarr);
	return 0;
}
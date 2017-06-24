#include <stdio.h>
#include <string.h>
char needle[1000010];
char haystack[1000010];
int kmp[1000010];
int needle_len;
void prefix()	{
	int p=0;
	int q=1;
	kmp[0]=0;
	while(q<needle_len)	{
		if(needle[p]==needle[q])	{
			p++;
			kmp[q]=p;
			q++;
		}
		else	{
			if(p!=0)	{
				p=kmp[p-1];
			}
			else	{
				kmp[q]=0;
				q++;
			}
		}
	}
}
void compute()	{
	int i=0;
	int j=0;
	int ctr=0;
	int h=strlen(haystack);
	while(i<h)	{
		if(needle[j]==haystack[i])	{
			i++;
			j++;
		}
		if(j==needle_len)	{
			printf("%d\n",i-j);
			ctr++;
			j=kmp[j-1];
		}
		else if(i<h && needle[j]!=haystack[i])	{
			if(j!=0)	{
				j=kmp[j-1];
			}
			else	{
				i++;
			}
		}
	}
	if(ctr==0)	{
		printf("\n");
	}
}
int main()	{
	while(scanf("%d\n",&needle_len)!=EOF)	{
		memset(kmp,0,sizeof(kmp));
		scanf("%s",needle);
		prefix();
		scanf("%s",haystack);
		compute();
	}
	return 0;
}
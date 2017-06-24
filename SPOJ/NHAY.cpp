#include <bits/stdc++.h>
using namespace std;
int kmp[1001000];
int main()	{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int needle_len;
	char needle[1001000];
	char haystack[1001000];
	while(scanf("%d",&needle_len)==1)	{
//		cin>>needle;
//		cin>>haystack;
		scanf("%s",needle);
		scanf("%s",haystack);
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
					p=kmp[q-1];
				}
				else	{
					kmp[q]=0;
					q++;
				}
			}
		}
		int i=0;
		int j=0;
		int ctr=0;
		int h=strlen(haystack);
//		for(int i=0;i<needle_len;i++)	{
//			cout<<needle[i]<<" "<<kmp[i]<<endl;
//		}
		while(i<h)	{
//			cout<<i<<endl;
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
//		for(int i=0;i<needle_len;i++)	{
//			cout<<needle[i]<<" "<<kmp[i]<<endl;
//		}
	}
	return 0;
}
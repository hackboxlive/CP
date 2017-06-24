#include <bits/stdc++.h>
using namespace std;
string s;
const int MAXX=500500;
struct node	{
	int pos;
	int neg;
	int endpos;
	int endneg;
	int ptr[26];
}trie[MAXX];
int ctr;
int globctr;
int fff;
char printable[200200];
int pctr;
void nullset()	{
	for(int i=0;i<MAXX;i++)	{
		trie[i].pos=0;
		trie[i].neg=0;
		trie[i].endpos=0;
		trie[i].endneg=0;
		for(int j=0;j<26;j++)	{
			trie[i].ptr[j]=-1;
		}
	}
}
void insert_string(int ch)	{
	int c;
	int nd=0;
	for(int i=0;i<s.length();i++)	{
		c=(int)(s[i]-97);
		if(trie[nd].ptr[c]==-1)	{
			ctr++;
			trie[nd].ptr[c]=ctr;
		}
		if(ch==1)	{
			trie[nd].pos++;
		}
		else	{
			trie[nd].neg++;
		}
		nd=trie[nd].ptr[c];
	}
	if(ch==1)	{
		trie[nd].pos++;
		trie[nd].endpos++;
	}
	else	{
		trie[nd].neg++;
		trie[nd].endneg++;
	}
	return;
}
void dfs(int nd)	{
	if(trie[nd].pos==0 && trie[nd].neg!=0)	{
		globctr++;
		return;
	}
	if(trie[nd].pos!=0 && trie[nd].endneg!=0)	{
		fff=1;
		return;
	}
	for(int i=0;i<26;i++)	{
		if(trie[nd].ptr[i]!=-1)	{
			dfs(trie[nd].ptr[i]);
		}
	}
}
void dfs_print(int nd,int pp)	{
	if(trie[nd].pos==0 && trie[nd].neg!=0)	{
		for(int i=0;i<pp;i++)	{
			printf("%c",printable[i]);
		}
		printf("\n");
		return;
	}
	for(int i=0;i<26;i++)	{
		if(trie[nd].ptr[i]!=-1)	{
			printable[pp]=(char)(i+97);
			dfs_print(trie[nd].ptr[i],pp+1);
		}
	}
}
int main()	{
	int n;
	string ch;
	string temp;
	ctr=0;
	scanf("%d",&n);
	nullset();
	getline(cin,s);
	for(int i=0;i<n;i++)	{
		cin>>ch;
		cin>>s;
		if(ch[0]=='+')	{
			insert_string(1);
		}
		else	{
			insert_string(-1);
		}
	}
	fff=0;
	globctr=0;
	dfs(0);
	if(fff==1)	{
		printf("-1\n");
		return 0;
	}
	cout<<globctr<<endl;
	dfs_print(0,0);
	return 0;
}
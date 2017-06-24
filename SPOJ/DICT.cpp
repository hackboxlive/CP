#include <bits/stdc++.h>
using namespace std;
struct node	{
	int numwords;
	int end;
	int ptr[26];
}trie[30000];
int ctr;
char word[30000];
string s;
void nullset()	{
	for(int i=0;i<30000;i++)	{
		trie[i].numwords=0;
		trie[i].end=0;
		for(int j=0;j<26;j++)	{
			trie[i].ptr[j]=-1;
		}
	}
}
void insert_string(int nd,int pos)	{
	if(pos==s.length())	{
		trie[nd].numwords++;
		trie[nd].end++;
		return;
	}
	int ch=(int)(s[pos]-97);
	if(trie[nd].ptr[ch]==-1)	{
		ctr++;
		trie[nd].ptr[ch]=ctr;
	}
	insert_string(trie[nd].ptr[ch],pos+1);
	trie[nd].numwords++;
}
pair<int,int> findwords()	{
	int nd=0,ch;
	for(int i=0;i<s.length();i++)	{
		ch=(int)(s[i]-97);
		if(trie[nd].ptr[ch]==-1)	{
			return make_pair(-1,0);
		}
		nd=trie[nd].ptr[ch];
	}
	return make_pair(trie[nd].numwords,nd);
}
void print_words(int nd,int pp)	{
	if(trie[nd].end!=0)	{
		for(int i=0;i<pp;i++)	{
			printf("%c",word[i]);
		}
		printf("\n");
	}
	for(int i=0;i<26;i++)	{
		if(trie[nd].ptr[i]!=-1)	{
			word[pp]=(char)(i+97);
			print_words(trie[nd].ptr[i],pp+1);
		}
	}
}
int main()	{
	int n;
	nullset();
	scanf("%d",&n);
	for(int i=0;i<n;i++)	{
		cin>>s;
		insert_string(0,0);
	}
	int k;
	pair<int,int> ans;
	scanf("%d",&k);
	for(int i=0;i<k;i++)	{
		cin>>s;
		ans=findwords();
		printf("Case #%d:\n",i+1);
		if(ans.first==-1)	{
			printf("No match.\n");
			continue;
		}
		for(int i=0;i<s.length();i++)	{
			word[i]=s[i];
		}
		print_words(ans.second,s.length());
	}
	return 0;
}
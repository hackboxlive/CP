#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > words(500100);
int min_size;
int k;
bool comp_word(int pos)	{
	int flag=0;
	for(int i=0;i<min_size;i++)	{
		if(words[pos][i]>words[pos+1][i])	{
			flag=1;
			break;
		}
	}
	if(flag==0)	{
		return true;
	}
	else	{
		return false;
	}
}
void add_word(int pos,int ctr)	{
	for(int i=0;i<min_size;i++)	{
		words[pos][i]=words[pos][i]+ctr;
		if(words[pos][i]==k+1)	{
			words[pos][i]=1;
		}
	}
	return;
}
int main()	{
	int n;
	int arr_size;
	int val;
	min_size=INT_MAX;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)	{
		scanf("%d",&arr_size);
		if(min_size>arr_size)	{
			min_size=arr_size;
		}
		for(int j=0;j<arr_size;j++)	{
			scanf("%d",&val);
			words[i].push_back(val);
		}
	}
	int break_pos;
	for(int i=0;i<n-1;i++)	{
		bool check=comp_word(i);
		if(check==false)	{
			break_pos=i;
		}
	}
	for(int i=break_pos+1;i<n-1;i++)	{
		bool check=comp_word(i);
		if(check==false)	{
			printf("-1\n");
			return 0;
		}
	}
	//make 1st smallest
	int ctr=0;
	int smallest=0;
	for(int i=0;i<min_size;i++)	{
		if(words[0][i]<words[0][smallest])	{
			smallest=i;
		}
	}
	ctr=k+1-words[0][smallest];
	for(int i=0;i<n;i++)	{
		add_word(i,ctr);
	}
	for(int i=0;i<n-1;i++)	{
		if(comp_word(i)==false)	{
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n",ctr);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n,a,b;
	string s;
	scanf("%d%d%d",&n,&a,&b);
	cin>>s;
	a--;
	b--;
	if(s[a]==s[b])	{
		printf("0\n");
		return 0;
	}
	else	{
		printf("1\n");
	}
	return 0;
}
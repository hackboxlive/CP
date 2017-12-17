#include <bits/stdc++.h>
using namespace std;
int main()	{
	int a;
	cin>>a;
	if(a%10<=5)	{
		a=a/10;
		a=a*10;
	}
	else	{
		a=a/10;
		a++;
		a=a*10;
	}
	cout<<a<<endl;
	return 0;
}
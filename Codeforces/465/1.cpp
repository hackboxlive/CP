#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n;
	cin>>n;
	int ways=0;
	for(int i=1;i<n;i++)	{

		if((n-i)%i==0)	{
			ways++;
		}
	}
	cout<<ways<<endl;
	return 0;
}
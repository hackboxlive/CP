#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n;
	cin>>n;
	int off=1;
	int ctr=1;
	for(int i=1;i<n;i++)	{
		cout<<(ctr%n)+1<<" ";
		off++;
		ctr+=off;
	}
	cout<<endl;
	return 0;
}
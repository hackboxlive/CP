#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t=1;
	cout<<t<<endl;
	int n=1000,l=5000;
	cout<<l<<" "<<n<<endl;
	srand(time(NULL));
	int r;
	char moves[]={'L','R','U','D'};
	for(int i=0;i<l;i++)	{
		r=rand()%4;
		cout<<moves[r];
	}
	cout<<endl;
	for(int i=0;i<n;i++)	{
		for(int j=0;j<n;j++)	{
			cout<<".";
		}
		cout<<endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()	{
	int n=50;
	int m=50;
	srand(time(NULL));
	cout<<n<<" "<<m<<endl;
	for(int i=0;i<m;i++)	{
		for(int j=0;j<n;j++)	{
			for(int k=0;k<n;k++)	{
				cout<<rand()%100<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
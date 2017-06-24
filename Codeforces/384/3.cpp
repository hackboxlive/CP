#include <bits/stdc++.h>
using namespace std;
int main()	{
	int p;
	cin>>p;
	int n1,n2,n3;
	if(p==1)	{
		cout<<"-1\n";
		return 0;
	}
	n1=p;
	n2=p+1;
	n3=p*(p+1);
	cout<<n1<<" "<<n2<<" "<<n3<<endl;
	return 0;
}
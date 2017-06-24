#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t=0;
	string s;
	for(int i=1;i<=10;i++)	{
		for(int j=0;j<=i;j++)	{
//			cout<<i<<" "<<j<<endl;
			for(int k=0;k<(1<<i);k++)	{
				s = "";
				int gg=k;
				for(int l=0;l<i;l++)	{
					if(gg%2)	{
						s=s+'1';
					}
					else	{
						s=s+'0';
					}
					gg/=2;
				}
				cout<<i<<" "<<j<<endl<<s<<endl;
				t++;
			}
		}
	}
	cout<<t<<endl;
	return 0;
}
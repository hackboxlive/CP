#include <bits/stdc++.h>
using namespace std;
int main()	{
	int a,b;
	cin>>a>>b;
	int step=1;
	while(true)	{
		if(step%2==1)	{
			if(a>=step)	{
				a=a-step;
				step++;
			}
			else	{
				cout<<"Vladik\n";
				break;
			}
		}
		else	{
			if(b>=step)	{
				b=b-step;
				step++;
			}
			else	{
				cout<<"Valera\n";
				break;
			}
		}
	}
	return 0;
}
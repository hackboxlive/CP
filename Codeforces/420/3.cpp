#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n,num;
	string comm;
	cin>>n;
	stack<int> st;
	int to_rem=1;
	int ctr=0;
	for(int i=0;i<2*n;i++)	{
		cin>>comm;
		if(comm[0]=='a')	{
			cin>>num;
			st.push(num);
		}
		else	{
			if(!st.empty() && st.top()==to_rem)	{
				st.pop();
				to_rem++;
			}
			else	{
				if(!(st.empty()))	{
					while(!(st.empty()))	{
						st.pop();
					}
					ctr++;
					to_rem++;
				}
				else	{
					to_rem++;
				}
			}
		}
	}
	cout<<ctr<<endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()	{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
	int t;
	cin>>t;
	string s;
	while(t--)	{
//		cout<<"TEST CASE #"<<t<<endl;
		cin>>s;
		stack<int> st;
		int val=0;
		for(int i=0;i<s.length();i++)	{
//			ssacout<<i<<endl;
			if(s[i]=='(')	{
				if(val!=0)	{
					st.push(val);
					st.push(-1);
					val=0;
				}
				else	{
					st.push(-1);
				}
			}
			else	{
				if(st.top()==-1)	{
					val++;
					st.pop();
				}
				else	{
					while(st.top()!=-1)	{
						val=val^st.top();
						st.pop();
					}
					val++;
					st.pop();
				}
			}
//			cout<<s[i]<<endl;
	//		cout<<val<<endl;
		}
		while(!st.empty())	{
			val=val^st.top();
			st.pop();
		}
//		cout<<val<<endl;
//		cout<<"HERE\n";
		if(val==0)	{
			cout<<"Bob\n";
		}
		else	{
			cout<<"ATM\n";
		}
	}
	return 0;
}

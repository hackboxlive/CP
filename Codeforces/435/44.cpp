#include <bits/stdc++.h>
using namespace std;

int main()	{
//	string s="0010100101101100001101110001110011000010011011001110010011101010011010100101101001111010111001000100";
	string s;
	cin>>s;
	cout<<(int)s.length()<<endl;
	string ss;
	while(true)	{
		cin>>ss;
		int ctr=0;
		for(int i=0;i<s.length();i++)	{
			if(s[i]!=ss[i])	{
				ctr++;
			}
		}
		cout<<ctr<<endl;
	}
	return 0;
}
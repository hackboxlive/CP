#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	cin>>t;
	string s;
	int alpha[10];
	while(t--)	{
		cin>>s;
		memset(alpha,0,sizeof(alpha));
		for(int i=0;i<s.length();i++)	{
			alpha[s[i]-'0']++;
		}
		string ans="";
		if(alpha[6]>=1 && alpha[5]>=1)	{
			ans+="A";
		}
		if(alpha[6]>=2)	{
			ans+="B";
		}
		if(alpha[6]>=1 && alpha[7]>=1)	{
			ans+="C";
		}
		if(alpha[6]>=1 && alpha[8]>=1)	{
			ans+="D";
		}
		if(alpha[6]>=1 && alpha[9]>=1)	{
			ans+="E";
		}
		if(alpha[7]>=1 && alpha[0]>=1)	{
			ans+="F";
		}
		if(alpha[7]>=1 && alpha[1]>=1)	{
			ans+="G";
		}
		if(alpha[7]>=1 && alpha[2]>=1)	{
			ans+="H";
		}
		if(alpha[7]>=1 && alpha[3]>=1)	{
			ans+="I";
		}
		if(alpha[7]>=1 && alpha[4]>=1)	{
			ans+="J";
		}
		if(alpha[7]>=1 && alpha[5]>=1)	{
			ans+="K";
		}
		if(alpha[7]>=1 && alpha[6]>=1)	{
			ans+="L";
		}
		if(alpha[7]>=2)	{
			ans+="M";
		}
		if(alpha[7]>=1 && alpha[8]>=1)	{
			ans+="N";
		}
		if(alpha[7]>=1 && alpha[9]>=1)	{
			ans+="O";
		}
		if(alpha[8]>=1 && alpha[0]>=1)	{
			ans+="P";
		}
		if(alpha[8]>=1 && alpha[1]>=1)	{
			ans+="Q";
		}
		if(alpha[8]>=1 && alpha[2]>=1)	{
			ans+="R";
		}
		if(alpha[8]>=1 && alpha[3]>=1)	{
			ans+="S";
		}
		if(alpha[8]>=1 && alpha[4]>=1)	{
			ans+="T";
		}
		if(alpha[8]>=1 && alpha[5]>=1)	{
			ans+="U";
		}
		if(alpha[8]>=1 && alpha[6]>=1)	{
			ans+="V";
		}
		if(alpha[8]>=1 && alpha[7]>=1)	{
			ans+="W";
		}
		if(alpha[8]>=2)	{
			ans+="X";
		}
		if(alpha[8]>=1 && alpha[9]>=1)	{
			ans+="Y";
		}
		if(alpha[9]>=1 && alpha[0]>=1)	{
			ans+="Z";
		}
		cout<<ans<<endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	scanf("%d",&t);
	while(t--)	{
		int n;
		scanf("%d",&n);
		int d=n;
		string s="";
		while(d)	{
			if(d>9)	{
				s=s+'9';
				d=d-9;
			}
			else	{
				s=s+to_string(d);
				d=0;
			}
		}
		int carry=0;
		int summ=0;
		int i=0;
//		cout<<s<<endl;
		for(;i<s.length();i++)	{
			if(s[i]=='9')	{
				summ+=0;
				if(i==s.length()-1)	{
					summ++;
				}
			}
			else	{
				summ+=(s[i]-'0'+1);
//				i++;
				break;
			}
		}
		i++;
//		cout<<summ<<endl;
		for(;i<s.length();i++)	{
			summ+=(s[i]-'0');
		}
		cout<<summ<<endl;
	}
	return 0;
}
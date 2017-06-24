#include <bits/stdc++.h>
using namespace std;
int arr[26];
int flag=0;
string s;
vector<char> vv;
void check_substring(int start,int end)	{
	int ctr=0;
	for(int i=start;i<end;i++)	{
		if(s[i]!='?')	{
			arr[s[i]-65]++;
		}
		else	{
			ctr++;
		}
	}
	for(int i=0;i<26;i++)	{
		if(arr[i]>1)	{
			return;
		}
	}
	int ctr2=0;
	for(int i=0;i<26;i++)	{
		if(arr[i]==0)	{
			ctr2++;
		}
	}
	if(ctr==ctr2)	{
		for(int i=0;i<26;i++)	{
			if(arr[i]==0)	{
				vv.push_back((char)(i+65));
			}
		}
		flag=1;
	}
}
int main()	{
	cin>>s;
	for(int i=0;i<=s.length()-26;i++)	{
		memset(arr,0,sizeof(arr));
		check_substring(i,i+26);
		if(flag==1)	{
			int ctr=0;
			for(int j=0;j<s.length();j++)	{
				if(s[j]!='?')	{
					cout<<s[j];
				}
				else	{
					if(j<i || j>i+25)	{
						cout<<"A";
					}
					else	{
						cout<<vv[ctr++];
					}
				}
			}
			break;
		}
	}
	if(flag==0)	{
		cout<<"-1";
	}
	return 0;
}
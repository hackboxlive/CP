#include <bits/stdc++.h>
using namespace std;
int pre[1000100];
string str,pat;
vector<int> occur;
void precompute()	{
	int l=pat.length();
//	cout<<"l="<<l<<endl;
	pre[0]=0;
	int j=0;
	for(int i=1;i<l;i++)	{
		if(pat[j]==pat[i])	{
			pre[i]=j+1;
			j++;
		}
		else	{
			if(j==0)	{
				pre[i]=0;
			}
			else	{
				do	{
					j=pre[j-1];
					if(pat[j]==pat[i])	{
						pre[i]=j+1;
						j++;
						break;
					}
				}while(j!=0);
				if(j==0)	{
					pre[i]=0;
				}
			}
		}
	}
	// for(int i=0;i<l;i++)	{
	// 	cout<<pre[i]<<" ";
	// }
	// cout<<endl;
}
void kmpsearch()	{
	int i=0,j=0;
	int pl=pat.length(),sl=str.length();
	while(i<sl)	{
		if(str[i]==pat[j])	{
			i++;
			j++;
			if(j==pl)	{
				occur.push_back(i-j);
				j=pre[j-1];
			}
		}
		else	{
			if(j!=0)	{
				j=pre[j-1];
			}
			else	{
				i++;
			}
		}
	}
	if(occur.empty())	{
		cout<<"Not Found\n";
		return;
	}
	cout<<(int)occur.size()<<endl;
	for(i=0;i<occur.size();i++)	{
		cout<<occur[i]+1<<" ";
	}
	cout<<endl;
}
int main()	{
	int t;
	cin>>t;
	while(t--)	{
		occur.clear();
		cin>>str>>pat;
		precompute();
		kmpsearch();
		cout<<endl;
	}
	return 0;
}
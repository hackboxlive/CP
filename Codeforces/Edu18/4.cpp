#include <bits/stdc++.h>
using namespace std;
pair<long long int,long long int> get_parent(long long int num,long long int n)	{
	long long int two=n+1;
	long long int root=two/2;
	long long int left,right;
	long long int temp;
	if(num>root)	{
		left=root;
		right=two;
	}
	else if(num<root)	{
		left=0;
		right=root;
	}
	else	{
		left=0;
		right=two;
	}
	temp=(left+right)/2;
	while(temp!=num)	{
		if(temp>num)	{
			right=temp;
		}
		if(temp<num)	{
			left=temp;
		}
		temp=(left+right)/2;
	}
	pair<long long int,long long int> val;
	val.first=left;
	val.second=right;
	return val;
}
int cntbit(long long int n)	{
	int cnt=0;
	while(n)	{
		if(n&1)	{
			cnt++;
		}
		n=n/2;
	}
	return cnt;
}
int main()	{
	long long int n;
	int q;
	long long int num;
	string s;
	long long int left,right;
	long long int temp;
	int u,v;
	cin>>n>>q;
	long long int two=n+1,root=two/2;
	pair<long long int,long long int> ans;
	while(q--)	{
		cin>>num;
		cin>>s;
		for(int i=0;i<s.length();i++)	{
//			cout<<"i="<<i<<endl;
			if(s[i]=='L' ||s[i]=='R')	{
				if(num%2==1)	{
//					i++;
					continue;
				}
			}
//			cout<<root<<endl;
			if(s[i]=='U')	{
				if(num==root)	{
//					cout<<"HERE";
//					i++;
					continue;
				}
			}
//			cout<<num<<endl;
			ans=get_parent(num,n);
//			cout<<"HERE";
//			cout<<"parent of "<<num<<"="<<ans.first<<" & "<<ans.second<<endl;
			if(s[i]=='U')	{
				u=cntbit(ans.first);
				v=cntbit(ans.second);
//				cout<<u<<" "<<v<<endl;
				if(u==v)	{
					num=ans.first;
				}
				else	{
					if(u>v)	{
						num=ans.first;
					}
					else	{
						num=ans.second;
					}
				}
			}
			if(s[i]=='L')	{
				num=(num+ans.first)/2;
			}
			if(s[i]=='R')	{
				num=(num+ans.second)/2;
			}
		}
		cout<<num<<endl;
	}
	return 0;
}
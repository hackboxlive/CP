#include <bits/stdc++.h>
using namespace std;
int ch[1010];
long long modd=1e9+7;
vector<int> bits;
vector<int> p;
long long dp[1010][1010];
long long inv[1010];
int req_bits(int n)	{
	if(ch[n]!=-1)	{
		return ch[n];
	}
	int v=n;
	int ans=0;
	while(v!=0)	{
		if(v%2==1)	{
			ans++;
		}
		v/=2;
	}
	ch[n]=req_bits(ans)+1;
	return ch[n];
}
long long pow_fast(long long n,long long v)	{
	if(v==1)	{
		return n;
	}
	if(v==0)	{
		return 1;
	}
	long long ans=pow_fast(n,v/2);
	ans=(ans*ans)%modd;
	if(v%2==1)	{
		ans=(ans*n)%modd;
	}
	return ans;
}
void choose()	{
	for(int i=1;i<=1000;i++)	{
		dp[i][1]=i;
	}
	inv[1]=1;
	for(int i=2;i<=1000;i++)	{
		inv[i]=pow_fast(i,modd-2);
	}
	for(int i=2;i<=1000;i++)	{
		for(int j=2;j<=i;j++)	{
			dp[i][j]=(dp[i][j-1]*(i-j+1))%modd;
			dp[i][j]=(dp[i][j]*inv[j])%modd;
		}
	}
}
long long choose_again(int n,int r)	{
	if(r>n)	{
		return 0;
	}
	return dp[n][r];
}
string to_binary(int n)	{
	string ans="";
	while(n!=0)	{
		ans+=to_string(n%2);
		n/=2;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
int main()	{
	choose();
	memset(ch,-1,sizeof(ch));
	ch[1]=0;
	int mm=-1;
	for(int i=2;i<=1000;i++)	{
		ch[i]=req_bits(i);
	}
	string s;
	cin>>s;
	long long k;
	cin>>k;
	if(k>5)	{
		cout<<"0\n";
		return 0;
	}
	if(k==0)	{
		cout<<"1\n";
		return 0;
	}
	if(s.compare("1")==0)	{
		cout<<"0\n";
		return 0;
	}
	if(k==1)	{
		cout<<s.length()-1<<endl;
		return 0;
	}
// 	if(s.length()<=9)	{
// 		int ppp=0;
// 		for(int i=0;i<s.length();i++)	{
// 			ppp*=2;
// 			ppp+=(s[i]-'0');
// 		}
// 		int anss=0;
// 		for(int i=1;i<=ppp;i++)	{
// 			if(ch[i]==k)	{
// //				cout<<to_binary(i)<<endl;
// 				anss++;
// 			}
// 		}
// 		cout<<anss<<endl;
// 		return 0;
// 	}
	reverse(s.begin(),s.end());
	for(int i=0;i<s.length();i++)	{
		if(s[i]=='1')	{
			bits.push_back(i+1);
		}
	}
	reverse(bits.begin(),bits.end());
	// for(int i=0;i<bits.size();i++)	{
	// 	cout<<bits[i]<<" ";
	// }
	reverse(s.begin(),s.end());
	long long ans=0;
	//finding answer for k=2,3,4,5
	int checker=k-1;
	for(int i=1;i<=1000;i++)	{
		if(ch[i]==checker)	{
//			cout<<"checking "<<i<<endl;
			if(bits.size()>=i)	{
//				cout<<i<<endl;
				ans++;
				ans%=modd;
			}
			for(int j=i;j>=1;j--)	{
				if(bits[i-j]-1<j)	{
					break;
				}
//				cout<<choose_again(bits[i-j]-1,j)<<endl;
				ans+=choose_again(bits[i-j]-1,j);
				ans%=modd;
//				cout<<ans<<endl;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
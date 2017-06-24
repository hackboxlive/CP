#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define loop(i,x,y) for(int i = x; i < y; ++i)

using namespace std;

int min (int a, int b) { return a < b ? a : b;}
int gcd(int a, int b){ return (b==0)? a : gcd(b, a%b);}
int calcDigits(long n){ int count = 0; while ( n != 0){ ++count; n/=10;} return count;}

int main(){
	do{
	long a,b;
	cin>>a>>b;
	if(a == 0 && b == 0)
		break;
	else
	{
		int ac = calcDigits(a);
		int bc = calcDigits(b);
		int a1[ac],b1[bc];
		rep(i,ac){
			a1[i] = a % 10;
			a /= 10;
		}
		rep(i,bc){
			b1[i] = b % 10;
			b /= 10;
		}
		int op = min(ac,bc);
		int count = 0;
		int carry = 0;
		rep(i,op)
		{
			int f = a1[i] + b1[i] + carry;
			if(f > 9){
				carry = 1;
				++count;
			}
			else
				carry = 0;
		}
		if(carry != 0){
			for (int i = op; i < ac; ++i)
			{
				if(a1[i] + carry > 9)
				{
					carry = 1;
					++count;
				}
				else
					break;
			}
			for (int i = op; i < bc; ++i)
			{
				if(b1[i] + carry > 9)
				{
					carry = 1;
					++count;
				}
				else
					break;
			}
		}
		if(count == 0)
			cout<<"No carry operation."<<endl;
		else if(count == 1)
			printf("1 carry operation.\n");
		else
			printf("%d carry operations.\n",count);
	}
	}while(true);
    return 0;
}
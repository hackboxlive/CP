#include <bits/stdc++.h>
using namespace std;
long long f[69][69];
void pre() {
   	f[0][0]=1;
	for(int n=1;n<64;n++) {
		f[n][0]=1;
		f[n][n]=1;
		for(int k=1;k<n;k++) {
			f[n][k]=f[n-1][k];
			for(int p=0;p<=k;p++)	{
				f[n][k]+=f[n-k-1][p];
			}
			for(int p=1;p<k;p++)	{
				f[n][k]+=f[n-p-1][k];
			}
		}
	}
}
void print() {
 	for(int n=1;n<64;n++) {
		for(int k=0;k<=n;k++) {
			cout<<f[n][k]<<" ";
		}
		cout<<endl;
	}
}
int main() {
	pre();
	print();
	return 0;
}

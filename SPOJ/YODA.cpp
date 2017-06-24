#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

long long fact(int x){
	long long ans=1;
	// cout << "X is " << x;
	while(x)
		ans*=x--;
	// cout << " and Ans is: " << ans <<'\n';
	return ans;
} 

int main(){
	char s[1000000];
	int i,numalphas[40];		//a-z0-9 36positions
	while(scanf("%s",s)!=EOF){
		// cout << s << '\n';
		for(i=0;i<26;i++)
			numalphas[i]=0;
		int len=strlen(s);
		if(len==0){
			cout << "1\n";
			continue;
		}
		for(i=0;i<len;i++){
			char c=s[i];
			if(c>='a' && c<='z')
				numalphas[c-'a']++;
			else if(c>='A' && c<='Z')
				numalphas[c-'A']++;
			else
				continue;
		}
		int tot=0,odds=0;
		long long num=1,denom=1;
		for(i=0;i<26;i++){
			if(numalphas[i])
				tot+=numalphas[i];
			if(numalphas[i]%2)
				odds++;
		}
		if(tot==0 || tot==1){
			cout << "1\n";
			continue;
		}
		if(odds>1){
			cout << "0\n";
			continue;
		}

		if(tot%2)
			num = fact((tot-1)/2);
		else
			num = fact(tot/2);

		for(i=0;i<26;i++){
			if(numalphas[i]>2)
				if(numalphas[i]%2)
					numalphas[i]--;
				denom*=fact(numalphas[i]/2);
		}
		cout << (num/denom) << '\n';
	}
	return 0;
}
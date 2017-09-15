#include <bits/stdc++.h>
using namespace std;
int main()	{
	int n=100000;
	int m=100000;
	srand(time(NULL));
	int u,v;
	// for(int j=0;j<10;j++)	{
	// 	printf("10\n%d %d 3\n",n,m);
	// 	for(int i=0;i<m;i+=3)	{
	// 		cout<<i+1<<" "<<i+2<<endl;
	// 		cout<<i+1<<" "<<i+3<<endl;
	// 		cout<<i+3<<" "<<i+2<<endl;
	// 	}
	// }
	printf("10\n");
	for(int j=0;j<1;j++)	{
		printf("%d %d 3\n",n,m);
		map<pair<int,int> , bool > mp;
		for(int i=0;i<m;)	{
			u=rand()%n;
			v=rand()%n;
			if(u==v)	{
				continue;
			}
			if(mp.find(make_pair(u,v))==mp.end())	{
				i++;
				mp[make_pair(u,v)]=true;
				mp[make_pair(v,u)]=true;
			}
			printf("%d %d\n",u+1,v+1);
		}
	}
	return 0;
}
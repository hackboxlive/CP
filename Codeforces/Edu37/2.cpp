#include <bits/stdc++.h>
using namespace std;
int l[1010],r[1010],ans[1010];
int main()	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)	{
			cin>>l[i]>>r[i];
		}
		int cur=1;
		for(int i=0;i<n;i++)	{
			// if(l[i]==r[i])	{
			// 	ans[i]=0;
			// 	continue;
			// }
			if(r[i]<cur)	{
				ans[i]=0;
			}
			else	{
				while(l[i]>cur)	{
					cur++;
				}
				ans[i]=cur;
				cur++;
			}
		}
		for(int i=0;i<n;i++)	{
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<int> odd,even,arr;
int main()	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++)	{
		odd.clear();
		even.clear();
		arr.clear();
		int n,temp;
		cin>>n;
		for(int i=0;i<n;i++)	{
			cin>>temp;
			if(i&1)	{
				odd.push_back(temp);
			}
			else	{
				even.push_back(temp);
			}
		}
		sort(odd.begin(),odd.end());
		sort(even.begin(),even.end());
		for(int i=0;i<n;i++)	{
			if(i&1)	{
				arr.push_back(odd[i/2]);
			}
			else	{
				arr.push_back(even[i/2]);
			}
		}
		int flag=-1;
		for(int i=0;i<n-1;i++)	{
			//cout<<arr[i]<<endl;
			if(arr[i]>arr[i+1])	{
				flag=i;
				break;
			}
		}
		//cout<<arr[n-1]<<endl;
		cout<<"Case #"<<tt<<": ";
		if(flag==-1)	{
			cout<<"OK";
		}
		else	{
			cout<<flag;
		}
		cout<<endl;
	}
	return 0;
}
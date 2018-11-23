#include <bits/stdc++.h>
using namespace std;

int arr[1001000];

int main()	{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)	{
		cin>>arr[i];
	}
	if(arr[1] != 0)	{
		cout << "1\n";
		return 0;
	}
	int maxx = 0;
	int impossible = -1;
	for(int i=2;i<=n;i++)	{
		if(arr[i] > maxx + 1)	{
			impossible = i;
			break;
		}
		else if(arr[i] == maxx + 1)	{
			maxx++;
		}
	}
	cout << impossible << endl;
	return 0;
}
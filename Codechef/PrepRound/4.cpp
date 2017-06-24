#include <bits/stdc++.h>
using namespace std;
int main()	{
	int t;
	cin >> t;
	int n;

	while(t--)	{
		cin >> n;

		long long int left;
		long long int right;
		long long int x1, x2, y1, y2;
		
		cin >> x1 >> y1;
		if(n==1)	{
			cout<<"no\n";
			continue;
		}
		cin >> x2 >> y2;
		
		if(n == 2)	{
			printf("yes\n");
			continue;
		}

		long long int x,y;
		
		int flag=0;
		
		for(int i=2;i<n;i++)	
		{
			cin >> x >> y;
			if(!flag)
			{
				left = (x2-x1)*(y-y1);
				right = (y2-y1)*(x-x1);
				if(left!=right)	
					flag=1;
			}
		}

		if(flag == 0)	{
			cout<<"no\n";
		}
		else	{
			cout<<"yes\n";
		}
	}
	return 0;
}
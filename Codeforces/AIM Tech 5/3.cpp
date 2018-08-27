#include <bits/stdc++.h>
using namespace std;
int n;
struct box	{
	int x1,x2,y1,y2;
}rects[132675],prefix[132675],postfix[132675];

int main()	{
	cin >> n;
	for(int i = 0; i < n; i++)	{
		cin>>rects[i].x1>>rects[i].y1>>rects[i].x2>>rects[i].y2;
	}
	box comm;
	comm.x1 = rects[0].x1;
	comm.x2 = rects[0].x2;
	comm.y1 = rects[0].y1;
	comm.y2 = rects[0].y2;
	prefix[0].x1 = comm.x1;
	prefix[0].y1 = comm.y1;
	prefix[0].x2 = comm.x2;
	prefix[0].y2 = comm.y2;

	for(int i = 1;i<n;i++)	{
		comm.x1 = max(comm.x1, rects[i].x1);
		comm.y1 = max(comm.y1, rects[i].y1);
		comm.x2 = min(comm.x2, rects[i].x2);
		comm.y2 = min(comm.y2, rects[i].y2);
		prefix[i].x1 = comm.x1;
		prefix[i].y1 = comm.y1;
		prefix[i].x2 = comm.x2;
		prefix[i].y2 = comm.y2;
	}

	comm.x1 = rects[n-1].x1;
	comm.x2 = rects[n-1].x2;
	comm.y1 = rects[n-1].y1;
	comm.y2 = rects[n-1].y2;
	postfix[n-1].x1 = comm.x1;
	postfix[n-1].y1 = comm.y1;
	postfix[n-1].x2 = comm.x2;
	postfix[n-1].y2 = comm.y2;

	for(int i = n-2;i>=0;i--)	{
		comm.x1 = max(comm.x1, rects[i].x1);
		comm.y1 = max(comm.y1, rects[i].y1);
		comm.x2 = min(comm.x2, rects[i].x2);
		comm.y2 = min(comm.y2, rects[i].y2);
		postfix[i].x1 = comm.x1;
		postfix[i].y1 = comm.y1;
		postfix[i].x2 = comm.x2;
		postfix[i].y2 = comm.y2;
	}

	if(postfix[1].x1 <= postfix[1].x2 && postfix[1].y1 <= postfix[1].y2)	{
		cout << postfix[1].x1 << " " << postfix[1].y1 << endl;
		return 0;
	}

	if(prefix[n-2].x1 <= prefix[n-2].x2 && prefix[n-2].y1 <= prefix[n-2].y2)	{
		cout << prefix[n-2].x1 << " " << prefix[n-2].y1 << endl;
		return 0;
	}

	for(int i = 1; i < n - 1; i++)	{
		comm.x1 = max(prefix[i-1].x1, postfix[i+1].x1);
		comm.y1 = max(prefix[i-1].y1, postfix[i+1].y1);
		comm.x2 = min(prefix[i-1].x2, postfix[i+1].x2);
		comm.y2 = min(prefix[i-1].y2, postfix[i+1].y2);

		if(comm.x1 <= comm.x2 && comm.y1 <= comm.y2)	{
			cout << comm.x1 << " " << comm.y1 << endl;
			break;
		}
	}
	return 0;
}
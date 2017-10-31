#include <bits/stdc++.h>
using namespace std;

int n,k,e,xo,yo;
struct node	{
	int x;
	int y;
	double dist;
	double p;
}arr[101];
double dp[101][101];
double get_dist(int x1,int y1,int x2,int y2)	{
//	cout<<"got it";
	return sqrt((double)(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double prob(double r)	{
	if(r==0.0)	{
		for(int i=0;i<n;i++)	{
			if(arr[i].x==xo && arr[i].y==yo)	{
				arr[i].p=1.0;
			}
			else	{
				arr[i].p=0.0;
			}
		}
	}
	else	{
		for(int i=0;i<n;i++)	{
			if(arr[i].dist<=r)	{
				arr[i].p=1.0;
			}
			else	{
				arr[i].p=exp(1 - (arr[i].dist*arr[i].dist)/(r*r));
			}
		}
	}
	for(int i=0;i<=n;i++)	{
		for(int j=0;j<=n;j++)	{
			dp[i][j]=0.0;
		}
	}
	dp[0][0]=1.0;
	for(int i=1;i<=n;i++)	{
		for(int j=0;j<=i;j++)	{
			if(j==0)	{
				dp[i][j]=(1.0-arr[i-1].p)*dp[i-1][j];
			}
			else	{
				dp[i][j]=arr[i-1].p*dp[i-1][j-1]+(1.0-arr[i-1].p)*dp[i-1][j];
			}
		}
	}
	double ans=0.0;
	for(int i=k;i<=n;i++)	{
		ans+=dp[n][i];
	}
	return ans;
}
int main()	{
	cin>>n;
	cin>>k>>e;
	cin>>xo>>yo;
	double d=-1.0;
	for(int i=0;i<n;i++)	{
		cin>>arr[i].x>>arr[i].y;
		arr[i].dist=get_dist(xo,yo,arr[i].x,arr[i].y);
//		cout<<arr[i].dist<<endl;
		d=max(d,arr[i].dist);
	}
	double hi=d,mid,lo=0.0;
	double ep=1.0;
	ep-=((double)e/1000);
	int lt=100;
	while(lt--)	{
		mid=lo+(hi-lo)/2;
//		printf("%.8lf %.8lf %.8lf\n",lo,mid,hi);
//		getchar();
		d=prob(mid);
//		cout<<d<<endl;
		if(d>=ep)	{
			hi=mid;
		}
		else	{
			lo=mid+0.000000001;
		}
	}
	printf("%.11lf\n",lo);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
double prob[110];
double fast_exp(double base, int exp)
{
    if(exp==1)
    return base;
    else
    {
        if(exp%2 == 0)
        {
            double base1 = pow(fast_exp(base, exp/2),2);
            return base1;
        }
        else
        {
            double ans = (base*  pow(fast_exp(base,(exp-1)/2),2));
            return ans;
        }
    }
}
int main()	{
	int n,x;
	cin>>n>>x;
	for(int i=0;i<=x;i++)	{
		cin>>prob[i];
	}
	double sum=0.0;
	for(int i=0;i<=x;i++)	{
		sum=sum+fast_exp(prob[i],n);
	}
	cout<<(double)(1.0-sum)<<endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
long long dp[110][110];
long long solve(int balls,int boxes)  {
    if(dp[balls][boxes]!=-1)    {
        return dp[balls][boxes];
    }
    if(boxes==1)    {
        return dp[balls][boxes]=1;
    }
    long long ans=0;
    for(int i=0;i<balls;i++)    {
        ans=ans+solve(i,boxes-1);
        ans=ans%761238923;
    }
    if(balls!=boxes)    {
        ans=ans+solve(balls,boxes-1);
        ans=ans%761238923;
    }
    return dp[balls][boxes]=ans;
}
int main()  {
    int n;
    cin>>n;
    for(int i=0;i<110;i++)  {
        for(int j=0;j<110;j++)  {
            dp[i][j]=-1;
        }
    }
    while(n!=0) {
        cout<<solve(n,n)<<endl;
        cin>>n;
    }
    return 0;
}

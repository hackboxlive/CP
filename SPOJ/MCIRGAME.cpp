#include <bits/stdc++.h>
using namespace std;
string dp[160][160];
string addstrings(string s1,string s2)  {
//    cout<<"Adding string "<<s1<<" "<<s2<<endl;
    if(s1.length()<s2.length()) {
        swap(s1,s2);
    }
    string ans="";
    int diff=s1.length()-s2.length();
    for(int i=0;i<diff;i++) {
        s2="0"+s2;
    }
    int m,n,c=0;
    for(int i=s1.length()-1;i>=0;i--) {
        m=s1[i]-'0';
        n=s2[i]-'0';
//        cout<<m<<" "<<n<<" "<<c<<endl;
        m=m+n+c;
        c=0;
        if(m>9) {
            c=m/10;
            m=m%10;
        }
//        cout<<m<<endl;
        ans=to_string(m)+ans;
//        cout<<ans<<endl;
    }
    if(c!=0)    {
        ans=to_string(c)+ans;
    }
//    cout<<"Ans = "<<ans<<endl;
    return ans;
}
string solve(int balls,int boxes)  {
    if(dp[balls][boxes].compare("-1")!=0)    {
        return dp[balls][boxes];
    }
    if(boxes==1)    {
        return dp[balls][boxes]="1";
    }
    string ans="0";
    for(int i=0;i<balls;i++)    {
        ans=addstrings(ans,solve(i,boxes-1));
    }
    if(balls!=boxes)    {
        ans=addstrings(ans,solve(balls,boxes-1));
    }
    return dp[balls][boxes]=ans;
}
int main()  {
    int n;
    cin>>n;
    for(int i=0;i<160;i++)  {
        for(int j=0;j<160;j++)  {
            dp[i][j]="-1";
        }
    }
    while(n!=-1) {
        cout<<solve(n,n)<<endl;
        cin>>n;
    }
    return 0;
}

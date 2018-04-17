#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
struct node    {
    int o_z;
    int l;
    int r;
};
int main()  {
    int t;
    cin>>t;
    while(t--)  {
        int n;
        cin>>n;
        arr.clear();
        int temp;
        arr.push_back(2);
        for(int i=0;i<n;i++)    {
            cin>>temp;
            arr.push_back(temp);
        }
        arr.push_back(2);
        int l=1,r=0;
        node tmp;
        vector<node> oz;
        for(int i=1;i<=n+1;i++)   {
            if(arr[i]==arr[i-1])    {
                r++;
            }
            else    {
                if(arr[i-1]==1) {
                    tmp.o_z=1;
                    tmp.l=l;
                    tmp.r=r;
                    oz.push_back(tmp);
                }
                if(arr[i-1]==0) {
                    tmp.o_z=0;
                    tmp.l=l;
                    tmp.r=r;
                    oz.push_back(tmp);
                }
                l=i;
                r=i;
            }
        }
        // for(int i=0;i<oz.size();i++)    {
        //     cout<<oz[i].o_z<<" "<<oz[i].l<<" "<<oz[i].r<<endl;
        // }
        int ans=-1;
        for(int i=0;i<oz.size();i++)    {
            if(oz[i].o_z==0)    {
                int temp=oz[i].r-oz[i].l+1;
                if(i+1<oz.size())   {
                    temp+=oz[i+1].r-oz[i+1].l+1;
                }
                if(i-1>=0)  {
                    temp+=oz[i-1].r-oz[i-1].l+1;
                }
                if(i-2>=0)  {
                    temp+=oz[i-2].r-oz[i-2].l+1;
                }
                ans=max(ans,temp);
            }
            if(oz[i].o_z==1)    {
                int temp=oz[i].r-oz[i].l+1;
                if(i-1>=0)  {
                    temp+=oz[i-1].r-oz[i-1].l+1;
                }
                if(i+1<oz.size())   {
                    temp+=oz[i+1].r-oz[i+1].l+1;
                }
                if(i+2<oz.size())   {
                    temp+=oz[i+2].r-oz[i+2].l+1;
                }
                ans=max(ans,temp);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
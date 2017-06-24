#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int arr[100100];
long long int subArraySum(int n, long long int sum)
{
    map<long long int, vector<int> > map;
    long long int curr_sum = 0;
    long long int ctr=0;
    for (int i = 0; i < n; i++)
    {
        curr_sum = curr_sum + arr[i];
        if (curr_sum == sum)
        {
 //           cout<<0<<" to "<<i<<endl;
            ctr++;
        }
        if (map.find(curr_sum - sum) != map.end())
        {
            ctr+=(int)map[curr_sum-sum].size();
            //cout<<map[curr_sum-sum]+1<<" to "<<i<<endl;
            //ctr++;
        }
//        map[curr_sum] = i;
        map[curr_sum].push_back(i);
    }
    return ctr;
}
int main()
{
    long long int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)    {
        cin>>arr[i];
    }
    long long int MAXX=1e15,MINN=1e15;
    MINN*=-1;
    long long int val=1;
    long long int ctr=0;
    if(k==1)    {
        ctr+=subArraySum(n,1);
        cout<<ctr<<endl;
        return 0;
    }
    if(k==-1)   {
        ctr+=subArraySum(n,-1);
        ctr+=subArraySum(n,1);
        cout<<ctr<<endl;
        return 0;
    }
    while(val<=MAXX && val>=MINN)    {
        ctr+=subArraySum(n,val);
        val=val*k;
    }
    cout<<ctr<<endl;
    return 0;
}
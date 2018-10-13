#include <bits/stdc++.h>
using namespace std;

vector<long long> primes;
set<long long> pp1;
int p[2002000];
vector<long long> leftest;
map<long long, long long> fact;
map<long long, long long> vvvl;
void sieve()    {
    for(int i = 2; i <= 2000000; i++)   {
        if(p[i] == 0)   {
            primes.push_back(i);
            pp1.insert(i);
            for(int j = 2 * i; j <= 2000000; j += i)    {
                p[j] = 1;
            }
        }
    }
}

bool func() {
    long long mat[505][505];
    set<long long> s;
    for(map<long long, long long>::iterator it = fact.begin(); it != fact.end(); it++)  {
        for(int j=0;j<leftest.size();j++)   {
            if(leftest[j]%it->first==0) {
                fact[it->first]++;
                fact[leftest[j]/it->first]++;
                leftest[j]=1;
            }
        }
    }
    for(int i=0;i<leftest.size();i++)  {
        for(int j=i+1;j<leftest.size();j++)    {
            mat[i][j]=__gcd(leftest[i], leftest[j]);
            if(mat[i][j] > 1 && mat[i][j] != leftest[i])   {
                s.insert(mat[i][j]);
            }
        }
    }
    for(set<long long>::iterator it = s.begin();it!=s.end();it++) {
        long long temp = *it;
        //cout << temp << endl;
        for(int i = 0; i < leftest.size();i++) {
            if(leftest[i]%temp == 0)   {
                fact[temp]++;
                fact[leftest[i]/temp]++;
                leftest[i]=1;
            }
        }
    }
    for(int i = 0;i<leftest.size();i++)    {
        if(leftest[i]!=1)  {
            vvvl[leftest[i]]++;
        }
    }
}
int main()  {
    sieve();
    int n;
    cin >> n;
    long long vv;
    long long temp, temp2;
    for(int i = 0; i < n; i++)  {
        cin >> vv;
        temp = sqrt(vv);
        if(temp * temp == vv)   {
            temp2 = sqrt(temp);
            if(temp2 * temp2 == temp)   {
                fact[temp2] += 4;
            }
            else    {
                fact[temp] += 2;
            }
        }
        else    {
            bool check = false;
            for(int i = 0; i < primes.size(); i++)  {
                temp = primes[i] * primes[i] * primes[i];
                if(temp == vv)  {
                    check = true;
                    fact[primes[i]] += 3;
                    break;
                }
                if(temp > vv)   {
                    break;
                }
            }
            if(check == false)  {
                leftest.push_back(vv);
            }
        }
    }
    func();
    long long ans = 1;
    for(map<long long, long long>::iterator it = fact.begin(); it != fact.end(); it++) {
        //cout << it->first << " " << it->second << "\n";
        temp = it -> second;
        ans *= (temp + 1);
        ans %= 998244353;
    }
    for(map<long long, long long>::iterator it = vvvl.begin(); it != vvvl.end(); it++) {
        ans *= (it->second + 1)*(it->second + 1);
        ans %= 998244353;
    }
    cout << ans << endl;
    cout.flush();
    return 0;
}
#include <iostream>

template<typename T>
void read(T& _val)
{
    std::cin >> _val;
}

template<typename T, typename... Args>
void read(T& _val, Args&... _args)
{
    std::cin >> _val;
    read(_args...);
}

template<typename T>
void print(const T& _val)
{
    std::cout << _val << std::endl;
}

template<typename T, typename... Args>
void print(const T& _val, const Args&... _args)
{
    std::cout << _val << " ";
    print(_args...);
}

/*
*   Main starts below
*/

#include <unordered_map>

int main()
{
    int n;read(n);
    long long prefix[200200];
    prefix[0] = 0;
    std::unordered_map<int, int> mp;
    long long x;
    long double ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        read(x);
        ans += x * (i - 1) - prefix[i - 1];
        ans -= mp[x - 1];
        ans += mp[x + 1];
        //print(ans);
        mp[x]++;
        prefix[i] = prefix[i - 1] + x;
    }
    //print(ans);
    printf("%0.Lf", ans);
}
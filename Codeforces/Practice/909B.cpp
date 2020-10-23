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
#include <cstring>

int dp[101];
int solve(int n)
{
    if(n == 1 || n == 2)
    {
        return n;
    }
    if(dp[n] != -1)
    {
        return dp[n];
    }
    return n + solve(n - 2);
}

int main()
{
    int n;
    read(n);
    memset(dp, -1, sizeof(dp));
    print(solve(n));
}
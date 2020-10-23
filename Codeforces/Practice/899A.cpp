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

int main()
{
    int n;read(n);
    int x;
    int one = 0, two = 0;
    while(n--)
    {
        read(x);
        if(x == 1)
        {
            one++;
        }
        else
        {
            two++;
        }
    }
    int ans = 0;
    if(two <= one)
    {
        ans += two;
        one -= two;
        ans += one / 3;
    }
    else
    {
        ans += one;
    }
    print(ans);
}
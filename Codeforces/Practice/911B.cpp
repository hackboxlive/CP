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
    int n, a, b;
    read(n, a, b);

    int ans = 0;
    int ans_x = -1;
    for(int x = 1; x < n; x++)
    {
        ans = std::max(ans, std::min(a / x, b / (n - x)));
        //print(a / x, b / (n - x));
    }
    print(ans);
}
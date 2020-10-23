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
    std::unordered_map<int, int> mp;
    int n;read(n);
    int x;
    while(n--)
    {
        read(x);
        mp[x]++;
    }
    int gt = 0;
    for(auto it : mp)
    {
        if(it.second > gt)
        {
            gt = it.second;
        }
    }
    print(gt);
}
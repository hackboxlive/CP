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

#include <vector>

int main()
{
    std::vector<int> expand_3;
    for(int i = 0; i * 3 <= 100; i++)
    {
        expand_3.push_back(i * 3);
    }
    std::vector<int> expand_7;
    for(int i = 0; i * 7 <= 100; i++)
    {
        expand_7.push_back(i * 7);
    }
    int t;
    read(t);
    while(t--)
    {
        int x;
        read(x);
        std::string ans = "NO";
        for(auto i : expand_3)
        {
            for(auto j : expand_7)
            {
                if(i + j == x)
                {
                    ans = "YES";
                }
            }
        }
        print(ans);
    }
}
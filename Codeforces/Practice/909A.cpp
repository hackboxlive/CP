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
    std::string first, last;
    read(first, last);

    if(first.size() == 1)
    {
        print(first.substr(0, 1) + last[0]);
        return 0;
    }
    int i = 1;
    for(; i < first.size(); ++i)
    {
        if(first[i] >= last[0])
        {
            break;
        }
    }
    print(first.substr(0, i) + last[0]);
}
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
    int n;
    read(n);
    std::vector<int> arr;
    int x; int minn = 1e9;
    for(int i = 0; i < n; ++i)
    {
        read(x);
        arr.push_back(x);
        minn = std::min(minn, x);
    }
    std::vector<int> id;
    for(int i = 0; i < n; ++i)
    {
        if(arr[i] == minn)
        {
            id.push_back(i);
        }
    }
    minn = 1e9;
    for(int i = 1; i < id.size(); ++i)
    {
        minn = std::min(minn, id[i] - id[i - 1]);
    }
    print(minn);
}
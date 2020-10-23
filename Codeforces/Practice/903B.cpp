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
    int h1, a1, c1;
    read(h1, a1, c1);
    int h2, a2;
    read(h2, a2);

    std::vector<std::string> moves;
    while(h2 > 0)
    {
        if(h1 > a2 || h2 <= a1)
        {
            moves.push_back("STRIKE");
            h2 -= a1;
        }
        else
        {
            moves.push_back("HEAL");
            h1 += c1;
        }
        
        h1 -= a2;
    }
    print(moves.size());
    for(auto& i : moves)
    {
        print(i);
    }
}
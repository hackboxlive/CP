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
    int seq[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int n;
    std::vector<int> pattern;
    for(int year = 1; year <= 600; ++year)
    {
        if(year % 4 == 0)
        {
            if(year % 100 != 0 || year % 400 == 0)
            {
                seq[1] = 29;
            }
        }
        for(int month = 0; month < 12; month++)
        {
            pattern.push_back(seq[month]);
        }
        seq[1] = 28;
    }
    read(n);
    std::vector<int> inp;
    for(int i = 0; i < n; ++i)
    {
        int x;
        read(x);
        inp.push_back(x);
    }
    std::string ans = "No";
    for(int i = 0; i < pattern.size() - n; ++i)
    {
        if(pattern[i] == inp[0])
        {
            int mch = 1;
            for(int j = 1; j < n; ++j)
            {
                if(inp[j] == pattern[i + j])
                {
                    mch++;
                }
                else
                {
                    break;
                }
                
            }
            if(mch == n)
            {
                ans = "Yes";
                break;
            }
        }
    }
    print(ans);
}
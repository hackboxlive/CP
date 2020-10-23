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
    long long k, a, b;
    read(k);
    read(a);
    read(b);

    long long ans_a = 0;
    if(a < 0)
    {
        ans_a = (-1 * a) / k + 1;
    }
    else
    {
        ans_a = a / k + 1;
    }
    
    long long ans_b = 0;
    if(b < 0)
    {
        ans_b = (-1 * b) / k + 1;
    }
    else
    {
        ans_b = b / k + 1;
    }

    if(a < 0 && b > 0)
    {
        print(ans_a + ans_b - 1);
    }
    else
    {
        long long ans = llabs(ans_a - ans_b);
        if(b <= 0 && (-1 * b) % k == 0)
        {
            ans++;
        }
        if(a >= 0 && b != 0 && a % k == 0)
        {
            ans++;
        }
        print(ans);
    }
}
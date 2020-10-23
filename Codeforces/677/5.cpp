#include <iostream>

template<typename T>
void read(T& _val)
{
    std::cin >> _val;
}

template<typename T>
void print(const T& _val)
{
    std::cout << _val << std::endl;
}

int main()
{
    unsigned long long n;
    read(n);
    unsigned long long ans = 1;
    for(int i = 1; i < n / 2; ++i)
    {
        ans *= i;
    }
    ans = ans * ans;
    unsigned long long ncn = 1;
    for(int i = 1; i <= n / 2; ++i)
    {
        ncn *= (n + 1 - i);
    }
    for(int i = 1; i <= n / 2; ++i)
    {
        ncn = ncn / i;
    }
    ncn = ncn / 2;
    ans = ans * ncn;
    print(ans);
}
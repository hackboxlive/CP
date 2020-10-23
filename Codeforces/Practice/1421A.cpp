#include <iostream>

int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        long long a, b;
        std::cin >> a >> b;
        long long temp_a = a;
        long long temp_b = b;
        long long ans = 0;
        for(int i = 0; a != 0 || b != 0; i++)
        {
            if(a & 1 && b & 1)
            {
                ans |= (1 << i);
            }
            a = a >> 1;
            b = b >> 1;
        }
        //std::cout << ans << std::endl;
        //std::cout << (temp_a ^ ans) << std::endl;
        std::cout << (temp_a ^ ans) + (temp_b ^ ans) << std::endl;
    }
}
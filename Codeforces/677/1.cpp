#include <iostream>

template<typename T>
void read(T& _val)
{
    std::cin >> _val;
}

template<typename T>
void print(T& _val)
{
    std::cout << _val << std::endl;
}

int main()
{
    int t;
    read(t);
    while(t--)
    {
        int n;
        read(n);
        int dig = 1;
        int room = 1;
        int ctr = 1;
        int ans = 1;
        while(room != n)
        {
            room = room * 10 + dig;
            ctr++;
            if(room > 10000)
            {
                dig++;
                room = 0;
                ctr = 0;
            }
            ans += ctr;
        }
        print(ans);
    }

}
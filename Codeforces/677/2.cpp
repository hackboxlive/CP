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
    int t;
    read(t);
    while(t--)
    {
        int n;
        read(n);
        int arr[60];
        int num0 = 0;
        for(int i = 0; i < n; ++i)
        {
            read(arr[i]);
            if(arr[i] == 0)
            {
                num0++;
            }
        }
        int first1 = -1;
        for(int i = 0; i < n; ++i)
        {
            if(arr[i] == 1)
            {
                first1 = i;
                break;
            }
        }
        int last1 = -1;
        for(int i = n - 1; i >= 0; --i)
        {
            if(arr[i] == 1)
            {
                last1 = i;
                break;
            }
        }
        if(first1 == -1)
        {
            print(0);
        }
        else
        {
            print(num0 - first1 - (n - 1 - last1));
        }
    }
}
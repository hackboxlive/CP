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
    int arr[400400];
    while(t--)
    {
        int n;
        read(n);

        int maxval = 0;
        int maxidx = -1;
        for(int i = 0; i < n; ++i)
        {
            read(arr[i]);
            if(arr[i] > maxval)
            {
                maxidx = i;
                maxval = arr[i];
            }
        }
        bool all_same = true;
        int ans = -1;
        for(int i = maxidx + 1; i < n; ++i)
        {
            if(arr[i] != maxval)
            {
                ans = i - 1;
                all_same = false;
                break;
            }
        }
        for(int i = maxidx - 1; i >= 0; --i)
        {
            if(arr[i] != maxval)
            {
                ans = i + 1;
                all_same = false;
                break;
            }
        }
        if(all_same)
        {
            print(-1);
        }
        else
        {
            print(ans + 1);
        }
        
    }
}
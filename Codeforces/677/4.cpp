#include <iostream>
#include <sstream>

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
        int arr[5050];
        for(int i = 0; i < n; ++i)
        {
            read(arr[i]);
        }
        bool all_same = true;
        for(int i = 1; i < n; ++i)
        {
            if(arr[i] != arr[0])
            {
                all_same = false;
            }
        }
        if(all_same)
        {
            print("NO");
        }
        else
        {
            print("YES");
            int diffidx = -1;
            for(int i = 1; i < n; ++i)
            {
                if(arr[i] != arr[0])
                {
                    diffidx = i;
                    std::stringstream ss;
                    ss << i + 1 << " " << 1;
                    print(ss.str());
                }
            }
            for(int i = 1; i < n; ++i)
            {
                if(i != diffidx && arr[i] == arr[0])
                {
                    std::stringstream ss;
                    ss << i + 1 << " " << diffidx + 1;
                    print(ss.str());
                }
            }
        }
        
    }
}
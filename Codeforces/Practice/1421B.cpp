#include <iostream>
#include <vector>

template<typename T>
void read(T& _val)
{
    std::cin >> _val;
}

int main()
{
    int t;
    read(t);
    while(t--)
    {
        int n;
        read(n);
        char mat[200][200];
        for(int i = 0; i < n; ++i)
        {
            std::string s;
            read(s);
            for(int j = 0; j < n; ++j)
            {
                mat[i][j] = s[j];
            }
        }
        int s0 = 0;
        int s1 = 0;
        int f0 = 0;
        int f1 = 0;
        for(int i = 0; i < 2; ++i)
        {
            if(mat[i][1 - i] == '0')
                s0++;
            else
                s1++;
            if(mat[n - 1 - i][n - 2 + i] == '0')
                f0++;
            else
                f1++;
        }
        if(s0 + f0 < s1 + f1)
        {
            int ans = 0;
            std::vector<std::pair<int, int>> vals;
            if(mat[0][1] == '1')
        }
    }
}
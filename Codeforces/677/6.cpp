
#include <iostream>
#include <bits/stdc++.h>

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

int mat[100][100];
int n, m, k;
int dp[75][75][75][75];

int solve(int i, int j, int cnt, int rem)
{
    if(dp[i][j][cnt][rem] != -1)
    {
        return dp[i][j][cnt][rem];
    }
    if(cnt > m / 2)
    {
        return -1e9;
    }
    if(j == m)
    {
        i++;
        j = 0;
        cnt = 0;
    }
    if(i == n)
    {
        if(rem == 0)
        {
            return 0;
        }
        else
        {
            return -1e9;
        }
    }
    dp[i][j][cnt][rem] = std::max(solve(i, j + 1, cnt, rem), solve(i, j + 1, cnt + 1, (rem + mat[i][j]) % k) + mat[i][j]);
    return dp[i][j][cnt][rem];
}

int main()
{
    read(n);
    read(m);
    read(k);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            read(mat[i][j]);
        }
    }
    memset(dp, -1, sizeof(dp));
    print(solve(0, 0, 0, 0));
}
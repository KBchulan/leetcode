#include <bits/stdc++.h>

using namespace std;

int64_t C(int64_t n, int64_t m)
{
    if (m == 0 || n == m)
        return 1;

    return C(n - 1, m) + C(n - 1, m - 1);
}

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = 1;
        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (j == 0 && i == 0)
                    continue;
                if (i)
                    dp[i][j] += dp[i - 1][j];
                if (j)
                    dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
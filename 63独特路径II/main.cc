#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1)
            return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = 1;
        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    continue;

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

std::ostream &operator<<(std::ostream &os, vector<vector<int>> &obstacleGrid)
{
    os << Solution::uniquePathsWithObstacles(obstacleGrid);
    return os;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<int>> nums = {
        {0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

    cout << nums << endl;
}
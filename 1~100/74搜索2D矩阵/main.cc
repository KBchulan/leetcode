#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        for (size_t i = 0; i < m; i++)
        {
            if (matrix[i][n - 1] >= target)
            {
                for (size_t j = 0; j < n; j++)
                {
                    if (matrix[i][j] == target)
                        return true;
                }
                return false;
            }
        }

        return false;
    }
};


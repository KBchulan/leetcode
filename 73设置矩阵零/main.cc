#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<pair<int, int>> points;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                    points.push_back(make_pair(i, j));
            }
        }
        for (const auto &point : points)
        {
            setLine(point.first, matrix);
            setTie(point.second, matrix);
        }
    }

    void setLine(int i, vector<vector<int>> &matrix)
    {
        for (int m = 0; m < matrix[0].size(); m++)
            matrix[i][m] = 0;
    }

    void setTie(int j, vector<vector<int>> &matrix)
    {
        for (int m = 0; m < matrix.size(); m++)
            matrix[m][j] = 0;
    }
};
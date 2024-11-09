#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int row = 0, col = -1, dir = 1;
        vector<int> result;

        while (rows > 0 && cols > 0)
        {
            for (int i = 0; i < cols; i++)
            {
                col += dir;
                result.push_back(matrix[row][col]);
            }
            rows--;

            for (int i = 0; i < rows; i++)
            {
                row += dir;
                result.push_back(matrix[row][col]);
            }

            cols--;
            dir *= -1;
        }
        return result;
    }
};

int main()
{
    vector<vector<int>> nums = {
        {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    vector<int> res = Solution::spiralOrder(nums);
    for (const auto &num : res)
        cout << num << " ";
}
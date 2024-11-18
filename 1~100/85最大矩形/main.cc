#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxArea = 0;

        for (int i = 0; i < m; i++)
        {
            // 更新每列的高度
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            // 计算当前行构成的直方图中的最大矩形面积
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

private:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> stk;

        // 计算左边界
        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && heights[stk.top()] >= heights[i])
            {
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        // 清空栈
        while (!stk.empty())
            stk.pop();

        // 计算右边界
        for (int i = n - 1; i >= 0; i--)
        {
            while (!stk.empty() && heights[stk.top()] >= heights[i])
            {
                stk.pop();
            }
            right[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }

        // 计算最大面积
        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            maxArea = max(maxArea, heights[i] * (right[i] - left[i] - 1));
        }

        return maxArea;
    }
};
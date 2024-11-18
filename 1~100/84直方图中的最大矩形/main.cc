#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> stk;

        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && heights[stk.top()] >= heights[i])
            {
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        while (!stk.empty())
            stk.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!stk.empty() && heights[stk.top()] >= heights[i])
            {
                stk.pop();
            }
            right[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            maxArea = max(maxArea, heights[i] * (right[i] - left[i] - 1));
        }

        return maxArea;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> nums = {2, 1, 5, 6, 2, 3};
    cout << Solution::largestRectangleArea(nums) << endl;
}
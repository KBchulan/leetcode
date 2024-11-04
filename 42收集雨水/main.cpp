#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static int trap(vector<int> &height)
    {
        if (height.size() < 3)
            return 0;

        int size = height.size();
        vector<int> left(size);
        vector<int> right(size);
        left[0] = height[0];
        right[size - 1] = height[size - 1];

        int ans = 0;
        for (auto i = 1; i < size; i++)
            left[i] = max(left[i - 1], height[i]);

        for (auto i = size - 2; i >= 0; i--)
            right[i] = max(right[i + 1], height[i]);

        for (auto i = 1; i < size - 1; i++)
            ans += min(left[i], right[i]) - height[i];
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << Solution::trap(nums) << endl;
}
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static int jump(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        vector<int> steps(nums.size());
        int leval = 0;
        for (size_t i = 0; i < nums.size() - 1; i++)
        {
            steps[leval + 1] = max(steps[leval + 1], static_cast<int>(i + nums[i]));
            if (i == steps[leval])
                leval++;
        }
        return leval;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << Solution::jump(nums) << endl;
}
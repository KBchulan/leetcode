#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static int maxSubArray(vector<int> &nums)
    {
        int resNum = INT_MIN;
        int currentSum = 0;

        for (auto i = 0; i < nums.size(); i++)
        {
            currentSum = max(nums[i], currentSum + nums[i]);
            resNum = max(resNum, currentSum);
        }
        return resNum;
    }
};

int main()
{
    vector<int> nums = {-3, -2, -2, -3};
    cout << Solution::maxSubArray(nums) << endl;
}
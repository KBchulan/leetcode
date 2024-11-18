#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static bool canJump(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return true;
        if (nums.size() == 2)
        {
            if (nums[0] > 0)
                return true;
            return false;
        }

        vector<bool> canMove(nums.size(), false);
        canMove[0] = true;
        for (auto i = 0; i < nums.size(); i++)
        {
            if (canMove[i])
                for (auto j = i; j <= i + nums[i] && j < nums.size(); j++)
                    canMove[j] = true;
            if(canMove[nums.size() - 1])
                return true;
        }

        return false;
    }
};

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << Solution::canJump(nums) << endl;
    return 0;
}
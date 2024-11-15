#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return nums.size();

        int count = 1;
        int currentNum = nums[0];

        auto newEnd = std::remove_if(nums.begin() + 1, nums.end(),
                                     [&](int num)
                                     {
                                         if (num == currentNum)
                                         {
                                             count++;
                                             return count >= 3;
                                         }
                                         else
                                         {
                                             currentNum = num;
                                             count = 1;
                                             return false;
                                         }
                                     });

        nums.erase(newEnd, nums.end());
        return nums.size();
    }
};
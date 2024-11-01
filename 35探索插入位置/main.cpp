#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static int searchInsert(vector<int> &nums, int target)
    {
        for(auto i = 0; i < nums.size(); i++){
            if(nums[i] >= target)
                return i;
        }
        return nums.size();
    }
};

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    cout << Solution::searchInsert(nums, target) << endl;
}
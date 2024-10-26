//
// Created by whx on 24-10-26.
//

#include <vector>

class Solution {
public:
    static int removeDuplicates(std::vector<int>& nums) {
        int result = 1;
        for (auto i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[i - 1])
                nums[result++] = nums[i];
        }
        return result;
    }
};
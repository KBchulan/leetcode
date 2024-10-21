//
// Created by whx on 24-10-21.
//

#include <set>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static int threeSumClosest(vector<int>& nums, const int& target) {
        sort(nums.begin(), nums.end());
        unsigned long idx = 0;
        int result = 800000;

        while (idx < nums.size() - 2) {
            unsigned long left = idx + 1,
                          right = nums.size() - 1;

            while(left < right) {
                const int sum = nums[idx] + nums[left] + nums[right];
                result = abs(result - target) > abs(target - sum) ? sum :result;
                if(sum < target)
                    left++;
                else if(sum > target)
                    right--;
                else
                    return result;
            }
            idx++;
        }

        return result;
    }
};

int main(int argc, char **argv) {
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}
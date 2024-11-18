//
// Created by whx on 24-10-22.
//

#include <vector>
#include <iostream>

class Solution {
    using ll = long long;
public:
    static std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        int len = nums.size();
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;

        for(auto i = 0; i < len - 3; i++) {
            for(auto j = i + 1; j < len - 2; j++) {
                const ll newTarget = static_cast<ll>(target) - static_cast<ll>(nums[i]) - static_cast<ll>(nums[j]);
                int left = j + 1,
                    right = len - 1;
                while (left < right) {
                    if(nums[left] + nums[right] < newTarget)
                        left++;
                    else if(nums[left] + nums[right] > newTarget)
                        right--;
                    else {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        const int tmp1 = left;
                        const int tmp2 = right;
                        while(left < right && nums[left] == nums[tmp1])left++;
                        while(left < right && nums[right] == nums[tmp2])right--;
                    }
                }
                while(j + 1 < len && nums[j] == nums[j + 1]) j++;
            }
            while(i + 1 < len && nums[i] == nums[i + 1]) i++;
        }
        return result;
    }
};

int main(int argc, char **argv) {
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

}
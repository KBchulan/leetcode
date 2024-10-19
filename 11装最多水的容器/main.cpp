//
// Created by whx on 24-10-19.
//

#include <vector>
#include <iostream>

class Solution {
public:
    static int maxArea(const std::vector<int>& height) {
        int left = 0;
        int right = static_cast<int>(height.size() - 1);
        int res = -1;

        while(left < right) {
            int current = std::min(height[left], height[right]) * (right - left);

            res = std::max(res, current);

            if(height[left] < height[right])
                left++;
            else if(height[left] == right) {
                left++;
                right--;
            }
            else right--;
        }
        return res;
    }
};

int main() {
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    const std::vector<int> nums = {1,8,6,2,5,4,8,3,7};

    std::cout << Solution::maxArea(nums) << std::endl;
}
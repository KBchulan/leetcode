//
// Created by whx on 24-10-21.
//

#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    static vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unsigned long idx = 0;
        set<vector<int>> s;
        std::vector<std::vector<int>> result;

        while (idx < nums.size()) {
            unsigned long left = idx + 1,
                          right = nums.size() - 1;
            while(left < right) {
                if(nums[idx] + nums[left] + nums[right] == 0) {
                    s.insert({nums[idx], nums[left], nums[right]});
                    left++;
                    right--;
                }
                else if(nums[idx] + nums[left] + nums[right] < 0) {
                    left++;
                }
                else
                    right--;
            }
            idx++;
        }
        result.reserve(s.size());
        for(const auto& aaa : s)
            result.push_back(aaa);
        return result;
    }
};

int main(int argc,char **argv) {
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);


}
//
// Created by whx on 24-10-15.
//

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums,const int target) {
        int idx = 0;
        vector<int> result;
        unordered_map<int ,int> num_idx;

        for(const auto& num : nums) {

            if(num_idx.find(target - num) != num_idx.end()) {
                result.emplace_back(num_idx[target - num]);
                result.push_back(idx);
                return result;
            }

            num_idx[num] = idx++;
        }
        return initializer_list<int>();
    }
};

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> nums = {3,2,4};
    constexpr int target = 6;
    cout << Solution::twoSum(nums, target).front() << Solution::twoSum(nums, target).back() << endl;
}
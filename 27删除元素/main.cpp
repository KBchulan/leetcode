//
// Created by whx on 24-10-27.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static int removeElement(vector<int>& nums, int val) {
        int idx = 0;
        for(const auto& num : nums) {
            if (num != val)
                nums[idx++] = num;
        }
        return idx;
    }
};

int main() {
    vector<int> x{3,2,2,6};
    cout << Solution::removeElement(x, 2) << endl;
}
//
// Created by whx on 24-10-16.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
        const std::vector<int>::size_type size_1 = nums1.size();
        const std::vector<int>::size_type size_2 = nums2.size();

        int i = 0, j = 0;
        int current = 0, prev = 0;

        for (int count = 0; count <= (size_1 + size_2) / 2; count++) {
            prev = current;
            if (i < size_1 && (j >= size_2 || nums1[i] < nums2[j]))
                current = nums1[i++];
            else
                current = nums2[j++];
        }

        if ((size_1 + size_2) % 2 == 0)
            return (prev + current) / 2.0;
        return current;
    }
};

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    cout << Solution::findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
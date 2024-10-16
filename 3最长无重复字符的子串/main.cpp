//
// Created by whx on 24-10-16.
//

#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    static int lengthOfLongestSubstring(const string& str) {
        int left = 0,
            res = 0;

        unordered_set<char> st;
        for (auto right = 0; right < str.length(); right++) {
            while(st.find(str[right]) != st.end()) {
                st.erase(str[left]);
                left++;
            }

            st.insert(str[right]);
            res = max(res, right - left + 1);
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s = "abcabcbb";
    cout << Solution::lengthOfLongestSubstring(s) << endl;

    return 0;
}
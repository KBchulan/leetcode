//
// Created by whx on 24-10-17.
//

#include <string>
#include <iostream>

class Solution {
public:
    static std::string longestPalindrome(const std::string& s) {
        if(s.size() <= 1)
            return s;

        auto expand_from_center = [&](int left, int right) {
            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            return s.substr(left + 1, right - left -1);
        };

        std::string max_str = s.substr(0, 1);
        for (auto i = 0; i < s.size() - 1; i++) {
            std::string odd = expand_from_center(i, i);
            std::string even = expand_from_center(i, i + 1);

            if(odd.size() > max_str.size())
                max_str = odd;
            if(even.size() > max_str.size())
                max_str = even;
        }
        return max_str;
    }

};

int main() {
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    const std::string str = "babad";
    std::cout << Solution::longestPalindrome(str) << std::endl;
    return 0;
}
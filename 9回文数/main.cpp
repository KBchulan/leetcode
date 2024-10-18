//
// Created by whx on 24-10-18.
//

#include <string>
#include <iostream>

class Solution {
public:
    static bool isPalindrome(int x) {
        if(x == 0) return true;
        if(x < 0) return false;

        std::string pre = std::to_string(x);
        const std::string las(pre.rbegin(), pre.rend());
        return pre == las;
    }
};


int main(int argc, char **argv) {
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cout << Solution::isPalindrome(123) << std::endl;
    std::cout << Solution::isPalindrome(-123) << std::endl;
    std::cout << Solution::isPalindrome(121) << std::endl;
    std::cout << Solution::isPalindrome(-121) << std::endl;
    return 0;
}
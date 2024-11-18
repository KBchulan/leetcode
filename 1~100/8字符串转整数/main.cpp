//
// Created by whx on 24-10-18.
//

#include <limits>
#include <string>
#include <iostream>

class Solution {
public:
    static int myAtoi(const std::string& s) {
        int result = 0, sign = 1;
        const size_t begin = s.find_first_not_of(' ');

        if(begin == std::string::npos) {
            return 0;
        }

        size_t index = begin;
        if(s[begin] == '-') {
            sign = -1;
            index++;
        }

        if(s[begin] == '+')
            index++;

        while(index < s.size() && std::isdigit(s[index])) {
            if (result > (std::numeric_limits<int>::max() - (s[index] - '0')) / 10) {
                return sign == 1 ? std::numeric_limits<int>::max() : std::numeric_limits<int>::min();
            }
            result = result * 10 + (s[index] - '0');
            index++;
        }

        return result * sign;
    }
};

int main(int argc, char **argv) {
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cout << Solution::myAtoi("   +9641613") << std::endl;
    return 0;
}
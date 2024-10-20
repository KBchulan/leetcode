//
// Created by whx on 24-10-20.
//

#include <string>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    static int romanToInt(const std::string& s) {
        std::unordered_map<char, int> my_map = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = my_map[static_cast<char>(s[s.size() - 1])];
        for(auto i = 0; i < s.size() - 1; i++) {
            if(my_map[s[i]] < my_map[s[i + 1]])
                result -= my_map[s[i]];
            else result += my_map[s[i]];
        }

        return result;
    }
};

int main(int argc,char **argv) {
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string str = "LVIII";
    std::cout << Solution::romanToInt(str) << std::endl;
}
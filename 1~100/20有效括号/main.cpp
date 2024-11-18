//
// Created by whx on 24-10-23.
//

#include <stack>
#include <string>
#include <iostream>

class Solution {
public:
    static bool isValid(const std::string& s) {
        bool result = true;
        std::stack<char> chars;

        for(const auto& ch : s) {

            if(!chars.empty()) {
                if (ch == ')' && chars.top() == '(')
                    chars.pop();
                else if (ch == ']' && chars.top() == '[')
                    chars.pop();
                else if (ch == '}' && chars.top() == '{')
                    chars.pop();
                else
                    chars.emplace(ch);
            }
            else {
                chars.emplace(ch);
            }
        }

        if(!chars.empty())
            result = false;
        return result;
    }
};
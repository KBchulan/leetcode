//
// Created by whx on 24-10-28.
//

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string> &words)
    {
        unordered_map<string, int> counts;
        for (int i = 0; i < words.size(); i++)
            counts[words[i]]++;

        int length = s.length();
        int wordsize = words.size();
        int len = words[0].size();
        vector<int> ans;
        for (int i = 0; i < len; i++)
        {
            int start = i, count = 0;
            unordered_map<string, int> mp;
            for (int j = i; j <= length - len; j += len)
            {
                string word = s.substr(j, len);
                if (counts.find(word) != counts.end())
                {
                    mp[word]++;
                    count++;

                    while (mp[word] > counts[word])
                    {
                        string leftword = s.substr(start, len);
                        mp[leftword]--;
                        count--;
                        start += len;
                    }
                    if (count == wordsize)
                        ans.push_back(start);
                }
                else
                {
                    mp.clear();
                    count = 0;
                    start = j + len;
                }
            }
        }
        return ans;
    }
};
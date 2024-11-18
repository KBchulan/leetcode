#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static string simplifyPath(string path)
    {
        stringstream strs(path);
        vector<string> words;

        // get words
        string word;
        while (getline(strs, word, '/'))
        {
            if (!word.empty())
                words.push_back(word);
        }

        if (
            (words.size() == 1 && (words.front() == "." || words.front() == ".."))
            || words.empty()
        )
            return "/";

        // 去除 .
        words.erase(std::remove_if(
                        words.begin(), words.end(),
                        [](const string &s)
                        {
                            return s == ".";
                        }),
                    words.end());

        // ..
        vector<string> result_words;
        for (const auto &wor : words)
        {
            if (wor == "..")
            {
                if (!result_words.empty())
                    result_words.pop_back();
                continue;
            }

            result_words.push_back(wor);
        }

        string result = "";
        for (const auto &item : result_words)
        {
            result = result + "/" + item;
        }
        if(result == "")
            return "/";
        return result;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << Solution::simplifyPath("..") << endl;
    return 0;
}
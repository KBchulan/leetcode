#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> result;
        vector<string> currentLine;
        int currentLength = 0;

        for (int i = 0; i < words.size(); i++)
        {
            if (currentLength + currentLine.size() + words[i].length() > maxWidth)
            {
                string line;
                
                if (currentLine.size() == 1)
                {
                    line = currentLine[0];
                    line.append(maxWidth - line.length(), ' ');
                }
                else
                {
                    // 计算空格数
                    int spaces = maxWidth - currentLength;
                    int gaps = currentLine.size() - 1;
                    int spacePerGap = spaces / gaps;
                    int extraSpaces = spaces % gaps;

                    // 构建当前行
                    for (int j = 0; j < currentLine.size(); j++)
                    {
                        line += currentLine[j];
                        if (j < gaps)
                        {
                            int spacesToAdd = spacePerGap + (j < extraSpaces ? 1 : 0);
                            line.append(spacesToAdd, ' ');
                        }
                    }
                }
                result.push_back(line);
                currentLine.clear();
                currentLength = 0;
            }

            currentLine.push_back(words[i]);
            currentLength += words[i].length();
        }

        // 处理最后一行(左对齐)
        if (!currentLine.empty())
        {
            string lastLine = currentLine[0];
            for (int i = 1; i < currentLine.size(); i++)
            {
                lastLine += " " + currentLine[i];
            }
            lastLine.append(maxWidth - lastLine.length(), ' ');
            result.push_back(lastLine);
        }

        return result;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};

    vector<string> result = Solution::fullJustify(words, 16);

    for (const string &line : result)
        cout << line << endl;

    return 0;
}
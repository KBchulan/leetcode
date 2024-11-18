#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    explicit ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode dummy(0, head);
        vector<int> nums;

        while (head != nullptr)
        {
            nums.emplace_back(head->val);
            head = head->next;
        }

        nums.erase(std::remove_if(nums.begin(), nums.end(),
                                  [&](const int &num)
                                  {
                                      int count = std::count(nums.begin(), nums.end(), num);
                                      return count >= 2;
                                  }),
                   nums.end());
        if(nums.size() == 0)
            return nullptr;

        ListNode *flag = dummy.next;
        int idx = 0;
        for (const auto &num : nums)
        {
            flag->val = num;
            idx++;
            if (idx < nums.size())
                flag = flag->next;
            else
                flag->next = nullptr;
        }
        return dummy.next;
    }
};
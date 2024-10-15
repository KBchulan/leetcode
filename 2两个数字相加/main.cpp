//
// Created by whx on 24-10-15.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static ListNode* addTwoNumbers(const ListNode* l1, const ListNode* l2) {
        const auto result = new ListNode(0);
        auto tmp = result;
        int sum = 0;

        while(l1 != nullptr || l2 != nullptr || sum != 0) {
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            if(tmp != nullptr) {
                tmp->next = new ListNode(sum % 10);
                sum = sum / 10;
                tmp = tmp->next;
            }
        }

        const auto res = result->next;
        delete result;
        return res;
    }
};

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
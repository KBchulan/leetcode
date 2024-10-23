//
// Created by whx on 24-10-23.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(const int x) : val(x), next(nullptr) {}
    ListNode(const int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp = head;
        int count = 0;

        if (head == nullptr || head->next == nullptr)
            return nullptr;

        while (tmp) {
            tmp = tmp->next;
            count++;
        }

        if (count == n)
            return head->next;

        int i = 1;
        tmp = head;
        while(i < count - n) {
            tmp = tmp->next;
            i++;
        }

        if(tmp->next)
            tmp->next = tmp->next->next;

        return head;

    }
};

int main(int argc, char **argv) {
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

}
//
// Created by whx on 24-10-25.
//

#include <queue>
#include <vector>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static ListNode* mergeKLists(const std::vector<ListNode*>& lists) {
        auto cmp = [](const ListNode* a, const ListNode* b){return a->val > b->val;};
        std::priority_queue<ListNode*, std::vector<ListNode *>, decltype(cmp)> minHeap(cmp);

        for(const auto& a : lists) {
            if (a)
                minHeap.emplace(a);
        }

        ListNode dummy(0);
        ListNode* curr = &dummy;
        while(!minHeap.empty()) {
            ListNode* node = minHeap.top();
            minHeap.pop();
            curr->next = node;
            curr = curr->next;

            if(node->next) {
                minHeap.emplace(node->next);
            }
        }
        return dummy.next;
    }

};

int main(int argc, char **argv) {
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector<ListNode*> lists;
}
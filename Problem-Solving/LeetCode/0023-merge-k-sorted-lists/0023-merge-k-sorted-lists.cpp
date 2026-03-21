/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int> pq;
        for(auto head : lists) {
            while(head != nullptr) {
                pq.push(-head->val);
                head = head->next;
            }
        }
        ListNode* head = nullptr;
        if (pq.size() > 0) {
            auto v = -pq.top();
            pq.pop();
            head = new ListNode(v);
        }
        auto node = head;
        while(pq.size()) {
            auto v = -pq.top();
            pq.pop();
            node->next = new ListNode(v);
            node = node->next;
        }
        return head;
    }
};
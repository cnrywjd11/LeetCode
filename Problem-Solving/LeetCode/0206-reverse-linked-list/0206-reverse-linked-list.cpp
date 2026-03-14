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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        vector<ListNode*> vt;
        ListNode* node = head;
        while (1) {
            vt.push_back(node);
            if (node->next == NULL) break;
            node = node->next;   
        }
        ListNode* newHead = vt[vt.size()-1];
        for(int i=vt.size()-1;i>=1;i--) {
            vt[i]->next = vt[i-1];
        }
        vt[0]->next = NULL;
        return newHead;
    }
};
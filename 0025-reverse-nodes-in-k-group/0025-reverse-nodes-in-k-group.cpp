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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode*prev = &dummy;
        while (true) {
            ListNode*node = prev;
            for (int i=0; i<k && node; i++) node = node->next;
            if (!node) break;
            ListNode*curr = prev->next;
            ListNode*next = curr->next;
            for (int i=1;i<k;i++) {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            prev = curr;
        }
        return dummy.next;
        
    }
};
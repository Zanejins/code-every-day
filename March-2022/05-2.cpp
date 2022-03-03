// 剑指offer22----倒数第k个结点-----快慢指针问题
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(k--) {
            fast=fast->next;
        }

        while(fast!=nullptr) {
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> visited;
        ListNode* p=headA;
        while(p!=NULL) {
            visited.insert(p);
            p=p->next;
        }
        p=headB;
        while(p!=NULL) {
            if(visited.count(p)) 
                return p;
            p=p->next;
        }
        return NULL;
    }
};

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
    /**
     * 
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here
        // 翻转链表
        ListNode* p=head1;
        ListNode* r=nullptr; //保持
        while(p) {
            ListNode* temp=p->next;
            p->next=r;
            r=p;
            p=temp;
        }
        p=head2;
        ListNode* l=nullptr;
        while(p) {
            ListNode* temp=p->next;
            p->next=l;
            l=p;
            p=temp;
        }
        ListNode* head=new ListNode(0);
        ListNode* tail=head;
        int carry=0;
        while(l || r) {
            int sum=carry;
            if(l!=NULL) {
                sum+=l->val;
                l=l->next;
            }
            if(r!=NULL) {
                sum+=r->val;
                r=r->next;
            }
            carry=sum/10;
            tail->next=new ListNode(sum%10);
            tail=tail->next;
        }
        if(carry>0) {
            tail->next=new ListNode(carry);
        }
        ListNode* res=NULL;
        p=head->next;
        while(p) {
            ListNode* temp=p->next;
            p->next=r;
            r=p;
            p=temp;
        }
        return r;
    }
};

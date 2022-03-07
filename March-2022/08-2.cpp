/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode* phead= new ListNode(0); //创建头结点
        ListNode* p=phead;
        while(pHead1&&pHead2) {
            if(pHead1->val<pHead2->val) {
                p->next=pHead1;
                pHead1=pHead1->next;
            }
            else {
                p->next=pHead2;
                pHead2=pHead2->next;
            }
            p=p->next;
        }
        p->next=pHead1? pHead1:pHead2;
        return phead->next;
    }
};

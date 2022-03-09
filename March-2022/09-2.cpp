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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==NULL || pHead2==NULL) {
            return NULL;
        }
        ListNode* pa=pHead1;
        ListNode* pb=pHead2;
        while(pa!=pb) {
            pa=pa==NULL? pHead2:pa->next;
            pb=pb==NULL? pHead1:pb->next;
        }
        return pa;
        
    }
};

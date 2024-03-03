// T.C : O(n)
// S.C : O(1)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pre_slow, *slow, *fast;
        pre_slow=NULL;
        slow=fast=head;
        
        for(int i=0;i<n;i++)  fast=fast->next;
        
        while(fast!=NULL){
            pre_slow=slow;
            slow=slow->next;
            fast=fast->next;
        }
        
        if(pre_slow==NULL){
            ListNode* new_head = head->next;
            delete head;
            return new_head;
        }
    
        pre_slow->next=slow->next;
        slow->next=NULL;
        delete slow;
        
        return head;
    }
};

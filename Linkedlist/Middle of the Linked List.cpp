// T.C: O(n)
// S.C: O(1)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head,*prev=head;
        while(temp!=NULL && temp->next!=NULL){
            temp=temp->next->next;
            prev=prev->next;
        }
        if(temp==NULL || temp->next==NULL){
                return prev;
        }
        return head;
    }
};

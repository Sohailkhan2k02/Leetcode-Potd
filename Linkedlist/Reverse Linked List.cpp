//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp,*prev=NULL;
        while(head!=NULL){
            temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        return prev;
    }
};

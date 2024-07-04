//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        vector<int>t;
        ListNode* temp=head;
        temp=temp->next;
        int sum=0;
        while(temp!=NULL && temp->val!=0){
            sum+=temp->val;
            temp=temp->next;
            if(temp->val==0){
                t.push_back(sum);
                sum=0;
                temp=temp->next;
            }
        }
        
        if(t.empty()) return NULL; // DIDNT THOUGHT OF THIS AH SHIT I AM STILL BAD AT DEDUCING EDGE CASES
        ListNode* res = new ListNode(t[0]);
        ListNode* curr = res;
        for (int i = 1; i < t.size(); ++i) {
            curr->next = new ListNode(t[i]);
            curr = curr->next;
        }
        return res;
    }
};

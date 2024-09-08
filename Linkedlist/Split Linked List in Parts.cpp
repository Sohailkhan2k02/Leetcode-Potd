//T.C : O(L+k) - You are traversing the input linkedlist only once and the array of size k only once
//S.C : O(1) (Not including result vector)
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        int L = 0;
        while(curr) {
            L++;
            curr = curr->next;
        }
        
        int eachBucketNodes = L/k; //0
        int remainderNodes  = L%k; //3
        
        vector<ListNode*> result(k, NULL);
        curr           = head;
        ListNode* prev = NULL;
        
        for(int i = 0; curr && i < k ; i++) {
            
            result[i] = curr;
            
            for(int count = 1; count <= eachBucketNodes + (remainderNodes > 0 ? 1 : 0); count++) {
                prev = curr;
                curr = curr->next;
            }
            
            prev->next = NULL;
            remainderNodes--;
        }
        
        return result;
    }
};

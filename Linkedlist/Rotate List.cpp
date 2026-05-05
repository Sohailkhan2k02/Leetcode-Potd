/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    int count_size(ListNode* head){
        if(head == NULL){
            return 0;
        }
        return 1 + count_size(head->next);
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL){
            return head;
        }
        int n = count_size(head);
        vector<ListNode*> arr(n);
        k = k%n;
        if(k == 0){
            return head;
        }
        ListNode* temp = head;
        int i = 0;
        while(temp != NULL){
            arr[(i+k)%n] = temp;
            temp = temp->next;
            i++;
        }
        for(int i=0;i<n-1;i++){
            arr[i]->next = arr[i+1];
        }
        arr[n-1]->next = NULL;
        return arr[0];
    }
};

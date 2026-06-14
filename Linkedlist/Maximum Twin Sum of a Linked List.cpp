/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverse(struct ListNode *head){
    struct ListNode *prev = NULL;
    while(head){
        struct ListNode *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
int pairSum(struct ListNode* head) {
    //get to mid and cut it off
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while(fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    //reverse the second half
    struct ListNode *half_head = reverse(slow->next);
    //add both halves and keep track of the maximum
    int res = 0;
    while(half_head){
        int curr = head->val + half_head->val;
        if(curr > res)
            res = curr;
        head = head->next;
        half_head = half_head->next;
    }
    return res;
}

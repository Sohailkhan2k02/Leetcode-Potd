class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        for (ListNode* curr = head; curr; curr = curr->next) {
            ans = (ans << 1) + curr->val;
        }
        return ans;
    }
};

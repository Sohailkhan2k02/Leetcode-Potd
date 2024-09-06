//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    ListNode* delathead(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* t = head;
        head = head->next;
        delete t;
        return head;
    }

    ListNode* delatpos(ListNode* head, ListNode* prev, ListNode* curr) {
        if (curr == NULL) return head;
        prev->next = curr->next;
        delete curr;
        return head;
    }

    ListNode* delattail(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* temp = head, *prev = NULL;
        if (head->next == NULL) {
            delete head;
            return NULL;
        }
        while (temp->next) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        delete temp;
        return head;
    }

    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st(nums.begin(), nums.end());
        if (head == NULL) return head;
        
        while (head != NULL && st.find(head->val) != st.end()) {
            head = delathead(head);
        }

        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp != NULL) {
            if (st.find(temp->val) != st.end()) {
                if (temp->next == NULL) {
                    head = delattail(head);
                    break;
                } else {
                    head = delatpos(head, prev, temp);
                    temp = prev->next;
                }
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};

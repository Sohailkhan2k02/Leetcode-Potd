//T.C : O(n) GCD TAKES O(log(min(a,b)))
//S.C : O(n)
class Solution {
public:
    int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp=head;
        while(temp && temp->next){
            int a=temp->val;
            int b=temp->next->val;
            ListNode* res=new ListNode(gcd(a,b));
            res->next=temp->next;
            temp->next=res;
            temp=res->next;
        }
        return head;
    }
};

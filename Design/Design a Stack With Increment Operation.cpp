//T.C : O(min(size,k)
//S.C : O(n)
class Node{
    public:
    Node* next;
    Node* prev;
    int val;
    Node(int val){
        next=NULL;
        prev=NULL;
        this->val=val;
    }
};
class CustomStack {
public:
    Node* head;
    Node* tail;
    int size;
    int capacity;
    CustomStack(int maxSize) {
        head=NULL;
        tail=NULL;
        size=0;
        capacity=maxSize;
    }
    
    void push(int x) {
        if(size==capacity){
            return;
        }

        Node* temp=new Node(x);
        if(size==0){
            head=temp;
            tail=temp;
        }
        else{
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
        size++;
    }
    
    int pop() {
        if(size==0){
            return -1;
        }

        Node* temp=head;
        int value=head->val;
        if(size==1){
            head=NULL;
            tail=NULL;
        }
        else{
            head=head->next;
            head->prev=NULL;
        }
        delete(temp);
        size--;
        return value;
    }
    
    void increment(int k, int val) {
        if(size<=k){
            Node* temp=head;
            while(temp!=NULL){
                temp->val+=val;
                temp=temp->next;
            }
        }
        else{
            int cnt=0;
            Node* temp=tail;
            while(cnt<k){
                temp->val+=val;
                temp=temp->prev;
                cnt++;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

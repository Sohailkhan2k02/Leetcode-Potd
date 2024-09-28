//T.C : O(1)
//S.C : O(k)
class Node{
    public:
    int val;
    Node* next;
    Node* prev;

    Node(int val){
        this->val=val;
        next=NULL;
        prev=NULL;
    }
};
class MyCircularDeque {
public:
    Node* head;
    Node* tail;
    int size;
    int capacity;
    MyCircularDeque(int k) {
        head=NULL;
        tail=NULL;
        size=0;
        capacity=k;
    }
    
    bool insertFront(int value) {
        if(size==capacity){
            return false;
        }

        Node* temp=new Node(value);
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
        return true;
    }
    
    bool insertLast(int value) {
        if(size==capacity){
            return false;
        }

        Node* temp=new Node(value);
        if(size==0){
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(size==0){
            return false;
        }

        Node* temp=head;
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
        return true;
    }
    
    bool deleteLast() {
        if(size==0){
            return false;
        }

        Node* temp=tail;
        if(size==1){
            head=NULL;
            tail=NULL;
        }
        else{
            tail=tail->prev;
            tail->next=NULL;
        }
        delete(temp);
        size--;
        return true;
    }
    
    int getFront() {
        if(size==0) return -1;
        return head->val;
    }
    
    int getRear() {
        if(size==0) return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

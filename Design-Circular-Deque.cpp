class MyCircularDeque {
      struct node {
            int val ;
            struct node * next;
            struct node * prev;
            node(int val){
                this->val =val;
                next=nullptr;
                prev=nullptr;
            }
        };
        node *head,*tail;
        int maxSize;
        int listSize;
public:
    MyCircularDeque(int k) {
      maxSize = k;
        listSize = 0;
        head = tail = NULL;

    }
    
    bool insertFront(int value) {
        if(listSize == maxSize) //Overflow
            return false;
    
        node *newnode = new node(value);
        if(!head){
            head = tail = newnode;
            head->next = head;  //Make it circular
            tail->prev = head;
        }else{
            newnode->next = head;
            head->prev = newnode;
            tail->next = newnode;
            newnode->prev = tail;
            head = newnode;
        }
        listSize++;
        return true;
    }
    
    bool insertLast(int value) {
        if(listSize == maxSize)//Overflow
            return false;

        node *newnode = new node(value);
        if(!head){
            head = tail = newnode;
            head->next = head;  //Make it circular
            tail->prev = head;
        }else{
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next = head;
            tail = newnode;
            head->prev = tail;
        }
        listSize++;
        return true;
    }
    
    bool deleteFront() {
         if(listSize==0)
            return false;
        
        if(listSize==1){
            delete head;    //Avoiding memory leak
            head = tail = NULL;
        } else {
            node *curr = head;
            head = head->next;
            curr->next = curr->prev = NULL;
            head->prev = tail;
            tail->next = head;
            delete curr;    //Avoiding memory leak
        }
        listSize--;
        return true;
    }
    
    bool deleteLast() {
        if(listSize==0)
            return false;
        
        if(listSize==1){
            delete head;    //Avoiding memory leak
            head = tail = NULL;
        } else {
            node* curr = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            curr->prev = curr->next = NULL;
            delete curr;    //Avoiding memory leak
        }
        listSize--;
        return true;
    }
    
    int getFront() {
        if(listSize==0)
            return -1;
        return head->val;
    }
    
    int getRear() {
        if(listSize==0)
            return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return listSize==0;
    }
    
    bool isFull() {
        return listSize==maxSize;
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